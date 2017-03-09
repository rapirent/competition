#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
    char input[1000];
    while(fgets(input,500,stdin)){
        printf("length = %d\n",strlen(input));
    }
    return 0;
}
