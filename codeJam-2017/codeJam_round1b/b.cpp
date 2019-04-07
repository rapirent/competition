#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;



void backtracking(int total,int hair_num[],int now,int result[])
{
    if(now>total) {
        
        return;
    }
    int left = hair_num[now - 1];
    int isRight = now==left?1:0;
    int right = hair_num[now + 1];
    for(int i = 0;i<5;i++) {
        if(hair_num[i]>0) {
            if(i%2==0){
                //單色
                if(isRight) {
                    if(left!=i&&right!=i) {
                        hair_num[i]--;
                        result[now] = i;
                        backtracking(total,hair_num,now+1,result);
                        hair_num[i]++;
                    }
                }
                else {
                    if(left!=i) {
                        hair_num[i]--;
                        result[now] = i;
                        backtracking(total,hair_num,now+1,result);
                        hair_num[i]++;
                    }
                }
                
            }
            else {
                if(isRight) {
                    if(left!=i+1&&left!=i-1&&right!=i+1&&right!=i-1) {
                        hair_num[i]--;
                        result[now] = i;
                        backtracking(total,hair_num,now+1,result);
                        hair_num[i]++;
                    }
                }
                else {
                    if(left!=i+1||left!=i-1) {
                        hair_num[i]--;
                        result[now] = i;
                        backtracking(total,hair_num,now+1,result);
                        hair_num[i]++;
                    }
                }
            }
        }
    }
    
}


int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    while(repeat--) {
        int num;
        scanf("%d",&num);
        int hair_num[7];
        scanf("%d %d %d %d %d %d",&hair_num[0],&hair_num[1],&hair_num[2],&hair_num[3],&hair_num[4],&hair_num[5]);
        int result[10000];
        memset(result,-1,sizeof(result));
        for(int i = 0;i<=5;i++) {
            if(hair_num[i]>0) {
                hair_num[i]--;
                result[0] = i;     
            }
        }     
           
        backtracking(num,hair_num,1,result);
        for(int i = 0;i<num;i++) {
            switch(hair_num[i]) {
                case 0:
                    printf("R");
                    break;
                case 1:
                    printf("O");
                    break;
                case 2:
                    printf("Y");
                    break;
                case 3:
                    printf("G");
                    break;
                case 4:
                    printf("B");
                    break;
                case 5:
                    printf("V");
                    break;
            }
        }
        printf("\n");
    }
    return 0;
}
