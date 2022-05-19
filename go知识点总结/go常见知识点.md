## go语言常见知识点



 ### 1. make和new的区别

内置函数new计算类型的大小，并为其分配零值内存，返回指针

make会被编译器翻译成具体的创建函数，由其分配内存和初始化成员结构，返回对象的引用而非指针

**new**:

- new的作用是初始化一个类型的指针
- new函数是内建函数
- 使用new来进行分配空间
- 传递给new函数的是一个类型，而不是一个值
- 返回值指向这个新分配的地址的指针

```go
package main

import "fmt"

func main() {
	p := new(Table)
	person := Table{"LittleTable"}
	fmt.Printf("%T\n",p)
	fmt.Printf("%T\n",person)

}
type Table struct {
	name string
}

// 输出结果为
// *main.Table
// main.Table

// 所以new函数返回的是指针，该指针指向Table实体

```

**make**:

- make的作用是为slice、map或chan的初始化
- make返回类型的引用而不是指针，而返回值类型依赖具体传入类型
- make函数是内健函数，函数定义：

```go
// The make built-in function allocates and initializes an object of type
// slice, map, or chan (only). Like new, the first argument is a type, not a
// value. Unlike new, make's return type is the same as the type of its
// argument, not a pointer to it. The specification of the result depends on
// the type:
//	Slice: The size specifies the length. The capacity of the slice is
//	equal to its length. A second integer argument may be provided to
//	specify a different capacity; it must be no smaller than the
//	length. For example, make([]int, 0, 10) allocates an underlying array
//	of size 10 and returns a slice of length 0 and capacity 10 that is
//	backed by this underlying array.
//	Map: An empty map is allocated with enough space to hold the
//	specified number of elements. The size may be omitted, in which case
//	a small starting size is allocated.
//	Channel: The channel's buffer is initialized with the specified
//	buffer capacity. If zero, or the size is omitted, the channel is
//	unbuffered.
func make(t Type, size ...IntegerType) Type
```





