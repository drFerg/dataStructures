#include <stdio.h>
#include "binaryTree.h"

int intCompare(int a, int b){
  return (a > b ? a - b : (b > a ? b - a : 0));
}

int main(int argc, char const *argv[])
{
  int b = 156;
  int i = 0;
  int a[10] = {5, 0, 1, 2, 3, 4, 6, 7, 8, 9};
  BTree *t = btree_create((Comparator)(&intCompare));
  for(; i < 10; i++){
    btree_put(t, &(a[i]));
  }
  printf("%d\n", btree_search(t, &a[9]));
  printf("%d\n", btree_search(t, &b));
  return 0;
}