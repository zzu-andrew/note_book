package main

import "fmt"

type Command interface {
	Execute()
}

type PrintCommand struct {
	Content string
}

func (p PrintCommand) Execute() {
	fmt.Println("打印消息", p.Content)
}

type SendEmail struct {
	To      string
	Content string
}

func (s SendEmail) Execute() {
	fmt.Println("发送邮件", s.To, s.Content)
}

type SendTel struct {
	To      string
	Content string
}

func (s SendTel) Execute() {
	fmt.Println("发送短信", s.To, s.Content)
}

type TaskQueue struct {
	Queue []Command
}

func NewTaskQueue() *TaskQueue {
	return &TaskQueue{}
}

func (t *TaskQueue) AddCommand(command Command) {
	t.Queue = append(t.Queue, command)
}

func (t *TaskQueue) Command() {
	for _, command := range t.Queue {
		command.Execute()
	}
}

func main() {
	queue := NewTaskQueue()
	queue.AddCommand(&PrintCommand{
		Content: "你好",
	})
	queue.AddCommand(&SendEmail{
		Content: "你好",
		To:      "xxx@qq.com",
	})
	queue.AddCommand(&SendTel{
		Content: "你好",
		To:      "11122223333",
	})
	queue.Command()
}
