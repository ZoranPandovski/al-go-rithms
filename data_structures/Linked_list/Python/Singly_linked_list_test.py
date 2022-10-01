from Singly_linked_list import linkedlist, node

list=linkedlist()
list.head=node("Monday")
list1=node("Tuesday")
list2=node("Thursday")
list.head.next=list1
list1.next=list2
print("Before insertion:")
list.printing()
print('\n')
list.push_after(list1,"Wednesday")
print("After insertion:")
list.printing()
print('\n')
list.deletion(3)
print("After deleting 4th node")
list.printing()
