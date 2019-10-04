import sys
import bisect

class Node():
    def __init__(self, lf):
        self.keys = []
        self.children = []
        self.next = None
        self.leaf = lf
    def kaatde(self):
        mid = len(self.keys) // 2
        mval = self.keys[mid]
        nw_node = Node(self.leaf)
        
        nw_node.keys = self.keys[mid:] if self.leaf else self.keys[mid+1:]
        nw_node.children = self.children[mid:] if self.leaf else self.children[mid+1:]
        self.keys = self.keys[:mid]
        self.children = self.children[:mid] if self.leaf else self.children[:mid+1]

        if self.leaf:
            nw_node.next = self.next
            self.next = nw_node
        
        return mval, nw_node

class Btree(Node):
    def __init__(self):
        self.pt = 4
        self.n = 3
        self.root = Node(True)

    def get_leaf(self,val,node):
        if node.leaf == False:
            for ind, key in enumerate(node.keys):
                if ind == 0 and val<= key: return self.get_leaf(val,node.children[ind])
                elif ind == len(node.keys)-1 and val <= key: continue
                elif ind == len(node.keys)-1 and val > key: return self.get_leaf(val,node.children[-1])
                if val > key and val <= node.keys[ind+1]: return self.get_leaf(val,node.children[ind+1])
        else :
            return node

    def keys_in_range(self, mn, mx, node):
        ans = 0
        for _ , key in enumerate(node.keys):
            if key >= mn and key <= mx: ans+=1   

        if len(node.keys) == 0:
            return ans,None
        elif node.keys[-1] > mx:
            return ans, None
        else :
            return ans, node.next
    
    def range(self, mn, mx):
        st_node = self.get_leaf(mn, self.root)
        ans = 0

        while st_node is not None:
            cnt, st_node = self.keys_in_range(mn,mx,st_node)
            ans += cnt
        return ans

    def insert(self, value, node):
        
        if node.leaf == True:
            idx = bisect.bisect(node.keys,value)
            node.keys.insert(idx,value)
            node.children.insert(idx,value)

            if len(node.keys) <= self.n : 
                return None, None
            else:
                return node.kaatde()

        for ind, key in enumerate(node.keys):
            if value < key and ind == 0:
                mid_val, nw = self.insert(value,node.children[ind])
                break
            elif ind == (len(node.keys) -1) and value < key: continue
            elif ind == (len(node.keys) -1) and value >= key: 
                mid_val, nw = self.insert(value,node.children[-1])
                break
            elif value >= key and value < node.keys[ind+1]:
                mid_val, nw = self.insert(value,node.children[ind+1])
                break
        
        if mid_val:
            idx = bisect.bisect(node.keys, mid_val)
            node.keys.insert(idx, mid_val)
            node.children.insert(idx+1, nw)

            if len(node.keys)<= self.n :
                return None, None
            else:
                return node.kaatde()
        else:
            return None, None
    
    def insert_op(self, value):
        mid, nw_node = self.insert(value,self.root)
        if mid:
            new_root = Node(True)
            new_root.children = [self.root, nw_node]
            new_root.keys = [mid]
            new_root.leaf = False
            self.root = new_root
            
# Globals
output =  []
# parser command
def doit(fname):
    with open(fname,'r') as f:
        for line in f:
            cmd = line.strip().lower().split()
            if cmd[0]== "insert":
                btree.insert_op(int(cmd[1]))
            if cmd[0]== "count":
                out = btree.range(int(cmd[1]),int(cmd[1]))
                output.append(str(out))
            if cmd[0]== "find":
                out = btree.range(int(cmd[1]),int(cmd[1]))
                output.append("YES" if out>0 else "NO")
            if cmd[0]== "range":
                out = btree.range(int(cmd[1]),int(cmd[2]))
                output.append(str(out))
    for i in output:
        print(i)
# beginning of code
if len(sys.argv) != 2:
    sys.exit("syntax error//")

fname = sys.argv[1]
btree = Btree()
doit(fname)