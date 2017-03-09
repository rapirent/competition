#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    map<string, int> M;
    int total_line;
    scanf("%d",&total_line);
    char c;
    while((c = getchar()) != '\n' && c != EOF)
		/* discard */ ;
    char input[100]={'\0'};
    for (int count_input=0;count_input<total_line;count_input++){
        fgets(input,99,stdin);
        char *city = strtok(input ," ");
        if (M.count(city)==0){
            M[city] = 1;
        }
        else {
            M[city] ++;
        }
    }
    for (map<string,int>::iterator iter = M.begin();iter != M.end();iter++){  
        cout << iter->first << " " << iter-> second << endl;
    }  
    return 0;
}
