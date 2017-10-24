
## B-Tree
In computer science, a B-tree is a self-balancing tree data structure that
keeps data sorted and allows searches, sequential access, insertions, and
deletions in logarithmic time. The B-tree is a generalization of a binary
search tree in that a node can have more than two children (Comer 1979, p.
123). Unlike self-balancing binary search trees, the B-tree is optimized for
systems that read and write large blocks of data. B-trees are a good example of
a data structure for external memory. It is commonly used in databases and
filesystems.

## Variants
In the B+ tree, copies of the keys are stored in the internal nodes; the keys
and records are stored in leaves; in addition, a leaf node may include a
pointer to the next leaf node to speed sequential access (Comer 1979, p. 129).

The B* tree balances more neighboring internal nodes to keep the internal nodes
more densely packed (Comer 1979, p. 129). This variant requires non-root nodes
to be at least 2/3 full instead of 1/2 (Knuth 1998, p. 488). To maintain this,
instead of immediately splitting up a node when it gets full, its keys are
shared with a node next to it. When both nodes are full, then the two nodes are
split into three. Deleting nodes is somewhat more complex than inserting
however.

B-trees can be turned into order statistic trees to allow rapid searches for
the Nth record in key order, or counting the number of records between any two
records, and various other related operations.

![](https://upload.wikimedia.org/wikipedia/commons/6/65/B-tree.svg)

[Source](https://en.wikipedia.org/wiki/B-tree)
