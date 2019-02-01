#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdbool.h>

#define MAX_ALPHA 26
typedef struct {
    struct Trie *children[MAX_ALPHA];
    bool endnode;
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    Trie *newnode = (Trie *)malloc(sizeof(Trie));
    if (!newnode) {
        return NULL;
    }
    int i;
    for(i=0;i<MAX_ALPHA;i++)
    {
        newnode->children[i] = NULL;
    }
    newnode->endnode = false;
    return newnode;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word, int len) 
{
    Trie *root = obj;
    int i;
    for (i =0 ; i<len; i++)
    {
        int index = word[i]-'a';
        if (!root->children[index]) {
            root->children[index] = trieCreate();
        }
        root = root->children[index];
    }
    root->endnode = true;
}
int find_prefix(Trie *root) 
{
    int count = 0;
    int i;
    int index;
    int flag;
    while(root) {
        flag = 0;
        for (i =0 ;i < 26; i++)
        {
            if(root->children[i]) {
                if (!flag )
                {
                    flag =1;
                    index = i;
                }
                else{
                    return count;
                }
            }
        }
        root = root->children[index];
        count++;
    }
    return count;
}
    
char* longestCommonPrefix(char** strs, int strsSize) {
    int i;
    char *output;
    output = (char *)malloc(1000);
    Trie *t_iter = trieCreate();
    for (i=0;i<strsSize;i++) {
        trieInsert(t_iter, strs[i], strlen(strs[i]));
    }
    strncpy(output, strs[0], find_prefix(t_iter));
    return output;
}
