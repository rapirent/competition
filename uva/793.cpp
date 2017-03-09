#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int dis_set[1000]={0};

void create(int x)
{
    for(int count=1;count<=x;count++){
        dis_set[count] = count;
    }
}

void union_gogo(int x, int y, int all)
{
    if(dis_set[x]==dis_set[y]){
        return;
    }
    int set_max = max(dis_set[x],dis_set[y]);
    int set_min = min(dis_set[x],dis_set[y]);
    for (int count = 1; count<=all;count++) {
        if (dis_set[count]==set_max){
            dis_set[count] = set_min;
        }
    }
}

int find_union(int x){
    return dis_set[x];    
}

int main(void)
{
    int total;
    scanf("%d",&total);
    int node_num;
    while(total-->0){   
    
        scanf("%d",&node_num);
        create(node_num);
        int correct,fail;
        correct=fail=0;
        char input[1000]={'\0'};
        char c;
        while((c=getchar())!='\n'&&c!=EOF);
        while(fgets(input,999,stdin)&&strlen(input)!=1){
            int num1,num2;
            char chargogo;
            sscanf(input,"%c %d %d",&chargogo,&num1,&num2);
            if(chargogo=='c'){
                union_gogo(num1,num2,node_num);
            }
            else if(chargogo=='q'){
                if(find_union(num1)==find_union(num2)){
                    correct++;                
                }
                else{
                    fail++;
                }
            }            
        }
        printf("%d,%d\n",correct,fail);
        if(total>0){
            printf("\n");
        }
    }
    return 0;
}
