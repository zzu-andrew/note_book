package main

import "fmt"

type AliPay struct {
}

func (a AliPay) GetPayPage(price int64) string {
	return "支付宝支付链接"
}

type AliPayAdapter struct {
	aliPay *AliPay
}

func (w AliPayAdapter) PayPage(price int64) string {
	return w.aliPay.GetPayPage(price)
}

type WeiXinPay struct {
}

func (w WeiXinPay) PayPage(price int64) string {
	return "微信支付链接"
}

type PayI interface {
	PayPage(price int64) string
}

func PayPage(pi PayI, price int64) string {
	return pi.PayPage(price)
}

func main() {
	fmt.Println(PayPage(WeiXinPay{}, 1))
	fmt.Println(PayPage(AliPayAdapter{aliPay: &AliPay{}}, 1))
}
