

# `ETCD`
## 特点
- 完全复制：集群中的每个节点都可以使用完整的存档
- 高可用性： `Etcd`可用于避免硬件的单点故障或网络问题
- 一致性：每次读取都会返回跨多主机的最新写入
- 简单：包括一个定义良好，面相用户的`API`(`gRPC`)
- 安全：实现了带有可选的客户端证书身份验证的自动化`TLS`
- 快速：每秒10000次写入的基准速度
- 可靠：使用`Raft`算法实现了强一致，高可用的服务存储目录



![image-20210707233220088](image/image-20210707233220088.png)

> - HTTP server 用于处理用户发送的`API`请求
> - Store 用于处理`etcd`支持的各类功能的事务，包括数据索引、节点状态变更、监控与反馈、事件处理与执行等等
> - Raft 强一致算法的具体实现，是`etcd`核心
> - `WAL` Write ahead log 预写式日志，是`etcd`数据存储的形式，除了内存中存储的所有的数据的状态以及节点的索引以外，`etcd`就通过`WAL`进行持久化存储，`WAL`中所有的数据提交前都会事先记录日志，`snapshot`是为了防止数据过多而进行的状态快照，`Entry`表示存储的具体日志的内容。 



## 应用场景

### 服务发现

服务发现是分布式系统中最常见的问题之一。即同一个分布式集群中的进程或者服务，要如何才能找到对方并建立连接。本质上来说，服务 发现就是想要了解集群中是否有进程在监听`UDP`或`TCP`端口，并且通过名字就能查找和连接。

### 配置中心

将一些配置信息放置到`etcd`上进行集中管理。

这类场景的使用通常是，应用在启动的时候主动从`etcd`获取一次配置配置信息，同时，在`etcd`节点上注册一个`watcher`并等待，以后每次配置有更新的时候，`etcd`都会实时通知订阅者，以此达到获取最新配置信息的目的。

### 分布式锁

因为`etcd`使用`raft`算法保持了数据的强一致性，某次操作存储到集群中的值必然是全局一致的，所以很容易实现分布式锁。锁服务具有两种使用方式，一是保持独占，二是控制时序。

- 保持独占：所有获取锁的用户最终只有一个可以得到
- 控制时序：所有想要得到锁的用户都会被执行，但是获得锁的顺序也是全局唯一的，同时决定了执行顺序。

### `etcd`集群

`etcd`作为一个高可用键值存储系统，天生就是为了集群化而设计的，由于`Raft`算法在做决策时需要多数节点的投票，所以`etcd`一般部署集群个数推荐奇数个节点。



### `etcd`安装



#### 运行

1. 下载对应版本，直接双击进行运行就可以了。

2. `etcdctl  --endpoints=http://127.0.0.1:2379 put nazha "dsb"`  使用`etcdctl`进行连接和设置`kv`值

```bash
andrew$ ./etcdctl --endpoints=http://127.0.0.1:2379 put baodelu "dsb"
OK
```



#### 使用`go`语言代码连接服务器

```go
package main

import (
	"context"
	"fmt"
	"time"

	"go.etcd.io/etcd/clientv3"
)

var (
	dialTimeout    = 5 * time.Second
	requestTimeout = 4 * time.Second
	// 节点，可以传递多个节点的链接
	endpoints      = []string{"127.0.0.1:2379"}
)

func main() {

	cfg := clientv3.Config{
		Endpoints:   endpoints,
		DialTimeout: dialTimeout,
	}

	cli, err := clientv3.New(cfg)

	if err != nil {
		// handle error
		fmt.Printf("connect to etcd failed, err:%v\n", err)
		return
	}

	fmt.Println("connect to etcd success")

	defer cli.Close()

	// put
	ctx, cancel := context.WithTimeout(context.Background(), requestTimeout)
	_, err = cli.Put(ctx, "标", "hello")
	cancel()
	if err != nil {
		fmt.Printf("put to etcd failed, err:%v\n", err)
		return
	}

	// get
	ctx, cancel = context.WithTimeout(context.Background(), requestTimeout)
	resp, err := cli.Get(ctx, "标", clientv3.WithPrefix())
	cancel()

	if err != nil {
		fmt.Printf("get from etcd failed, err:%v\n", err)
		return
	}

	for _, kv := range resp.Kvs {
		fmt.Printf("%s:%s\n", kv.Key, kv.Value)
	}
}
```













 

















