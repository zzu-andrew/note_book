## Go Embed简明教程

go语言程序都是编译成二进制可执行文件的，但是实际执行时除了需要可执行程序，还需要一些静态文件，比如html模板等，于是就有人想如果Go官方能内建支持就好了。2019末一个提案被提出 [issue#35950](https://links.jianshu.com/go?to=https://github.com/golang/go/issues/35950),期望Go官方编译器支持嵌入静态文件。后来Russ Cox专门写了一个设计文档 [Go command support for embedded static assets](https://links.jianshu.com/go?to=https://go.googlesource.com/proposal/+/master/design/draft-embed.md), 并最终实现了它。

- 需要注意的这个功能在go 1.16beta之后才支持
- 对于单个的文件，支持嵌入为字符串和 byte slice
- 对于多个文件和文件夹，支持嵌入为新的文件系统FS
- 比如导入 "embed"包，即使无显式的使用

  `go:embed`指令用来嵌入，必须紧跟着嵌入后的变量名

- 只支持嵌入为string, byte slice和embed.FS三种类型，这三种类型的别名(alias)和命名类型(如type S string)都不可以

### 嵌入为字符串

假设有一个文件test.txt文件内容为hello world

如下代码编译之后s的值就变成了"hello world"

```go
//go:embed test.txt
var s string
```

### 嵌入为byte slice

你还可以将文件的内容嵌入为slice of byte，也就是一个字节数组

```go
//go:embed test.txt
var b []byte
```

### 嵌入为fs.FS

甚至你可以嵌入为一个文件系统，这种方式在嵌入多个文件的时候非常有用

支持嵌入多个文件如：

```go
//go:embed test.txt hello.txt       
```

支持指定文件夹如：

```go
//go:embed file/file.txt
```

支持多行方式嵌入如：

```go
//go:embed test.txt hello.txt       
//go:embed file/file.txt
//go:embed test.txt hello.txt       
//go:embed file/file.txt
var f embed.FS

// 使用
// 嵌入为文件系统
data, _ :=  f.ReadFile("test.txt")
fmt.Println(string(data))
data, _ = f.ReadFile("hello.txt")
fmt.Println(string(data))
```

支持嵌入文件夹

```
//go:embed file
var d embed.FS
```

完整代码实现

```go
package main

import (
   "embed"
   _ "embed"
   "fmt"
)

//go:embed test.txt
var s string

//go:embed test.txt
var b []byte

//go:embed test.txt hello.txt
//go:embed file/file.txt
var f embed.FS

//go:embed file
var d embed.FS

//go:embed file/*.txt
var pre embed.FS


func main() {
   // 直接嵌入
   fmt.Println(s)
   fmt.Println(b)

   // 嵌入为文件系统
   data, _ :=  f.ReadFile("test.txt")
   fmt.Println(string(data))
   data, _ = f.ReadFile("hello.txt")
   fmt.Println(string(data))
   // 嵌入的时候文件是啥，这里要对应指定为相同的文件路径
   data, _ = f.ReadFile("file/file.txt")
   fmt.Println(string(data))

   data, _ = d.ReadFile("file/file.txt")
   fmt.Println(string(data))

   data, _ = pre.ReadFile("file/name.txt")
   fmt.Println(string(data))
}
```