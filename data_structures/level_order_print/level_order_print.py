class TreeNode(object):
    
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        
def level_order_print(node):
    
    nodes = [node]
    curr_count = 1
    next_count = 0
    curr_list = []
    
    while(len(nodes)):
        
        curr_node = nodes.pop()
        curr_count -= 1
        
        curr_list.insert(0, curr_node.val)        
        
        if curr_node.left:
            nodes.append(curr_node.left)
            next_count += 1
            
        if curr_node.right:
            nodes.append(curr_node.right)
            next_count += 1
            
        if not curr_count:
            print(curr_list)
            curr_count, next_count = next_count, curr_count
            curr_list = []

if __name__ == '__main__':
    a = TreeNode(5)
    b = TreeNode(4)
    c = TreeNode(6)
    d = TreeNode(2)
    a.left = b
    a.right = c
    level_order_print(a)            