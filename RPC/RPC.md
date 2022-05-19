## RPC









### gRPC

- 需要创建文件，文件名后缀为.proto，除了结构定义外的语句一分号结尾
- 结构定义可以包含：message、service、enum
- rpc方法定义结尾的分号可有可无
- Message命名采用驼峰命名方式，字段命名采用小写加下划线分隔符方式

```protobuf
message SongServerRequest {
	require string song_name = 1
}
```

- enums类型采用驼峰命名方式，字段命名采用大写字母加下划线分割方式

```protobuf
enum Foo {
	FIRST_VALUE = 1;
	SECOND_VALUE = 2;
}
```



















