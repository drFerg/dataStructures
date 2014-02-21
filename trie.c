/* trie.c
 *
 * A simple Trie data structure.
 *
 * Author: Fergus Leahy
 */
#include "trie.h"
#include "stdlib.h"
#include "stdio.h"

#ifdef DEBUG
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

int total = 0;

typedef struct node {
  char c;
  short isWord;
  struct node* sibling;
  struct node* child;
}Node;

struct trie {
  struct node *child;
  int size;
};

/* Helper function for creating a node */
Node *createNode(char c){
  Node *n = (Node *) malloc(sizeof(Node));
  if (!n) return NULL;
  n->c = c;
  n->isWord = 0;
  n->child = NULL;
  n->sibling = NULL;
  return n;
}

void trace(Node *n, char *word, int len) {
  if (n->c == word[0]) { /* node matches char */
    if (len == 1) { 
      n->isWord = 1; /* last char, so set as word*/
      return;
    }
    else if (!n->child) { /* no child, add char */
      n->child = createNode(word[1]);
    }
    trace(n->child, ++word, --len); /* try matching/adding next child char */
  } 
  else { /* no match, try siblings */
    if (!n->sibling) n->sibling = createNode(word[0]); /* no sibling, add char */
    trace(n->sibling, word, len);/* try matching/adding next sibling char */
  }
}

int find(Node *n, char *word, int len){
  if (n->c == word[0]){ /* node matches char */
    if (len == 1){ 
      return n->isWord; /* word matches if last char is end of word */
    } /* check children for subsequent chars */
    else if (n->child) return find(n->child, ++word, --len);
    else return 0; /* word doesn't match as node has no children */
  } /* no match, check siblings for match */
  else if (n->sibling) return find(n->sibling, word, len);
  else return 0; /* word doesn't match as node has no siblings */
}

Trie *init_trie(){
  Trie *t = (Trie *) malloc(sizeof(Trie));
  t->child = NULL;
  t->size = 0;
  return t;
}

void put(Trie *t, char *word, int len) {
  PRINTF("%s\n", word);
  if (t->child == NULL) t->child = createNode(word[0]);
  trace(t->child, word, len);
  t->size += len * sizeof(Trie);
}

int get(Trie *t, char *word, int len) {
  if (t) return find(t->child, word, len);
  else PRINTF("No trie passed\n");
  return 0;
}

int size(Trie *t){
  return total;
}