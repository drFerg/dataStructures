/* trieTest.c
 *
 * A simple program to test the Trie data structure.
 *
 * Author: Fergus Leahy
 */
#include <stdio.h>
#include "trie.h"

int main(int argc, char const *argv[])
{
    Trie *t = trie_create(t);
    printf("Trie initialisation %s\n",(t ? "succeeded": "failed"));
    trie_put(t, "fergus", 6);
    trie_put(t, "fergul", 6);
    trie_put(t, "ferguz", 6);
    trie_put(t, "fergal", 6);
    int suc = trie_search(t, "fergus", 6);
    printf("fergus %d\n", suc);
    suc = trie_search(t, "fergul", 6);
    printf("fergul %d\n", suc);
    suc = trie_search(t, "ferguz", 6);
    printf("ferguz %d\n", suc);
    suc = trie_search(t, "fergal", 6);
    printf("fergal %d\n", suc);
    return 0;
}