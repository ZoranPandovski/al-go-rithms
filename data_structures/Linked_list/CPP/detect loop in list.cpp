
it can be solved with various approach
we can use a hash map or we can use a boolean variable to check if
there is a loop or not

time complexity: O(n)
space : O(1) with map : O(n)

struct Node {
    int data;
    struct Node* next;
    int flag;
};

bool detectLoop(struct Node* h)
{
    while (h != NULL) {
        // If this node is already traverse
        // it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (h->flag == 1)
            return true;
 
        // If we are seeing the node for
        // the first time, mark its flag as 1
        h->flag = 1;
 
        h = h->next;
    }
 
    return false;
}