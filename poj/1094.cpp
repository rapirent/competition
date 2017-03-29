#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int n,m;
    char input[10] = {0};
    int dag[30][30] = {0};
    int visited[30] = {0};
    while(scanf("%d%d",&n,&m)==2&&n&&m) {
        memset(dag,0,sizeof(dag));
        memset(visited,0,sizeof(visited));
        for(int a = 0;a<m;a++) {
            scanf("%s",input);
            dag[input[0] - 'A'][input[2] - 'A'] = 1;
            visited[input[0] - 'A'] = visited[input[2] - 'A'] = 1;
            //input1 -> input2  input2 is before from the input1
        }
        int count = 0;
        int source2,b,inconsist = 0,source = -1;
        for(int source2 = 0;source2<26;source2++) {
            b = 0;
            for(;b<26;b++) {
                if(dag[b][source2]) {
                    count++;
                    //b在a後, 有人連到a
                    break;
                }
            }
            if(b>=26 && visited[source2]) {
                if(source == -1) {
                    source = source2;
                    continue;
                }
                else {
                    inconsist = 1;
                    break;
                }
            }
        }
        if(m<(n-1)) {
            printf("Sorted sequence cannot be determined.\n");
            continue;
        }
        if(b>=26&&source<26&&source!=-1) {
            if(inconsist) {
                printf("Sorted sequence cannot be determined");
            }
            else {
                printf("Sorted sequence determined after %d relations: %c",count+1,source + 'A');// ABCD.
                for(int a = 0; a<26;a++) {
                    dag[source][a] = 0;
                }
                visited[source] = 0;
                int trav;
                while(1) {
                    for(source = 0; source<26;source++) {
                        for(trav = 0;trav<26;trav++) {
                            if(dag[trav][source]) {
                                break;
                            }
                        }
                        if(trav>=26&&visited[source]) {
                            break;
                        }
                    }
                    if(source>=26) {
                        break;
                    }
                    if(trav>=26&&source<26) {
                        printf("%c",source + 'A');
                    }
                    for(int a = 0;a<26;a++) {
                        dag[source][a] = 0;
                    }
                    visited[source] = 0;

                }
            }
        }
        else {
            printf("Inconsistency found after %d relations",count);
        }
        printf(".\n");
    }
    return 0;
}
