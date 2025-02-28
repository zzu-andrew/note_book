package main

import "fmt"

type Book struct {
	Title string
}

type BookIterator struct {
	Books    []*Book
	position int
}

func NewBookIterator(book []*Book) *BookIterator {
	return &BookIterator{
		Books:    book,
		position: 0,
	}
}

type Iterator interface {
	HasNext() bool
	Next() *Book
}

func (b *BookIterator) HasNext() bool {
	if b.position >= len(b.Books) {
		return false
	}
	return true
}
func (b *BookIterator) Next() *Book {
	if !b.HasNext() {
		return nil
	}
	book := b.Books[b.position]
	b.position++
	return book
}

func IteratorFunc(iterator Iterator) {
	for iterator.HasNext() {
		book := iterator.Next()
		fmt.Println(book.Title)
	}
}

func main() {
	book := []*Book{
		{Title: "Go开发"},
		{Title: "前端开发"},
		{Title: "XX开发"},
	}

	bookIterator := NewBookIterator(book)
	IteratorFunc(bookIterator)

}
