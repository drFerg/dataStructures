/* trie.h
 *
 * A simple Trie data structure.
 *
 * Author: Fergus Leahy
 */
#ifndef TRIE_H
#define TRIE_H

typedef struct trie Trie;

Trie *init_trie();
void put(Trie *t, char *word, int len);

int get(Trie *t, char *word, int len);

int size(Trie *t);

#endif /* TRIE_H */