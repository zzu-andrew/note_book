package main

import "fmt"

type State interface {
	Switch(context *Context)
}

type Context struct {
	state State
}

func (c *Context) SetState(state State) {
	c.state = state
}
func (c *Context) Switch() {
	c.state.Switch(c)
}

type OnState struct {
}

func (OnState) Switch(context *Context) {
	fmt.Println("开关关闭")
	context.SetState(&OffState{})
}

type OffState struct {
}

func (OffState) Switch(context *Context) {
	fmt.Println("开关打开")
	context.SetState(&OnState{})
}

func main() {
	c := &Context{
		state: OffState{},
	}
	c.Switch()
	c.Switch()
	c.Switch()
}
