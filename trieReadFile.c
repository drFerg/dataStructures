/* trieReadFile.c
 *
 * A simple program to test the Trie data structure using an input file.
 * Best used with /usr/share/dict/words as an input file.
 *
 * Author: Fergus Leahy
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "trie.h"
#define SSIZE 60
int main(int argc, char const *argv[])
{
    FILE *fp;
    char *line = NULL;
    size_t bufLen = 0;
    ssize_t read;
    char query[SSIZE];
    Trie *t = trie_create(t);
    printf("Trie initialisation %s\n",(t ? "succeeded": "failed"));

    fp = fopen(argv[1],"r");
    if (fp == NULL) exit(EXIT_FAILURE);
    while ((read = getline(&line, &bufLen, fp)) != -1) {
        line[read - 1] = '\0';
        //printf("Line: %s\n", line);
        //printf("Length: %zu\n", --read);
        trie_put(t, line, --read);
        //printf("%s\n", (get(t, line, read) ? "Found" : "Lost"));
    }

    while (1) {
        scanf("%s", query);
        printf("%zu: %s\n", strlen(query), (trie_search(t, query, strlen(query)) ? "found" : "not found"));
    }

}