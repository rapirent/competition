/**********ALLAH IS ALMIGHTY************/


/**
 uva online judge
 problem name :: longest match ; 
 problem id   :: 10100; 
 catagory     :: dynamic_programming , lcs , string ;
     don't use (conio.h) header this causes compilation error;
 my_solution .................
**/

#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <fstream>
#include <utility>
#include <cassert>
#include <ctime>
#include <climits>
#include <functional>
#include <numeric>
#include <memory.h>

using namespace std;

string fs , ls;
vector < string > vv;
vector < string > vvv;
int dp[1000][1000];

int lcs (int i , int j) {
    if (i >= vv.size() || j >= vvv.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (vv[i] == vvv[j])
        ans = max (ans , 1 + lcs (i + 1 , j + 1));
    ans = max (ans , lcs (i + 1 , j));
    ans = max (ans , lcs (i , j + 1));
    return dp[i][j] = ans;

}

int main () {
    int cs = 0;
    while (getline (cin , fs)) {
        vv.clear();
        vvv.clear();
        getline (cin , ls);
        printf ("%2d. " , ++cs);
        for (int i = 0; i < fs.size(); i++) {
            if (!islower(fs[i]) && !isupper(fs[i]) && !isdigit(fs[i])) {
                fs[i] = ' ';
            }
        }
        for (int i = 0; i < ls.size(); i++) {
            if (!islower(ls[i]) && !isupper(ls[i]) && !isdigit(ls[i])) {
                ls[i] = ' ';
            }
        }
        string ss , sss;
        istringstream ssss (fs);
        istringstream sssss (ls);
        while (ssss >> ss) vv.push_back(ss);
        while (sssss >> sss) vvv.push_back(sss);
        if (vv.size() == 0 || vvv.size() == 0) {
            cout << "Blank!" << endl;
            continue;
        }
        memset (dp , -1 , sizeof (dp));
        printf ("Length of longest match: %d\n" , lcs (0 , 0));
        fs.clear();
        ls.clear();
        sss.clear();
        ssss.clear();
        sssss.clear();
    }
}
