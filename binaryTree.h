#ifndef BINARY_TREE_H
#define BINARY_TREE_H
typedef int (*Comparator)(void *a, void *b);
typedef struct bTree BTree;

BTree *btree_create(Comparator compare);
void btree_put(BTree *t, void *payload);
int btree_search(BTree *t, void *payload);

#endif /* BINARY_TREE_H */