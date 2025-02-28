package main

import "fmt"

type Log struct {
}

func (Log) Info(content string) {
	fmt.Println("日志落库")
}

type ProxyLog struct {
	log *Log
}

func (p *ProxyLog) Info(content string) {
	// 延迟初始化
	if p.log == nil {
		p.log = &Log{}
	}
	// 访问前
	p.log.Info(content)
	// 访问后
	fmt.Println("记录 调用了 info")
}

func main() {

	log := ProxyLog{}

	log.Info("zxxx")
}
