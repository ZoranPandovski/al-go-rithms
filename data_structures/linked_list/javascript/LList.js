/*
 * Link List implementation in Javascript
 */

function _P(value){
	console.log(value);
}
function Node(element){
	this.element = element;
	this.next = null;
}

function LList(){
	this.head = new Node("head");
	this.find = find;
	this.insert = insert;
	this.display = display;
}
function find(item){
	var currNode = this.head;
	while(currNode.element != item){
		currNode = currNode.next;
	}
	return currNode;
}
function insert(newElement, item){
	var newNode = new Node(newElement);
	var current = this.find(item);
	newNode.next = current.next;
	current.next = newNode;
}

function display(){
	var currNode = this.head;
	while(!(currNode.next == null)){
		_P(currNode.next.element);
		currNode = currNode.next;
	}
}

var cities = new LList();
cities.insert("Kolkata", "head");
cities.insert("Mumbai", "Kolkata");
cities.insert("Delhi", "Mumbai");
cities.display();