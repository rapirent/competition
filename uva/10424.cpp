#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;
int main(void){
    string a,b;
    int count,number1,number2;
    
    while(getline(cin, a)){
        getline(cin, b);
        number1=number2=0;
        for(count=number1=0;count<a.length();count++){
            if(isalpha(a[count])){
                number1 += tolower(a[count]) - (int)'a' + 1;
            }
        }
        while(number1>=10){
            number1 = number1/10 + number1%10;
        }
        for(count=number2=0;count<b.length();count++){
            if(isalpha(b[count])){
                number2 += tolower(b[count]) - (int)'a' + 1;
            }
        }
        while(number2>=10){
            number2 = number2/10 + number2%10;
        }
        double ans = number1<number2?(double)number1*100/(double)number2:(double)number2*100/(double)number1;
        printf("%.2lf %%\n",ans);
    }

    return 0;    
}
