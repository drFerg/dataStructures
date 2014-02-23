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

typedef struct tnode {
  char c;
  short isWord;
  struct tnode* sibling;
  struct tnode* child;
}TNode;

struct trie {
  struct tnode *child;
  int size;
};

/* Helper function for creating a node */
TNode *createNode(char c){
  TNode *n = (TNode *) malloc(sizeof(TNode));
  if (!n) return NULL;
  n->c = c;
  n->isWord = 0;
  n->child = NULL;
  n->sibling = NULL;
  return n;
}

/* internal function for traversing/adding new characters */
void triePut(TNode *n, char *word, int len) {
  if (n->c == word[0]) { /* node matches char */
    if (len == 1) { 
      n->isWord = 1; /* last char, so set as word*/
      return;
    }
    else if (!n->child) { /* no child, add char */
      n->child = createNode(word[1]);
    }
    triePut(n->child, ++word, --len); /* try matching/adding next child char */
  } 
  else { /* no match, try siblings */
    if (!n->sibling) n->sibling = createNode(word[0]); /* no sibling, add char */
    triePut(n->sibling, word, len);/* try matching/adding next sibling char */
  }
}

/* internal function for traversing/finding characters */
int trieSearch(TNode *n, char *word, int len){
  printf(".");
  if (n->c == word[0]){ /* node matches char */
    if (len == 1){ 
      return n->isWord; /* word matches if last char is end of word */
    } /* check children for subsequent chars */
    else if (n->child) return trieSearch(n->child, ++word, --len);
    else return 0; /* word doesn't match as node has no children */
  } /* no match, check siblings for match */
  else if (n->sibling) return trieSearch(n->sibling, word, len);
  else return 0; /* word doesn't match as node has no siblings */
}

/* creates, initialises and returns a new trie struct*/
Trie *trie_create(){
  Trie *t = (Trie *) malloc(sizeof(Trie));
  t->child = NULL;
  t->size = 0;
  return t;
}

/* puts a new word into the supplied trie */
void trie_put(Trie *t, char *word, int len) {
  PRINTF("%s\n", word);
  if (t->child == NULL) t->child = createNode(word[0]);
  triePut(t->child, word, len);
  t->size += len * sizeof(Trie);
}

/* checks if a word exists in the supplied trie */
int trie_search(Trie *t, char *word, int len) {
  if (t) return trieSearch(t->child, word, len);
  else PRINTF("No trie passed\n");
  return 0;
}

/* returns the size of the supplied trie */
int trie_size(Trie *t){
  return t->size;
}