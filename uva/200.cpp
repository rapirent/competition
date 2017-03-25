#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dag[26][26]={0};
int visited[26] ={0};
//int dag[26]={'\0'};

int main(void)
{
    char alphabet[10000][25] = {'\0'};
    int count = 0;
    int flag = 0;
    while(fgets(alphabet[count],21,stdin)!=0) {
        if(alphabet[count][0] != '#') {
            count++;
            continue;
        }
        else {
            break;
        }
    }
    //initialization
    memset(visited,0,sizeof(visited));
    memset(dag,-1,sizeof(dag[0][0])*26*26);
    for(int trav=0;trav<count-1;trav++) {
        for(int a = 0;a<min(strlen(alphabet[trav])-1,strlen(alphabet[trav+1])-1);a++) {
            if(alphabet[trav][a]!=alphabet[trav+1][a]) {
                dag[alphabet[trav][a]-'A'][alphabet[trav+1][a]-'A'] = 1;
                visited[alphabet[trav][a] - 'A'] = visited[alphabet[trav+1][a] - 'A'] = 1;
                break;
            }
        }
    }
    //由index1指向index2，只要檢查index2有無被指向就好
    //每次只要搜尋當前的source並印出就好啦!!!!!
    int not_source = 0;
    int trav, trav2 = 0;
    while(1) {
        for(trav = 0;trav<26;trav++) {
            not_source = 0;
            for(trav2 = 0; trav2<26;trav2++) {
                if(dag[trav2][trav]!=-1) {
                    break;
                }
            }
            if(trav2>=26&&visited[trav]==1) {
                break;
            }
        }
        if(trav>=26) {
            break;
        }
        visited[trav] = 0;
        printf("%c",trav + 'A');
        for(int a = 0;a<26;a++) {
            dag[trav][a] = -1;
        }
    }
    if(count == 1 ) {
        printf("%c",alphabet[0][0]);
    }
    printf("\n");
    return 0;
}
