//
// Created by wangyz38535 on 2023/7/7.
//

#ifndef NODE_BOOKS_LOG_STREAM_H
#define NODE_BOOKS_LOG_STREAM_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <mutex>

enum class LogLevel {
    DEBUG, INFO, WARNING, ERROR
};

class Logger {
public:
    Logger() : level(LogLevel::DEBUG), output(std::cout.rdbuf()) {}

    // 设置日志级别
    void set_level(LogLevel level) {
        this->level = level;
    }

    // 设置日志输出目标
    void set_output(std::ostream& output) {
        this->output.rdbuf(output.rdbuf());
    }

    // 记录日志
    template<typename... Args>
    void log(LogLevel level, Args... args) {
        if (level < this->level) {
            return;
        }
        std::stringstream message;
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        message << std::put_time(std::localtime(&now_c), "%F %T") << " ";
        switch (level) {
            case LogLevel::DEBUG:
                message << "DEBUG";
                break;
            case LogLevel::INFO:
                message << "INFO";
                break;
            case LogLevel::WARNING:
                message << "WARNING";
                break;
            case LogLevel::ERROR:
                message << "ERROR";
                break;
        }
        message << " ";
        log_message(message, args...);
    }

private:
    LogLevel level;
    std::ostream output;
    std::mutex mutex;

    // 递归地写入日志内容
    template<typename T, typename... Args>
    void log_message(std::stringstream& message, T value, Args... args) {
        message << value << " ";
        log_message(message, args...);
    }

    // 写入日志内容的终止条件
    void log_message(std::stringstream& message) {}

};

// 全局日志对象
Logger logger;

//int main() {
//    logger.set_level(LogLevel::INFO);
//    std::ofstream file("log.txt");
//    logger.set_output(file);
//
//    logger.log(LogLevel::DEBUG, "debug message"); // 不输出
//    logger.log(LogLevel::INFO, "info message");
//    logger.log(LogLevel::WARNING, "warning message");
//    logger.log(LogLevel::ERROR, "error message");
//
//    return 0;
//}

#endif //NODE_BOOKS_LOG_STREAM_H
