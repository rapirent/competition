#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(NULL));
	int prime[26] = {109, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
   	string s = "ABABBAGHCDEFGHIJKLMLMLMLMNOPQRSTUVWXYZYZYZYZ";
                //   ABABABABCDEFGHIJKLMLMLMLMNOPQRSTUVWXYZYZYZYZ
	printf("1000\n");
	for(int ca=0; ca<1001; ++ca){
		printf("200 43\n");
		s = "";
        s += "ABABABABCDEFGHIJKLMLMLMLMNOPQRSTUVWXYZYZYZYZ";
		for(int i=1; i<s.size(); ++i){
			printf("%d ", prime[s[i]-'A']*prime[s[i-1]-'A']);
		}
		printf("\n");
	}
	return 0;
}
