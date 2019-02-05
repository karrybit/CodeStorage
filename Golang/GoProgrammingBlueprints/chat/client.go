package main

import (
	"github.com/gorilla/websocket"
)

// clientはチャットを行っている1人のユーザーを表します
type client struct {
	// socketはこのクライアントのためのWebSocketですd
	socket *websocket.Conn
	// sendはメッセージが送られるチャネルです
	send chan []byte
	// roomはこのクライアントが参加しているチャットルームです
	room *room
}
