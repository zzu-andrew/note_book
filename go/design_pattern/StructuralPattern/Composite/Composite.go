package main

import "fmt"

type Node interface {
	Display(ident string)
}

type File struct {
	Name string
}

func (n File) Display(ident string) {
	fmt.Println(ident + n.Name)
}

type Dir struct {
	Name     string
	children []Node
}

func (n Dir) Display(ident string) {
	fmt.Println(ident + n.Name)
	for _, child := range n.children {
		child.Display(ident + "  ")
	}
}

func main() {
	root := Dir{
		Name: "CreationalPatterns",
		children: []Node{
			Dir{
				Name: "AbstractFactory",
				children: []Node{
					File{
						Name: "AbstractFactory.go",
					},
				},
			},
			File{
				Name: "main.go",
			},
		},
	}
	root.Display("")
}
