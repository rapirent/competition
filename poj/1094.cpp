#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

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
        int source2,b,inconsist = 0,source = -1;
        int cycle = 0,cycle_count;
        for(int source2 = 0;source2<26;source2++) {
            b = 0;
            for(;b<26;b++) {
                if(dag[b][source2]) {
                    //b在a後, 有人連到a
                    cycle_count = 0;
                    for(int test = 0,test2 = source2;test<26;test++) {
                        if(dag[test2][test]) {
                            cycle_count ++;
                            if(test == source2) {
                                cycle = 1;
                                break;
                            }
                            test2 = test;
                            test = 0;
                        }
                        
                    }
                    break;
                }
            }
            if(cycle) {
                break;
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
        vector<char> vec;
        int count = 0;
        if(cycle) {
            printf("Inconsistency found after %d relations.\n",cycle_count);
            continue;
        }
        if(b>=26&&source<26&&source!=-1) {
            if(inconsist) {
                printf("Sorted sequence cannot be determined.\n");
            }
            else {
                vec.push_back(source + 'A');
                count++;
                //printf("Sorted sequence determined after %d relations: %c",,source + 'A');// ABCD.
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
                        vec.push_back(source + 'A');
                        //printf("%c",source + 'A');
                        count++;
                    }
                    for(int a = 0;a<26;a++) {
                        dag[source][a] = 0;
                    }
                    visited[source] = 0;
                }
                printf("Sorted sequence determined after %d relations: ",count);// ABCD.
                for(int a = 0;a<vec.size();a++) {
                    printf("%c",vec[a]);
                }
                printf(".\n");
            }
        }
        else {
            printf("Sorted sequence cannot be determined.\n");
        }
    }
    return 0;
}
