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
    Trie *t = init_trie(t);
    printf("Trie initialisation %s\n",(t ? "succeeded": "failed"));
    put(t, "fergus", 6);
    put(t, "fergul", 6);
    put(t, "fergal", 6);
    int suc = search(t, "fergus", 6);
    printf("fergus %d\n", suc);
    suc = search(t, "fergul", 6);
    printf("fergul %d\n", suc);
    suc = search(t, "fergal", 6);
    printf("fergal %d\n", suc);
    return 0;
}