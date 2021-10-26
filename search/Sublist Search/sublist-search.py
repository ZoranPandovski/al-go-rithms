# SUBLIST SEARCH

#Checks whether the first list is present in second list or not.

#Taking fisrt node of second list
class Nodes:
    def __init__(self, value = 0):
        self.value = value
        self.next = None

#Returns TRUE if fisrt list is in the second list.
def findList(first,second):

    if not first or not second:
        return False

    if not first and not second:
        return True

    p1 = first
    p2 = second
    # Traversing the second LL
    # Checking nodes from both lists
    while p2:
        #Initializing p2 with current node of second LL
        p2 = second
#Starting our matching
        while p1:
            # If second LL become empty and
            # first not, return False,
            if not p2:
                return False

            #if nodes match, increase the pointers
            #for checking the next nodes
            elif p1.value == p2.value:
                p1 = p1.next
                p2 = p2.next

            #If nodes don't match further or the
            #p1 is None/empty
            else:
                break
            #Checks

        if not p1:       #p1 is empty/None
            return True  #Completely traversed and matched

        #If p1 is not empty/None
        p1 = first #bringing back to fisrt
        second = second.next   #increament second node element
    return False

#Driver Code
#Enter two linked list
# Example -
#node_a: 1-> 2-> 3-> 4
# node_b: 1->2->1->2->3->4
node_a = Nodes(1)
node_a.next = Nodes(2)
node_a.next.next = Nodes(3)
node_a.next.next.next = Nodes(4)

node_b = Nodes(1)
node_b.next = Nodes(2)
node_b.next.next = Nodes(1)
node_b.next.next.next = Nodes(2)
node_b.next.next.next.next = Nodes(3)
node_b.next.next.next.next.next = Nodes(4)

if findList(node_a, node_b):
    print("LIST FOUND")
else:
    print("LIST NOT FOUND")

#OUTPUT : LIST FOUND     
