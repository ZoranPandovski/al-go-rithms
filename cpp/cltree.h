#pragma once

template <class datatype>
class treenode
{
public:
	datatype data;
	treenode<datatype> *lchild, *rchild;
};



template<class datatype>
class btree 
{
private:
	treenode<datatype> *root;
	int nodeCount(treenode<datatype> *pos);
	int leftNodeCount(treenode<datatype> *pos);
	int rightNodeCount(treenode<datatype> *pos);


public:
	btree();
	bool tree_empty(void);
	void insertdata(datatype x);
	void inserttree(treenode<datatype> *&p, datatype d);
	void inorder(treenode<datatype> *p);
	void printinorder(void);
	void preorder(treenode<datatype> *p);
	void printpreorder(void);
	void postorder(treenode<datatype> *p);
	void printpostorder(void);
	void deletevalue(datatype v);
	void deltree(datatype val, treenode<datatype> *&p);
	treenode<datatype>* findmin(treenode<datatype> *p);



	int treeNodeCount();
	int treeLeftnodeCount();
	int treeRightnodeCount();

};



template<class datatype>
treenode<datatype>* btree<datatype>::findmin(treenode<datatype> *p) 
{
	if (p->lchild == NULL)
	{
		return (p);
	}
	else
		return(findmin(p->lchild));
};




template<class datatype>
void btree<datatype>::deltree(datatype val, treenode<datatype> *&p) 
{
	treenode<datatype> *buff;
	treenode<datatype> *temp;
	if (p != NULL)
		if (val < p->data)
			deltree(val, p->lchild);
		else
			if (val > p->data)
				deltree(val, p->rchild);
			else
				if (p->lchild == NULL && p->rchild == NULL)
				{
					temp = p;
					p = NULL;
					delete temp;
				}
				else
					if (p->lchild == NULL)
					{
						temp = p;
						p = p->rchild;
						delete temp;

					}
					else
						if (p->rchild == NULL)
						{
							temp = p;
							p = p->lchild;
							delete temp;
						}
						else
						{
							buff = findmin(p->rchild);
							buff->lchild = p->lchild;
							temp = p;
							p = p->rchild;
							delete temp;
						}
};



template<class datatype>
void btree<datatype>::deletevalue(datatype v) 
{
	deltree(v, root);
};




template<class datatype>
void btree<datatype>::postorder(treenode<datatype> *p) 
{
	if (p != NULL) 
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout << p->data << "  ";
	}
};






template<class datatype>
void btree<datatype>::printpostorder(void) 
{
	postorder(root);
};







template<class datatype>
void btree<datatype>::preorder(treenode<datatype> *p)
{
	if (p != NULL) 
	{
		cout << p->data << "  ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
};







template<class datatype>
void btree<datatype>::printpreorder(void) 
{
	preorder(root);
};






template<class datatype>
void btree<datatype>::inorder(treenode<datatype> *p) 
{
	if (p != NULL) 
	{
		inorder(p->lchild);
		cout << p->data << "  ";
		inorder(p->rchild);
	}
};








template<class datatype>
void btree<datatype>::printinorder(void) 
{
	inorder(root);
};




template<class datatype>
void btree<datatype>::inserttree(treenode<datatype> *&p, datatype d) 
{
	if (p == NULL)
	{
		p = new treenode<datatype>;
		p->data = d;
		p->lchild = NULL;
		p->rchild = NULL;
	}
	else 
	{
		if (p->data > d)
			inserttree(p->lchild, d);
		else
			inserttree(p->rchild, d);
	}
};





template<class datatype>
void btree<datatype>::insertdata(datatype x) 
{

	inserttree(root, x);
};





template<class datatype>
btree<datatype>::btree() 
{
	root = NULL;
};





template<class datatype>
bool btree<datatype>::tree_empty() 
{
	bool x = true;
	if (root == NULL) 
	{
		x = true;
	}
	else 
	{
		x = false;
	}
	return x;
};



template <class datatype>
int btree<datatype>::nodeCount(treenode<datatype> *pos)
{	
	int count = 0;
	try
	{
		if (!tree_empty())
		{
			if (pos != NULL)
			{
				
				return count = nodeCount(pos->lchild) + 1 + nodeCount(pos->rchild);

			}
		}
		else
			cout << "There are no nodes in the tree to count " << endl;
	}
	catch (...)
	{
		cout << "Unknown and unhandeled exception error " << endl;
	}
}



template <class datatype>
int btree<datatype>::treeNodeCount() 
{
	return nodeCount(root);
}


template <class datatype>
int btree<datatype>::leftNodeCount(treenode<datatype> *pos)
{
	int count = 0;
	try
	{
		if (!tree_empty())
		{
			if (pos != NULL)
			{
				return count = nodeCount(pos->lchild) + 1;

			}
		}
		else
			cout << "There are no nodes in the tree to count " << endl;
	}
	catch (...)
	{
		cout << "Unknown and unhandeled exception error " << endl;
	}
}


template <class datatype>
int btree<datatype>::treeLeftnodeCount() 
{
	return leftNodeCount(root);
}



template <class datatype>
int btree<datatype>::rightNodeCount(treenode<datatype> *pos)
{
	int count = 0;
	try
	{
		if (!tree_empty())
		{
			if (pos != NULL)
			{
				return count = nodeCount(pos->rchild) + 1;

			}
		}
		else
			cout << "There are no nodes in the tree to count " << endl;
	}
	catch (...)
	{
		cout << "Unknown and unhandeled exception error " << endl;
	}
}



template <class datatype>
int btree<datatype>::treeRightnodeCount() 
{
	return rightNodeCount(root);
}



