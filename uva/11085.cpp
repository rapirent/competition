#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

struct node{
    int solution[8];
};

int solution[8]={0};
int count=0;
int test[3][17] = {0};


//記住, 一定要用vector來存, 而非以全域變數搭配陣列
vector<node> solution_vector;
void search(int x)
{
    if(x==8) {
        node tmp; 
        for(int a=0;a<8;a++) {
            tmp.solution[a] = solution[a] + 1;
        }
        solution_vector.push_back(tmp);
        return;
    }
    for(int y = 0;y<8;y++) {
        if(!test[0][y] && !test[1][x+y] && !test[2][x-y+8]) {
            solution[x] = y;
            test[0][y] = test[1][x+y] = test[2][x-y+8] = 1;
            search(x+1);
            test[0][y] = test[1][x+y] = test[2][x-y+8] = 0;
        }
    }
}


int main(void)
{
    search(0);
    int input[8];
    int case_num = 1;
    while(scanf("%d %d %d %d %d %d %d %d",&input[0],&input[1],&input[2],&input[3]
                                        ,&input[4],&input[5],&input[6],&input[7])==8) {
        int sum = 100;
        for(int count_trav = 0; count_trav <= solution_vector.size() ; count_trav++) {
            int tmp = 0;
            for(int x = 0;x<8;x++) {
                if(input[x]!=solution_vector[count_trav].solution[x] ) {
                    tmp++;
                }
            }
            if(tmp<sum) {
                sum = tmp;
            }
        }
        printf("Case %d: %d\n",case_num++,sum);
    }   
    return 0; 
}

