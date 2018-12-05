# creating a node
class node: 
    def __init__(self, data): 
        self.data = data
        self.next = None  

class linkedlist: 
    def __init__(self):  
        self.head = None  #creating a header 
  
  
    #inserting a new node at the beginning 
    def push(self, new_data): 
        new_node = node(new_data) 
        new_node.next = self.head 
        self.head = new_node 

    #inserting a new node after a node    
    def push_after(self, prev_node, new_data): 
  
        #checking whether previous node exists 
        if prev_node is None: 
            print("The given previous node is not found.\n")
            return

        new_node = node(new_data) 
  
        #Make next of new Node as next of previous node 
        new_node.next = prev_node.next
  
        #make next of previous node as new node 
        prev_node.next = new_node 

    # append new node at the end
    def pushend(self, new_data): 

        new_node = node(new_data) 
  
        #If the Linked List is empty, then make the new node as head 
        if self.head is None: 
            self.head = new_node 
            return
  
        #otherwise traverse to the last node 
        end = self.head 
        while (end.next): 
            end = end.next
  
        #Change the next of last node 
        end.next =  new_node   

    def deletion(self, position): 
  
        #check if linked list is empty 
        if self.head == None: 
            return 
  
        # store header 
        temp = self.head 
  
        # If header is removed 
        if position == 0: 
            self.head = temp.next
            temp = None
            return 
  
        #previous node to the node to be deleted 
        for i in range(position -1 ): 
            temp = temp.next
            if temp is None: 
                break
  
        # If position is more than number of nodes 
        if temp is None and temp.next is None: 
            return


        # store pointer to the next of node to be deleted 
        next = temp.next.next
  
        # remove node from the linked list 
        temp.next = None
  
        temp.next = next

    def printing(self): 
        temp = self.head
        while temp is not None: 
            print(temp.data)
            temp = temp.next
