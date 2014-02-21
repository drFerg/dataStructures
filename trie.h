/* trie.h
 *
 * A simple Trie data structure.
 *
 * Author: Fergus Leahy
 */
#ifndef TRIE_H
#define TRIE_H

/* opaque data structure for trie */
typedef struct trie Trie;

/* creates, initialises and returns a new trie struct*/
Trie *init_trie();

/* puts a new word of size len into the supplied trie */
void put(Trie *t, char *word, int len);

/* checks if a word exists in the supplied trie */
int get(Trie *t, char *word, int len);

/* returns the size of the supplied trie */
int size(Trie *t);

#endif /* TRIE_H */