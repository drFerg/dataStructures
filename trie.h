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
Trie *trie_create();

/* puts a new word of size len into the supplied trie */
void trie_put(Trie *t, char *word, int len);

/* checks if a word exists in the supplied trie */
int trie_search(Trie *t, char *word, int len);

/* returns the size of the supplied trie */
int trie_size(Trie *t);

#endif /* TRIE_H */