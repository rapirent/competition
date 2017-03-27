#include <iostream>  
#include <cstdlib>  
#include <cstring>  
#include <cstdio>  
  
using namespace std;  
  
int F[10220];  
int c[115],w[115];  
  
int main()  
{  
    int m,n;  
    while (~scanf("%d%d",&m,&n)) {  
        for (int i = 1 ; i <= n ; ++ i)  
            scanf("%d%d",&c[i],&w[i]);  
          
        memset(F, 0, sizeof(F));  
        if (m > 1800) m += 200;  
        for (int i = 1 ; i <= n ; ++ i)   
            for (int j = m ; j >= c[i] ; -- j)  
                if (F[j] < F[j-c[i]]+w[i])  
                    F[j] = F[j-c[i]]+w[i];  
          
        int f = m;  
        while (f > 0 && F[f] == F[f-1]) -- f;  
        if (f <= 2000 && m > 2000)  
            printf("%d\n",F[m-200]);  
        else printf("%d\n",F[m]);  
    }  
    return 0;  
}  
