package main

import (
	"fmt"
	"time"
)

type ReqI interface {
	Handler(url string) string
}

type Req struct {
}

func (r Req) Handler(url string) string {
	fmt.Println("请求 " + url)
	time.Sleep(100 * time.Millisecond)
	return ""
}

// LogReqDecorator 日志装饰器
type LogReqDecorator struct {
	req ReqI
}

func (l LogReqDecorator) Handler(url string) string {
	fmt.Println("日志记录前")
	res := l.req.Handler(url)
	fmt.Println("日志记录后")
	return res
}

type MonitorDecorator struct {
	req ReqI
}

func (l MonitorDecorator) Handler(url string) string {
	t1 := time.Now()
	res := l.req.Handler(url)
	sub := time.Since(t1)
	fmt.Println("耗时", sub)
	return res
}
func main() {
	req := Req{}
	req1 := LogReqDecorator{req: req}
	req2 := MonitorDecorator{req: req1}
	req2.Handler("baidu.com")
}
