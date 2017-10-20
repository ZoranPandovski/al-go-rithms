package main

import "fmt"

// Node holds a Value of type int as well as a pointer to the node in
// front (Next) and a pointer to the node behind (Previous) it. These
// two pointers are the foundation of a doubly linked list.
type Node struct {
	Value          int
	Next, Previous *Node
}

// DoublyLinkedList holds only two pointers, one to the Head node and
// one to the Tail node of a list. Head and Tail will point to the
// same node if a list contains only that single node.
type DoublyLinkedList struct {
	Head, Tail *Node
}

// LoneNode is a helper function that adds a single node to a
// DoublyLinkedList. Since it's the only node in the list it becomes
// both the Head and Tail.
func (d *DoublyLinkedList) LoneNode(v int) {
	newNode := &Node{v, nil, nil}
	d.Head = newNode
	d.Tail = newNode
}

// Find searches for a Node in the list containing the Value v and
// returns a pointer to that Node.
func (d *DoublyLinkedList) Find(v int) *Node {
	for node := d.Head; node != nil; node = node.Next {
		if node.Value == v {
			return node
		}
	}

	return nil
}

// InsertBefore creates a new Node with the Value v and inserts it
// before node. If node is the Head then the new Node will become the
// Head.
func (d *DoublyLinkedList) InsertBefore(node *Node, v int) {
	if node == d.Head {
		newNode := &Node{v, node, nil}
		node.Previous = newNode
		d.Head = newNode
		return
	}

	newNode := &Node{v, node, node.Previous}
	node.Previous.Next = newNode
	node.Previous = newNode
}

// InsertAfter creates a new Node with the Value v and inserts it
// after node. If node is the Tail then the new Node will become the
// Tail.
func (d *DoublyLinkedList) InsertAfter(node *Node, v int) {
	if node == d.Tail {
		newNode := &Node{v, nil, node}
		node.Next = newNode
		d.Tail = newNode
		return
	}

	newNode := &Node{v, node.Next, node}
	node.Next.Previous = newNode
	node.Next = newNode
}

// InsertHead inserts a new Node with the Value v as the Head of the
// list. If there is currently no Head (i.e. the list is empty) then
// this new Node becomes both the Head and the Tail of a single node
// list, otherwise the new Node is inserted before the current Head.
func (d *DoublyLinkedList) InsertHead(v int) {
	if d.Head == nil {
		d.LoneNode(v)
		return
	}

	d.InsertBefore(d.Head, v)
}

// InsertTail inserts a new Node with the Value v as the Tail of the
// list. If there is currently no Tail (i.e. the list is empty) then
// this new Node becomes both the Head and the Tail of a single node
// list, otherwise the new Node is inserted after the current Tail.
func (d *DoublyLinkedList) InsertTail(v int) {
	if d.Tail == nil {
		d.LoneNode(v)
		return
	}

	d.InsertAfter(d.Tail, v)
}

// Print list from Head to Tail.
func (d *DoublyLinkedList) PrintFoward() {
	for node := d.Head; node != nil; node = node.Next {
		fmt.Printf("%d", node.Value)
	}
	fmt.Println()
}

// Print list from Tail to Head.
func (d *DoublyLinkedList) PrintReverse() {
	for node := d.Tail; node != nil; node = node.Previous {
		fmt.Printf("%d", node.Value)
	}
	fmt.Println()
}

func main() {
	var dll DoublyLinkedList

	dll.InsertHead(2)
	dll.InsertTail(5)

	dll.InsertAfter(dll.Find(2), 3)
	dll.InsertBefore(dll.Find(5), 4)

	dll.InsertTail(7)

	dll.InsertBefore(dll.Find(7), 6)

	dll.InsertHead(1)
	dll.InsertTail(8)

	dll.PrintFoward()
	dll.PrintReverse()
}
