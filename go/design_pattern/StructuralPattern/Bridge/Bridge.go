package main

import "fmt"

// Printer 打印机
type Printer interface {
	PrintFile(file string) // 打印文件
}

type Epson struct {
}

func (Epson) PrintFile(file string) {
	fmt.Println("使用爱普生打印机打印文件")
}

type Hp struct {
}

func (Hp) PrintFile(file string) {
	fmt.Println("使用惠普打印机打印文件")
}

// Computer 电脑
type Computer interface {
	Print(string)       // 打印
	SetPrinter(Printer) // 设置打印机
}

type Mac struct {
	printer Printer
}

func (m *Mac) Print(file string) {
	// 电脑调打印机的打印方法
	fmt.Println("使用mac电脑")
	m.printer.PrintFile(file)
}

func (m *Mac) SetPrinter(printer Printer) {
	m.printer = printer
}

type Windows struct {
	printer Printer
}

func (m *Windows) Print(file string) {
	// 电脑调打印机的打印方法
	fmt.Println("使用windows电脑")
	m.printer.PrintFile(file)
}

func (m *Windows) SetPrinter(printer Printer) {
	m.printer = printer
}

func main() {
	w := Windows{}
	//hp := Hp{}
	ep := Epson{}

	w.SetPrinter(ep)
	w.Print("xx")
}
