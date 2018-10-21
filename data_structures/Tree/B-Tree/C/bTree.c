#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "bTree.h"

#define MAX_KEYS (1024)

struct btNode {
    int isLeaf;     /* is this a leaf node? */
    int numKeys;    /* how many keys does this node contain? */
    int keys[MAX_KEYS];
    struct btNode *kids[MAX_KEYS+1];  /* kids[i] holds nodes < keys[i] */
};

bTree
btCreate(void)
{
    bTree b;

    b = malloc(sizeof(*b));
    assert(b);

    b->isLeaf = 1;
    b->numKeys = 0;

    return b;
}

void
btDestroy(bTree b)
{
    int i;

    if(!b->isLeaf) {
        for(i = 0; i < b->numKeys + 1; i++) {
            btDestroy(b->kids[i]);
        }
    }

    free(b);
}

/* return smallest index i in sorted array such that key <= a[i] */
/* (or n if there is no such index) */
static int
searchKey(int n, const int *a, int key)
{
    int lo;
    int hi;
    int mid;

    /* invariant: a[lo] < key <= a[hi] */
    lo = -1;
    hi = n;

    while(lo + 1 < hi) {
        mid = (lo+hi)/2;
        if(a[mid] == key) {
            return mid;
        } else if(a[mid] < key) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return hi;
}

int
btSearch(bTree b, int key)
{
    int pos;

    /* have to check for empty tree */
    if(b->numKeys == 0) {
        return 0;
    }

    /* look for smallest position that key fits below */
    pos = searchKey(b->numKeys, b->keys, key);

    if(pos < b->numKeys && b->keys[pos] == key) {
        return 1;
    } else {
        return(!b->isLeaf && btSearch(b->kids[pos], key));
    }
}

/* insert a new key into a tree */
/* returns new right sibling if the node splits */
/* and puts the median in *median */
/* else returns 0 */
static bTree
btInsertInternal(bTree b, int key, int *median)
{
    int pos;
    int mid;
    bTree b2;

    pos = searchKey(b->numKeys, b->keys, key);

    if(pos < b->numKeys && b->keys[pos] == key) {
        /* nothing to do */
        return 0;
    }

    if(b->isLeaf) {

        /* everybody above pos moves up one space */
        memmove(&b->keys[pos+1], &b->keys[pos], sizeof(*(b->keys)) * (b->numKeys - pos));
        b->keys[pos] = key;
        b->numKeys++;

    } else {

        /* insert in child */
        b2 = btInsertInternal(b->kids[pos], key, &mid);
        
        /* maybe insert a new key in b */
        if(b2) {

            /* every key above pos moves up one space */
            memmove(&b->keys[pos+1], &b->keys[pos], sizeof(*(b->keys)) * (b->numKeys - pos));
            /* new kid goes in pos + 1*/
            memmove(&b->kids[pos+2], &b->kids[pos+1], sizeof(*(b->keys)) * (b->numKeys - pos));

            b->keys[pos] = mid;
            b->kids[pos+1] = b2;
            b->numKeys++;
        }
    }

    /* we waste a tiny bit of space by splitting now
     * instead of on next insert */
    if(b->numKeys >= MAX_KEYS) {
        mid = b->numKeys/2;

        *median = b->keys[mid];

        /* make a new node for keys > median */
        /* picture is:
         *
         *      3 5 7
         *      A B C D
         *
         * becomes
         *          (5)
         *      3        7
         *      A B      C D
         */
        b2 = malloc(sizeof(*b2));

        b2->numKeys = b->numKeys - mid - 1;
        b2->isLeaf = b->isLeaf;

        memmove(b2->keys, &b->keys[mid+1], sizeof(*(b->keys)) * b2->numKeys);
        if(!b->isLeaf) {
            memmove(b2->kids, &b->kids[mid+1], sizeof(*(b->kids)) * (b2->numKeys + 1));
        }

        b->numKeys = mid;

        return b2;
    } else {
        return 0;
    }
}

void
btInsert(bTree b, int key)
{
    bTree b1;   /* new left child */
    bTree b2;   /* new right child */
    int median;

    b2 = btInsertInternal(b, key, &median);

    if(b2) {
        /* basic issue here is that we are at the root */
        /* so if we split, we have to make a new root */

        b1 = malloc(sizeof(*b1));
        assert(b1);

        /* copy root to b1 */
        memmove(b1, b, sizeof(*b));

        /* make root point to b1 and b2 */
        b->numKeys = 1;
        b->isLeaf = 0;
        b->keys[0] = median;
        b->kids[0] = b1;
        b->kids[1] = b2;
    }
}
