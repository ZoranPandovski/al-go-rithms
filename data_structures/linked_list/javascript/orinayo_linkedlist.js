// Description
// Implement classes Node and Linked Lists

class Node {
  // Creates a class instance to represent a node. The node should have two properties,
  // 'data' and 'next'. Accept both of these as arguments to the 'Node' constructor, 
  // then assign them to the instance as properties 'data' and 'next'. If 'next' is not
  // provided to the constructor, then default its value to be 'null'.
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

class LinkedList {
  // Creates a class to represent a linked list. When created, a linked list should have 
  // *no* head node associated with it. The LinkedList instance will have one property, 'head',
  // which is a reference to the first node of the linked list. By default 'head' should be 'null'.
  constructor() {
    this.head = null;
  }

  // Creates a new Node from argument 'data' and assigns the resulting node to the 'head' property.
  // Make sure to handle the case in which the linked list already has a node assigned to the 'head' property.
  insertFirst(data) {
    this.head = new Node(data, this.head);
  }

  // Returns the number of nodes in the linked list.
  size() {
    let counter = 0;
    let node = this.head;

    while (node) {
      counter++;
      node = node.next;
    }

    return counter;
  }

  // Returns the first node of the linked list.
  getFirst() {
    return this.head;
  }

  // Returns the last node of the linked list
  getLast() {
    if (!this.head) {
      return null;
    }

    let node = this.head;
    while (node) {
      if (!node.next) {
        return node;
      }
      node = node.next;
    }
  }

  // Empties the linked list of any nodes.
  clear() {
    this.head = null;
  }

  // Removes only the first node of the linked list. The list's head should now be the second element.
  removeFirst() {
    if (!this.head) {
      return;
    }

    this.head = this.head.next;
  }

  // Removes the last node of the chain
  removeLast() {
    if (!this.head) {
      return;
    }

    if (!this.head.next) {
      this.head = null;
      return;
    }

    let previous = this.head;
    let node = this.head.next;
    while (node.next) {
      previous = node;
      node = node.next;
    }
    previous.next = null;
  }

  // Inserts a new node with provided data at the end of the chain
  insertLast(data) {
    const last = this.getLast();

    if (last) {
      // There are some existing nodes in our chain
      last.next = new Node(data);
    } else {
      // The chain is empty!
      this.head = new Node(data);
    }
  }

  // Returns the node at the provided index
  getAt(index) {
    let counter = 0;
    let node = this.head;
    while (node) {
      if (counter === index) {
        return node;
      }

      counter++;
      node = node.next;
    }
    return null;
  }

  // Removes node at the provided index
  removeAt(index) {
    if (!this.head) {
      return;
    }

    if (index === 0) {
      this.head = this.head.next;
      return;
    }

    const previous = this.getAt(index - 1);
    if (!previous || !previous.next) {
      return;
    }
    previous.next = previous.next.next;
  }

  // Create an insert a new node at provided index. If index is out of bounds, 
  // add the node to the end of the list.
  insertAt(data, index) {
    if (!this.head) {
      this.head = new Node(data);
      return;
    }

    if (index === 0) {
      this.head = new Node(data, this.head);
      return;
    }

    const previous = this.getAt(index - 1) || this.getLast();
    const node = new Node(data, previous.next);
    previous.next = node;
  }

  // Calls the provided function with every node of the chain and the index of the node.
  forEach(fn) {
    let node = this.head;
    let counter = 0;
    while (node) {
      fn(node, counter);
      node = node.next;
      counter++;
    }
  }

  // Linked list should be compatible as the subject of a 'for...of' loop
  *[Symbol.iterator]() {
    let node = this.head;
    while (node) {
      yield node;
      node = node.next;
    }
  }
}

module.exports = { Node, LinkedList };
