#ifndef __PTREE_H__
#define __PTREE_H__

#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const static u_int8_t bitmask[] =
  {0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff};

static const int  LINK_NULL    = 0x00;
static const int  LINK_0_OK    = 0x01;
static const int  LINK_1_OK    = 0x02;
static const int  LINK_BOTH_OK = 0x03;

template<class T> class PTreeNode;

template<class T> class PTree 
{
private:

  PTreeNode<T> root;
  PTreeNode<T> *ptr;
  void deleteNode (PTreeNode<T> * t);
  void branchNode (PTreeNode<T> * a, PTreeNode<T> * b);
  unsigned int dataCount;

  inline int MIN(int N1, int N2) { return (((N1) < (N2)) ? (N1) : (N2)); }
  inline u_int8_t CHECK_BIT(u_int8_t *K, int L) 
  { return ((((u_int8_t *)(K))[(L)/8] >> (7 - (L)%8)) & 1); }
  inline bool MATCH_KEY(u_int8_t * K1, u_int8_t * K2, int L)
  {
    return (((L >= 8) ? (memcmp ((u_int8_t*)(K1), (u_int8_t*)(K2), (L)/8) == 0) : 1 )
	    && (((L) % 8 > 0) ?					   
		((((u_int8_t*)(K1))[(L)/8] & bitmask[(L)%8]) ==	
		 (((u_int8_t*)(K2))[(L)/8] & bitmask[(L)%8])) : 1));
  }
  PTreeNode<T> * reHead (PTreeNode<T> * p);

public:
  PTree () {}
  ~PTree () { this->root.deleteAllNode (); }
  T * fetch (void * key, size_t len);
  T * lookup (void * key, size_t len);
  T * search (void * key, size_t len);
  bool remove (void * key, size_t len);
  bool insert (void * key, size_t len, T * p);
  
  void feInit ();
  void feNext ();
  bool feEnd ();
  T * feGet ();

  unsigned int getCount () { return this->dataCount; }
};

template<class S> class PTreeNode 
{
  friend class PTree<S>;

private:
  u_int8_t *key;
  int keylen;
  S * data;
  bool alloc;
  PTreeNode * parent;
  PTreeNode * link[2];
  static int nodeCount ;

  static const int DEBUG_PTREE_NODE = false;

  void setKey (u_int8_t * key, int len);
  void setChild (PTreeNode * pnode);
  void unsetChild (PTreeNode * pnode);
  void deleteAllNode (void);
  int getDataCount () { return this->dataCount; }

  inline int OCTET_SPACE(int bits) { return ((((bits)-1)/8)+1); }
  inline u_int8_t CHECK_BIT(u_int8_t *K, int L) 
  { return ((((u_int8_t *)(K))[(L)/8] >> (7 - (L)%8)) & 1); }

public:  
  PTreeNode (u_int8_t * _key = NULL, int _keylen = 0) : 
    key (NULL), keylen (0), data (NULL), alloc (NULL), parent (NULL)
  {
    this->link [0] = NULL;
    this->link [1] = NULL;

    if (_key)
      this->setKey (_key, _keylen);

    nodeCount++;
  }; 

  ~PTreeNode ()
  {
    if (this->data && this->alloc)
      delete this->data;
    if (this->key)
      free (this->key);

    nodeCount--;
  }

  static int getNodeCount () { return nodeCount; }
};

template<class S>
int PTreeNode<S>::nodeCount = 0;


template<class T>
T * PTree<T>::fetch (void * _key, size_t _len)
{
  u_int8_t * key = static_cast<u_int8_t*>(_key);
  int keyLen = static_cast<int>(_len * 8);

  PTreeNode<T> * bp, * mp; 
  PTreeNode<T> * t = NULL; 
  assert (key && keyLen > 0);

  for (bp = &this->root, mp = NULL; 
       bp != NULL && MATCH_KEY (bp->key, key, bp->keylen);
       bp = bp->link [CHECK_BIT (key, bp->keylen)])
    {
      mp = bp;

      if (bp->keylen >= keyLen)
	break;
    }

  if (bp == NULL)
    bp = mp;
  
  if (bp->keylen == keyLen && MATCH_KEY (bp->key, key, bp->keylen))
    {
      t = bp;
    }
  else
    {
      t = new PTreeNode<T> (key, keyLen);
      this->branchNode (bp, t);
    }

  if (t->data == NULL)
    {
      t->data = new T ;
      t->alloc = true;
      this->dataCount++;
    }
  
  return t->data;
}

template<class T>
T * PTree<T>::lookup (void * _vkey, size_t _len)
{
  u_int8_t * argKey = static_cast<u_int8_t*>(_vkey);
  int argKeylen = static_cast<int>(_len * 8);

  PTreeNode<T> * n;
  assert (argKey && argKeylen > 0);

  if (argKeylen == 0)
    return NULL;

  for (n = &this->root; 
       n && argKeylen >= n->keylen; 
       n = n->link [CHECK_BIT (argKey, n->keylen)])
    {
      if (n->keylen == argKeylen && MATCH_KEY (n->key, argKey, n->keylen))
	return n->data;

      if (n->keylen >= argKeylen)
	break;
    }

  return NULL;
}

template<class T>
T * PTree<T>::search (void * _key, size_t _len)
{
  u_int8_t * argKey = static_cast<u_int8_t*>(_key);
  int argKeylen = static_cast<int>(_len * 8);

  PTreeNode<T> * n;
  assert (argKey && argKeylen > 0);

  if (argKeylen == 0)
    return NULL;

  T * tgt = NULL;
  for (n = &this->root; n && argKeylen >= n->keylen; 
       n = n->link [CHECK_BIT (argKey, n->keylen)])
    {
      if (n->keylen > 0 && ! MATCH_KEY (n->key, argKey, n->keylen))
	break;
	
      if (n->data)
	tgt = n->data;

      if (n->keylen >= argKeylen)
	break;
    }

  return tgt;
}

template<class T>
bool PTree<T>::remove (void * _key, size_t _len)
{
  u_int8_t * argKey = static_cast<u_int8_t*>(_key);
  int argKeylen = static_cast<int>(_len * 8);

  PTreeNode<T> * n, * t = NULL;
  assert (argKey && argKeylen > 0);

  for (n = &this->root; n && argKeylen >= n->keylen; 
       n = n->link [CHECK_BIT (argKey, n->keylen)])
    {
      if (n->keylen == argKeylen && MATCH_KEY (n->key, argKey, n->keylen))
	{
	  t = n;
	  break;
	}

      if (n->keylen >= argKeylen)
	break;
    }

  if (! t || !t->parent)
    return false; 
  this->deleteNode (t);
  this->dataCount--;
  assert (this->dataCount >= 0);
  return true;
}

template<class T>
bool PTree<T>::insert (void * _key, size_t _len, T * p)
{
  u_int8_t * argKey = static_cast<u_int8_t*>(_key);
  int argKeylen = static_cast<int>(_len * 8);
  PTreeNode<T> * bp, * mp; 
  PTreeNode<T> * t = NULL; 
  assert (argKey && argKeylen > 0);

  for (bp = &this->root, mp = NULL; 
       bp != NULL && MATCH_KEY (bp->key, argKey, bp->keylen);
       bp = bp->link [CHECK_BIT (argKey, bp->keylen)])
    {
      mp = bp;

      if (bp->keylen >= argKeylen)
	break;
    }

  if (bp == NULL)
    bp = mp;
  
  if (bp->keylen == argKeylen && MATCH_KEY (bp->key, argKey, bp->keylen))
    {
      t = bp;

      if (t->data)
	return false;
    }
  else
    {
      t = new PTreeNode<T> (argKey, argKeylen);
      this->branchNode (bp, t);
    }

  assert (t->data == NULL);
  t->data = p;
  this->dataCount++;

  return true;
}

template <class T>
void PTree<T>::deleteNode (PTreeNode<T> * t)
{
  int st = LINK_NULL;
  bool delNode = true;
  PTreeNode<T> * parent = t->parent;

  if (! t->parent)
    return ; 

  st |= (t->link[0] ? LINK_0_OK : LINK_NULL);
  st |= (t->link[1] ? LINK_1_OK : LINK_NULL);

  switch (st)
    {
    case LINK_0_OK: t->parent->setChild (t->link[0]); break;
    case LINK_1_OK: t->parent->setChild (t->link[1]); break;
    case LINK_NULL: t->parent->unsetChild (t); break;
    case LINK_BOTH_OK:
      delete t->data;
      t->data = NULL;
      delNode = false;
      break;
    }

  if (delNode)
    {
      delete t;
      if (parent->data == NULL &&
	  (parent->link [0] == NULL || parent->link [1] == NULL))
	this->deleteNode (parent);
    }

  return ;
}


template <class T>
void PTree<T>::branchNode (PTreeNode<T> * a, PTreeNode<T> * b)
{
  int len, min, i;
  PTreeNode<T> * parent, * branch, * child;

  assert (b != NULL);

  min = MIN (a->keylen, b->keylen);
  for (i = 0, len = 0; i < (min/8) && a->key[i] == b->key[i] ; i++)
    len += 8;
  for (; len < min; len++)
    if (CHECK_BIT (a->key, len) != CHECK_BIT (b->key, len))
      break;

  assert (len != a->keylen || len != b->keylen);

  if (a->parent != NULL || b->parent != NULL)
    parent = (a->parent != NULL) ? a->parent : b->parent;
  else
    parent = NULL;

  if (len == a->keylen || len == b->keylen)
    {
      branch = (a->keylen < b->keylen) ? a : b;
      child  = (a->keylen < b->keylen) ? b : a;
      branch->setChild (child);
    }
  else
    {
      branch = new PTreeNode<T> (a->key, len);
      branch->setChild (a);
      branch->setChild (b);
    }

  if (parent)
    parent->setChild (branch);

  return;
}


template <class S>
void PTreeNode<S>::setKey (u_int8_t * _key, int _keylen)
{
  if (this->key)
    free (this->key);
  
  if (0 < (this->keylen = _keylen))
    {
      this->key = (u_int8_t*) calloc (OCTET_SPACE (_keylen) + 1, sizeof(u_int8_t));
      memcpy (this->key, _key, OCTET_SPACE (_keylen));
    }
  else
    this->key = NULL;
} 


template <class S>
void PTreeNode<S>::setChild (PTreeNode * child)
{
  assert (child);

  this->link [CHECK_BIT (child->key, this->keylen)] = child;
  child->parent = this;
  return;
}

template <class S>
void PTreeNode<S>::unsetChild (PTreeNode * child)
{
  assert (child);
  this->link [CHECK_BIT (child->key, this->keylen)] = NULL;
  child->parent = NULL;
  return;
}



template <class S>
void PTreeNode<S>::deleteAllNode (void)
{
  if (this->link[0])
    {
      this->link[0]->deleteAllNode ();
      assert (this->link[0]->link[0] == NULL &&
	      this->link[0]->link[1] == NULL);
      delete this->link[0];
      this->link[0] = NULL;
    }
  if (this->link[1])
    {
      this->link[1]->deleteAllNode ();
      assert (this->link[1]->link[0] == NULL &&
	      this->link[1]->link[1] == NULL);
      delete this->link[1];
      this->link[1] = NULL;
    }

  return ;
}

template<class T>
void PTree<T>::feInit ()
{
  this->ptr = this->reHead (&this->root);
  return ;
}

template<class T>
PTreeNode<T> * PTree<T>::reHead (PTreeNode<T> * p)
{
  while (p->link[0] || p->link[1])
    {
      while (p->link[0])
	p = p->link[0];

      while (p->link[1])
	p = p->link[1];
    }

  return p;
}

template<class T>
void PTree<T>::feNext ()
{
  if (this->ptr == NULL)
    return ;

  PTreeNode<T> * next = this->ptr->parent;
  if (next == NULL || next->parent == NULL)
    {
      this->ptr = NULL;
      return ;
    }

  if (next->link[1] && next->link[1] != this->ptr)
    next = this->reHead (next->link[1]);

  this->ptr = next;

  if (this->ptr->data == NULL)
    this->feNext ();

  return ;
}

template<class T>
bool PTree<T>::feEnd ()
{
  return ((this->ptr == NULL || this->ptr == &this->root) ? true : false);
}
 
template<class T>
T * PTree<T>::feGet ()
{
  if (this->ptr == NULL)
    return NULL;
  else
    return this->ptr->data;
}


#endif 
