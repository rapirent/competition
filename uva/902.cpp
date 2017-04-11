#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct node{
    int word_count;
    int link[26];
};

int max_count = 0;

void trav(int index,char memory[],int n, node trie[], int trie_size, char print_str[])
{
    if(trie[index].word_count > max_count) {
        max_count = trie[index].word_count;
        memcpy(print_str,memory,sizeof(char)*n);
        return;
    }
    for(int i = 0;i<26;i++) {
        if(trie[index].link[i] != 0 && trie[index].link[i]<= trie_size) {
            memory[n] = i + 'a';
            trav(trie[index].link[i],memory,n+1,trie,trie_size,print_str);
        }
    }
}


int main(void)
{
    int len;
    char discard,input[1000000]={'\0'};
    node trie[2000000];
    while(scanf("%d %s",&len,input)!=EOF) {
        memset(trie,0,sizeof(trie));
        int len_input = strlen(input);
        int cur = 0;
        int trie_size = 0;
        for(int i = 0;i<len_input;i++) {
            cur = 0;
            for(int j = 0;j<len;j++) {
                if(trie[cur].link[input[i+j] - 'a'] == 0) {
                    //有存過
                    trie_size++;
                    trie[cur].link[input[i+j] - 'a'] = trie_size;
                }
                cur = trie[cur].link[input[i+j] - 'a'];
            }
            trie[cur].word_count++;
        }
        char print_str[30] = {0};
        char memory_str[30] = {0};
        max_count = 0;
        trav(0,memory_str,0,trie,trie_size,print_str);
        printf("%s\n",print_str);
    }
    return 0;
}
