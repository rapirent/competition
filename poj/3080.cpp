#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int repeat;
    scanf("%d",&repeat);
    int row;
    char matrix[15][100] = {0};
    while(repeat-- > 0) {
        scanf("%d",&row);
        for(int i = 0;i<row;i++) {
                scanf("%s",matrix[i]);
        }
        char print_result[80] = {0};
        int count = 0;
//        int len = strlen(matrix[0]);
        for(int front = 0;front<60;front++) {
            for(int i = 60 - front - 1;i>=3;i--) {
                char tmp = matrix[0][front + i];
                matrix[0][front + i] = '\0';
                int j;
                for(j = 1;j<row;j++) {
                    if(strstr(matrix[j],matrix[0] + front) == NULL) {
                        //notfind
                        break;
                    }
                }
                if(j>=row&&i>count) {
                    count = i;
                    memset(print_result,0,sizeof(print_result));
                    memcpy(print_result,matrix[0] + front ,i);
                }
                matrix[0][front + i] = tmp;
            }
        }
        if(!count) {
            printf("no significant commonalities\n");
        }
        else {
            printf("%s\n",print_result);      
        }
    }
    return 0;
}
