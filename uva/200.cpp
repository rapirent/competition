#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dag[26][26]={0};
int visited[26] ={0};
//int dag[26]={'\0'};
vector<char> answer;
int found_source(void)
{
    int test[26]={0};
    for(int a=0;a<26;a++) {
        if(dag[a][0]!=-1) {
            if(test[a] == 0 ){
                test[a] = 2;
            }
            for(int dag_trav = 0;dag_trav<dag[a].size();dag_trav++) {
                test[dag[a][dag_trav]] = 1;
            }
        }
    }
    for(int a=0;a<26;a++) {
        if(test[a]==2) {
            return a;
        }
    }
    return 27;
}
void DFS(int source)
{
    if(visited[source] == 1) {
        return;
    }
    visited[source] = 1;
    answer.push_back(source + 'A');
    if(dag[source][0] != -1) {
        for(int dag_trav = 0; dag_trav<dag[source].size();dag_trav++) {
            DFS(dag[source][dag_trav]);
        }
    }    
}

int main(void)
{
    char alphabet[10000][25] = {'\0'};
    int count = 0;
    int flag = 0;
    while(fgets(alphabet[count],20,stdin)!=0) {
        if(alphabet[count][0] != '#') {
            count++;
            continue;
        }
        //initialization
        memset(visited,0,sizeof(visited));
        memset(dag,-1,sizeof(dag[0][0])*26*26);
        for(int trav=0;trav<count-1;trav++) {
            for(int a = 0;a<min(strlen(alphabet[trav]),strlen(alphabet[trav+1]))-1;a++) {
                if(alphabet[trav][a]!=alphabet[trav+1][a]) {
                    dag[alphabet[trav][a]-'A'][alphabet[trav+1][a]-'A'] = 1;                    
                }
            }
        }
        //由index1指向index2，只要檢查index2有無被指向就好
        int not_source = 0;
        for(int trav = 0;trav<26;trav++) {
            for(int trav2 = 0; trav2<26;trav2++) {
                if(dag[trav2][trav]) {
                    not_source = 1;
                    
                    break;
                }
            }
            if(not_source == 0) {
                
                break;
            }
        }
        int start = found_source();
        DFS(start);
                
        printf("\n");
        memset(alphabet,0,sizeof(alphabet));
        count = 0;
    }
    return 0;
}
