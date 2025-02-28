package main

import "fmt"

type Obj interface {
	SendMsg(string)
	RevMsg(string)
}
type Mediator interface {
	SendMsg(msg string, user Obj)
}

type User struct {
	Name     string
	mediator Mediator
}

func (u User) SendMsg(msg string) {
	fmt.Printf("用户 %s 发了消息 %s\n", u.Name, msg)
	u.mediator.SendMsg(msg, u)
}
func (u User) RevMsg(msg string) {
	fmt.Printf("用户 %s 接收到消息 %s\n", u.Name, msg)
}

type ChatRoom struct {
	users []User
}

func (c *ChatRoom) Register(user User) {
	c.users = append(c.users, user)
}
func (c *ChatRoom) SendMsg(msg string, user Obj) {
	for _, u := range c.users {
		if u == user {
			continue
		}
		u.RevMsg(msg)
	}
}

func main() {
	room := ChatRoom{}
	u1 := User{Name: "枫枫", mediator: &room}
	u2 := User{Name: "张三", mediator: &room}
	u3 := User{Name: "李四", mediator: &room}

	room.Register(u1)
	room.Register(u2)
	room.Register(u3)

	u1.SendMsg("你好啊")
	u2.SendMsg("吃了吗")
	u3.SendMsg("我吃了")
}
