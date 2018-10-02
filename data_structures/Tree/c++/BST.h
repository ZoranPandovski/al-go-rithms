#include <iostream>
#include <string>

template <class T>
class BST
{
    struct Node
    {
        Node *left = nullptr;
        Node *right = nullptr;
        T data = T(); // = NULL instead?
        
        bool isLeaf()
        {
            if (this->left == nullptr && this->right == nullptr)
                return true;
            
            else return false;
        }
    };

    Node *root;

// private functions doing the work behind the scenes
private:
    Node *inorder_successor(Node *root)
    {
        if (root->isLeaf())
            return root;

            // this case is for when we find the left most child but it has a right child
        else if (root->left == nullptr && root->right != nullptr)
            return inorder_successor(root->right);

        else return inorder_successor(root->left); // recursive case to find left most
    }

    Node *add(Node *root, T data)
    {
        if (root == nullptr) // tree isn't populated OR proper spot has been found
        {
            Node *temp = new Node();
            temp->data = data;
            return temp;
        }

        else if (data < root->data) // recurse to left side of tree
            root->left = add(root->left, data);
        
        else if (data > root->data) // recurse to right side of tree
            root->right = add(root->right, data);
    }

    Node *remove(Node *root, T data)
    {
        if (root == nullptr)
            return root;
        
        else if (data < root->data)
            root->left = remove(root->left, data);
        
        else if (data > root->data)
            root->right = remove(root->right, data);
        
        else 
        { 
            if (root->isLeaf()) // the node has no children
            {
                Node *temp = root;
                free(temp);
                temp = nullptr;
                return temp; 
            }

            else if (root->left == nullptr) // the node has one child
            {
                Node *temp = root->right;
                free(root);
                return temp;
            }

            else if (root->right == nullptr) // the node only has one child
            {
                Node *temp = root->left;
                free(root);
                return temp;
            }

            else // the node has two children
            {
                Node *temp = inorder_successor(root->right);
                Node *parent;
                root->data = temp->data;
                root->right = remove(root->right, data);
            }

            return root;
        }
    }

    void clear_all(Node* curr)
    {
		if (curr != nullptr)
		{
			clear_all(curr->left);
			clear_all(curr->right);
			delete curr;
		}
    }

    unsigned int size(Node *root)
    {
        if (root == nullptr) // null child won't add to count
            return 0;
        
        else return 1 + size(root->left) + size(root->right);
    }

    struct Node* get_node(Node* curr, T data)
    {
        if (curr == nullptr)
            return nullptr;
        
        else if (curr->data == data) // target node found
            return curr;
        
        else if (data < curr->data) // recurse left
            get_node(curr->left, data);
        
        else if (data > curr->data) // recurse right
            get_node(curr->right, data);
    }

    void print_ascending(Node* curr)
    {
		if (curr != nullptr)
		{
			print_ascending(curr->left);

			std::cout << curr->data << std::endl;

			print_ascending(curr->right);
		}
    }

    void print_descending(Node* curr)
    {
		if (curr != nullptr)
		{
			print_descending(curr->right);

			std::cout << curr->data << std::endl;

			print_descending(curr->left);
		}
    }

// public functions that simplify calls for the user
public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        clear();

		if (root != nullptr)
		{
			delete root;
            root = nullptr;
		}
    }

    void clear()
    {
        if (root == nullptr)
            return;
        
		clear_all(root);

		if (root != nullptr)
			root = nullptr;
    }

    void add(T data)
    {
        root = add(root, data);
    }

    void add(T* data, unsigned int size)
    {
        for (unsigned int i = 0; i < size; i++)
            add(data[i]);
    }

    void remove(T data)
    {
        root = remove(root, data);
    }

    void remove(T* data, unsigned int size)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            remove(data);
        }
    }

    bool contains(T data)
    {
        if (get_node(root, data) != nullptr)
            return true;
        
        else
            return false;
    }

    unsigned int size()
    {
        return size(root);
    }

    void print(bool ascending)
    {
        if (ascending)
            print_ascending(root);

        else print_descending(root);
    }
};