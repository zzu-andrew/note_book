## `MySQL`



### 关系数据库

常见的存储引擎：

`MyISAM`:

- 查询快
- 只支持表锁
- 不支持实务

`InnoDB`:

- 整体速度快
- 支持表锁
- 支持事务

**事务**：事务就是把多个`SQL`操作当成一个整体，在日常生活中会经常碰到，比如张三向李四转账1万元，需要执行张三减少1万元的`SQL`语句，也需要执行李四增加1万元的`SQL`语句。事务就可以将这两条语句捆绑成一个整体，保证两条语句能同时执行成功

**索引**

索引的原理：B树和B+树

索引的类型

索引的命中

分库分表

`SQL`慢查询优化

`MySQL`主从

`MySQL`读写分离





### 打开数据库







```go
package main

import (
	"database/sql"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"log"
)

// go连接MySQL数据库
func main() {

	//连接数据库
	dsn := "root:Wang.159@tcp(127.0.0.1:3306)/testdb"
	db, err := sql.Open("mysql", dsn) // open不会校验用户名和密码是否正确，只是检验了数据的格式
	if err != nil {
		log.Fatal(err)
	}
	// ping的时候才会校验用户名改密码的准确性
	err = db.Ping()
	if err != nil {
		fmt.Println("db ping err~")
		return
	}
	// 链接数据库成功

}
```









### 数据库数据查询







```go
package main

import (
	"database/sql"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"log"
)

// 是一个链接池操作
var db *sql.DB

type user struct {
	id   int
	name string
	age  int
}

func initDB() (err error) {

	//连接数据库
	dsn := "root:Wang.159@tcp(127.0.0.1:3306)/testdb"
	// 注意这里不要使用 := 因为要保证使用的db是全局变量
	db, err = sql.Open("mysql", dsn) // open不会校验用户名和密码是否正确，只是检验了数据的格式
	if err != nil {
		log.Fatal(err)
		return err
	}
	// ping的时候才会校验用户名改密码的准确性
	err = db.Ping()
	if err != nil {
		fmt.Println("db ping err~")
		return err
	}
	// 链接数据库成功
	return nil
}

// go连接MySQL数据库
func main() {

	//连接数据库
	err := initDB()
	if err != nil {
		fmt.Println("init db failed, err=", err)
	}
	fmt.Println("链接数据库成功!")

	// 写查询单条记录的sql语句
    // 执行没有占位符的情况，有占位符需要在QueryRow传入对应的参数
	sqlStr := `select id,name,age from user where id=1;`
	// 执行
	 rowObj := db.QueryRow(sqlStr)
	 // 拿到结果
	 var u1 user
	 err = rowObj.Scan(&u1.id, &u1.name, &u1.age)
	 if err != nil {
	 	fmt.Println("row data failed.")
	 }

	 fmt.Println(u1)
}
```













### `MySQL`预处理

**什么是预处理？**

**普通的`SQL`语句执行过程**

1. 客户端对`SQL`语句进行占位符替换得到完整的`SQL`语句
2. 客户端发送完整`SQL`语句到`MySQL`客户端
3. `MySQL`服务端执行完整的`SQL`语句并将结果返回给客户端

**预处理执行过程**

1. 把`SQL`语句分成两部分，命令部分与数据部分
2. 先把命令部分发送给`MySQL`服务端，`MySQL`服务端进行`SQL`预处理
3. 然后把数据部分发送给`MySQL`服务端，`MySQL`服务端对`SQL`语句进行占位符替换
4. `MySQL`服务端执行完整的`SQL`语句并将结果返回给客户端

**为什么要预处理**

1. 优化`MySQL`服务器重复执行`SQL`的方法，可以提升服务器性能，提前让服务器编译，一次编译多次执行，节省后续编译的成本
2. 避免`SQL`注入的问题



### `MySQL`事务

事务：一个最小的不可再分的工作单元；通常一个事务对应一个完整的业务(例如银行账户转账业务，该业务就是一个最小的工作单元)，同时这个完整的业务需要多次执行的`DML`(insert update delete)语句共同联合完成。

在`MySQL`中只有使用了`Innodb`数据库引擎的数据库或表才支持事务，事务处理可以用来维护数据库的完整性，保证成批的`SQL`语句要么全部执行，要么全部不执行。

事务的`ACID`

通常事务必须满足4个条件(`ACID`):原子性(`Atomicity`，或称不可分割性)



















