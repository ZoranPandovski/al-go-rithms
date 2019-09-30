/*
	this is an implementation of binary tree in c++
*/
#include <iostream>
#include <queue>
// TODO: implement level designed print functions
// example output:
//		3
//   1 	   5
//	0 2   4 6
// so on.

class BinarySearchTree{
private:
	typedef struct node{
		int value;
		int layer;
		node* left;
		node* right;
		node(int x){
			value = x;
			left = NULL;
			right = NULL;
		}
	} node;
	node* root;
private:
	void  printTreeUtil(node*);
	void  InOrderUtil(node*);
	void  PostOrderUtil(node*);
	void  PreOrderUtil(node*);
	void  BreadthFirstUtil(node*);
private:
	void  insertNodeUtil(node*, int);
	node* deleteNodeUtil(node*,int);
	node* findSmallest(node*);
	bool  searchUtil(node*, int);

public:
	BinarySearchTree();
	BinarySearchTree(int);
	~BinarySearchTree();
public:
	void insertNode(int);
	void deleteNode(int);
	// this search method can be defined differently depending on
	// structure of tree, since I decided to implement nodes as private
	// I will return bool indicating the searched value is found or not
	bool search(int);
public:
	void traverseIn_order();
	void traversePre_order();
	void traversePost_order();
	void traverseBreadthFirst();
	void printTree();
	void updateNode(int,int);
};

BinarySearchTree::BinarySearchTree(){
	// here initialize the binary tree
	root = NULL;
	layer = 0;
}

BinarySearchTree::~BinarySearchTree(){
	while(root!=NULL){
		this->deleteNode(root->value);
	}
}

void BinarySearchTree::insertNode(int value){
	this->insertNodeUtil(root,value);
}

void BinarySearchTree::insertNodeUtil(node* current, int value){
	if(current == NULL){
		//this is the root case:
		node* newNode= new node(value);
		root = newNode;
		return;
	}
	if(current->value < value){
		// if the given value is greater than node check right child
		// if right child is null then position is found, insert new child
		// if right child is not null continue recursively on right child of current node
		if(current->right == NULL){
			node* newNode= new node(value);
			current->right = newNode;
		}
		else this->insertNodeUtil(current->right, value);
	}
	else if(current->value > value){
		// this is the same as inserting towards right.
		if(current->left == NULL){
			node* newNode= new node(value);
			current->left = newNode;
		}
		else this->insertNodeUtil(current->left,value);
	}
}

void BinarySearchTree::deleteNode(int value){
	this->root = this->deleteNodeUtil(root,value);
}

BinarySearchTree::node* BinarySearchTree::findSmallest(node* current){
	node* temp = current;
	while(temp->left!=NULL){
		temp = temp->left;
	}
	return temp;
}
BinarySearchTree::node* BinarySearchTree::deleteNodeUtil(node* current, int value){
	if(current == NULL){
		std::cout<<"requested element is not found in tree"<<std::endl;
	}
	if(current->value < value){
		current->right = this->deleteNodeUtil(current->right,value);
	}
	else if(current->value > value){
		current->left = this->deleteNodeUtil(current->left,value);
	}
	else if(current->value == value){
		//implement this will take 5 mins.
		if(current->left == NULL){
			node* temp = current->right;
			delete current;
			return temp;
		}
		else if(current->right == NULL){
			node* temp = current->left;
			delete current;
			return temp;
		}
		node* smallest = this->findSmallest(current->right);
		current->value = smallest->value;
		current->right = deleteNodeUtil(current->right, smallest->value);
	}
	return current;
}

void BinarySearchTree::printTree(){
	this->printTreeUtil(root);
}

void BinarySearchTree::printTreeUtil(node* current){
	if(current == NULL) return;
	std::cout<<current->value<<std::endl;
	this->printTreeUtil(current->left);
	this->printTreeUtil(current->right);
}

void BinarySearchTree::traverseIn_order(){
	this->InOrderUtil(root);
}

void BinarySearchTree::InOrderUtil(node* current){
	if(current == NULL) return;
	this->InOrderUtil(current->left);
	std::cout<<current->value<<std::endl;
	this->InOrderUtil(current->right);
}

void BinarySearchTree::traversePost_order(){
	this->PostOrderUtil(root);
}

void BinarySearchTree::PostOrderUtil(node* current){
	if(current == NULL) return;
	this->PostOrderUtil(current->left);
	this->PostOrderUtil(current->right);
	std::cout<<current->value<<std::endl;
}

void BinarySearchTree::traversePre_order(){
	this->PreOrderUtil(root);
}

void BinarySearchTree::PreOrderUtil(node* current){
	if(current == NULL) return;
	std::cout<<current->value<<std::endl;
	this->PreOrderUtil(current->left);
	this->PreOrderUtil(current->right);
}

void BinarySearchTree::traverseBreadthFirst(){
	this->BreadthFirstUtil(root);
}

void BinarySearchTree::BreadthFirstUtil(node* current){
	std::queue<node*> levels;
	node* temp;

	levels.push(current);

	while(!levels.empty()){
		temp = levels.front();
		levels.pop();

		std::cout<<temp->value<<std::endl;
		if(temp->left != NULL) levels.push(temp->left);
		if(temp->right != NULL) levels.push(temp->right);
	}
}

bool BinarySearchTree::search(int value){
	return this->searchUtil(root,value);
}

bool BinarySearchTree::searchUtil(node* current, int value){
	if(current == NULL) return false;
	if(current->value == value) return true;
	else if(current->value > value) return this->searchUtil(current->left, value);
	else return this->searchUtil(current->right, value);
}

void BinarySearchTree::updateNode(int target, int nvalue){
	this->deleteNode(target);
	this->insertNode(nvalue);
}

int main(void){
	int testArr[] = {7,1,10,12,3};
	BinarySearchTree tree;
	for(int i =0; i< 5; i++){
		tree.insertNode(testArr[i]);
	}
	std::cout<<"in order traversal"<<std::endl;
	tree.traverseIn_order();
	std::cout<<"*******"<<std::endl;
	std::cout<<"post order traversal"<<std::endl;
	tree.traversePost_order();
	std::cout<<"*******"<<std::endl;
	std::cout<<"breadth first traversal"<<std::endl;
	tree.traverseBreadthFirst();
	std::cout<<"*******"<<std::endl;
	tree.printTree();
	std::cout<<"*******"<<std::endl;
	tree.deleteNode(7);
	tree.printTree();
	std::cout<<"*******"<<std::endl;
	std::cout<<(int)tree.search(3)<<std::endl;
	std::cout<<"*******"<<std::endl;
	tree.updateNode(3,15);
	tree.traverseBreadthFirst();
	std::cout<<"*******"<<std::endl;
	return 0;
}