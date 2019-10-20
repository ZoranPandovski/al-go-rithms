/* implementation of a B-tree */
typedef struct btNode *bTree;

/* create a new empty tree */
bTree btCreate(void);

/* free a tree */
void btDestroy(bTree t);

/* return nonzero if key is present in tree */
int btSearch(bTree t, int key);

/* insert a new element into a tree */
void btInsert(bTree t, int key);

/* print all keys of the tree in order */
void btPrintKeys(bTree t);
