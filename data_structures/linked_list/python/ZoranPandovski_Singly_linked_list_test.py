from .ZoranPandovski_Singly_linked_list import linkedlist, node

# test cases
def test_insert():
    list = linkedlist()
    list.head = node('a')
    list.push('b')
    list.pushend('c')
    node1 = node('c')
    list.push_after(node1,'d') # How is prev_node defined here?
    # Ideally node d should be inserted at the end of node c, being the last
    # element of the list, but here it is not sucessfully inserted, such that the
    # resulting list has only elements [a, b, c] and an error occurs for the fourth
    # deletion. The documentation about push_after() function is not very clear.
    
    # The issue here is that the list doesn't recognize the prev_node is a node already
    # in the list. If this cannot be detected, this function is not very useful.
    
    if list.head.data == 'b':
        res = True
    else:
        res = False
    
    list.deletion(0)
    
    if list.head.data == 'a':
        res = True
    else:
        res = False
        
    list.deletion(0)
    
    if list.head.data == 'c':
        res = True
    else:
        res = False
        
    list.deletion(0)
    
    if list.head.data == 'd':
        res = True
    else:
        res = False
        
    return res
    
if __name__ == '__main__':
    result = test_insert()
    if result == True:
        print('Insertion test passed')
    else:
        print('Insertion test failed')
