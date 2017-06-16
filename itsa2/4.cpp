#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;



struct node {
    char eng;
    int shu;
    bool operator< (const node &a) const {
        return eng<a.eng;
    }
};

vector<struct node> set;
bool used[25] = {0};

char print[3];
int print_int[3];

void backtrack(int print_index,int select_index)
{
    if(print_index==3) {
        printf("%c %c %c\n",print[0],print[1],print[2]);
        return;
    }
    for(int i = select_index;i<set.size();i++) {
        if(!used[i]) {
            if(print_index==2) {
                if(print_int[0]+print_int[1]>set[i].shu&&print_int[0]+set[i].shu>print_int[1]
                        &&print_int[1]+set[i].shu>print_int[0]) {
                    used[i] = true;
                    print[print_index] = set[i].eng;
                    print_int[print_index] = set[i].shu;
                    backtrack(print_index+1,i);
                    used[i] = false;
                } 
            }
            else {
                used[i] = true;
                print[print_index] = set[i].eng;
                print_int[print_index] = set[i].shu;
                backtrack(print_index+1,i);
                used[i] = false;
            }
        }
    }

}


int main(void)
{
    int num;
    scanf("%d",&num);
    int n;
    struct node input;
    while(getchar()!='\n');
    while(num--){
        scanf("%d",&n);
        memset(used,0,sizeof(used));
        set.clear();
        memset(print,0,sizeof(print));
        while(getchar()!='\n');
        for(int i = 0;i<n;i++) {
            scanf("%c %d",&input.eng,&input.shu);
            while(getchar()!='\n');
            set.push_back(input);
        }
        sort(set.begin(),set.end());
        backtrack(0,0);
    }
    return 0;
}
