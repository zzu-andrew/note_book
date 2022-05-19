















### `kafka`集群的架构

1. `broker`
2. topic
3. partition：分区，把同一个`topic`分成不同的分区，提高负载
   1. leader 分区的主节点
   2. follower 分区的从节点(小弟)
4. Consumer Group

### 生产者往`kafka`发送数据流的流程(6步)

![image-20210313222030658](image/image-20210313222030658.png)

### `kafka`选择分区模式(3种)

1. 指定往哪个分区写
2. 指定`Key`，`kafka`根据`key`做`hash`然后决定写哪个分区
3. 轮询方式

### 生产者往`kafka`发送数据的模式(3)种

1. 0把数据发送给`Leader`就成功，效率最高，安全性最低
2. 1把数据发送给`Leader`，等待`leader`回`ACK`
3. `all`把数据发送给`leader`确保`follower`拉取数据回复`ack`给`Leader`，`Leader`再回复`ACK`；安全性最高









### `kafka`的启动和创建`topic`



[kafka启动和创建topic](https://www.cnblogs.com/cq-yangzhou/p/11425047.html)



[kafka](https://www.cnblogs.com/qingyunzong/p/9004509.html)