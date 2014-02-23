#include <stdlib.h>
#include "binaryTree.h"

struct bnode {
  void *payload;
  struct bnode *leftChild;
  struct bnode *rightChild;
};

struct bTree {
  Comparator compare;
  struct bnode *root;
};

struct bnode *newBNode(void *payload){
  struct bnode *n = (struct bnode*) malloc(sizeof(struct bnode));
  n->payload = payload;
  n->leftChild = NULL;
  n->rightChild = NULL;
}

void recursivePut(Comparator compare, struct bnode *n, void *payload){
  int r = compare(n->payload, payload);
  if (r == 0) return;
  else if (r < 0){
    if (n->leftChild) recursivePut(compare, n->leftChild, payload);
    else n->leftChild = newBNode(payload);
  }
  else {
    if (n->rightChild) recursivePut(compare, n->rightChild, payload);
    else n->rightChild = newBNode(payload);
  }
}

int recursiveSearch(Comparator compare, struct bnode *n, void *payload){
  int r = compare(n->payload, payload);
  if (r == 0) return 1;
  else if (r < 0){
    if (n->leftChild) recursiveSearch(compare, n->leftChild, payload);
    else return 0;
  }
  else {
    if (n->rightChild) recursiveSearch(compare, n->rightChild, payload);
    else return 0;
  }
}

BTree *btree_create(Comparator compare){
  BTree *t = (BTree *) malloc(sizeof(BTree));
  t->compare = compare;
  t->root = NULL;
  return t;
}

void btree_put(BTree *t, void *payload){
  if (t->root) recursivePut(t->compare, t->root, payload);
  else t->root = newBNode(payload);
}   

int btree_search(BTree *t, void *payload){
  if (t->root) recursiveSearch(t->compare, t->root, payload);
  else return 0;
}