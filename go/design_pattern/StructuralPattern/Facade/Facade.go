package main

import "fmt"

type Inventory struct {
}

func (k Inventory) Deduction() {
	fmt.Println("扣库存")
}

type Pay struct {
}

func (k Pay) Pay() {
	fmt.Println("支付")
}

type Logistics struct {
}

func (k Logistics) SendOutGoods() {
	fmt.Println("发货")
}

type Order struct {
	inventory *Inventory
	pay       *Pay
	logistics *Logistics
}

func NewOrder() *Order {
	return &Order{
		inventory: &Inventory{},
		pay:       &Pay{},
		logistics: &Logistics{},
	}
}

func (o Order) Place() {
	o.inventory.Deduction()
	o.pay.Pay()
	o.logistics.SendOutGoods()
}

func main() {
	o := NewOrder()
	o.Place()
}
