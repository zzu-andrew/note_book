package main

import "fmt"

type Prototype interface {
	Clone() Prototype
}

type Student struct {
	Name string
	Age  int
}

func (s *Student) Clone() Prototype {
	return &Student{
		Name: s.Name,
		Age:  s.Age,
	}
}

func main() {
	s1 := Student{
		Name: "fengfeng",
		Age:  21,
	}
	s2 := s1.Clone().(*Student)
	s2.Name = "zhangsan"
	s2.Age = 25
	fmt.Println(s1)
	fmt.Println(s2)

}
