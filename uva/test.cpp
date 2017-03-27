#include<iostream>
#include<vector>
#include<cstring>
#define SIZE 999999+1
using namespace std;
/*
 * AUTHOR : liuchialun
 * DATE   : 2012/3/1
 * PROBLEM: given many kinds of food and their prices
 *          we have coupon to use, suppose we are going to order some
 *          food, find the minimal price.
 * SOLUTION: dp ( top- down) 
 *           transform an order to a number like 1 2 3 4 -> 1234
 *           the rest is trivial
 */
int dp[SIZE];
struct data
{
    data(){}
    data(int a,int b):v(a),p(b){}
    int v; // kinds 
    int p; // price
};
int recur(int n,const vector<data> & v);
int main()
{
    int num;
    while(cin>>num)
    {
        int item[num];
        int t=1,s;
        vector<data> v;
        for(int i = 1 ;i < num ; i++)t*=10;
        for(int i = 0 ;i < num ; i++)
        {
            cin>>item[i];
            v.push_back(data(t,item[i]) );
            t/=10;
        }
        int combo;
        cin>>combo;
        for(int i = 0 ;i < combo ;i++)
        {
            s = 0;
            for(int j = 0 ;j < num ; j++)
            {
                
                cin>>t;
                s = s*10+t;
            }
            cin>>t;
            v.push_back(data(s,t) );
        }
        
        // initialize the dp array
        memset(dp,false,sizeof(dp));
        
        int q;
        cin>>q;
        for(int i = 0 ;i < q ; i++)
        {
            s= 0 ;
            for(int j = 0 ;j < num ; j++)
            {
                cin>>t;
                s=s*10+t;
            }
            cout<<recur(s,v)<<endl;
        }
        
        
    }
    return 0;
}
int recur(int n,const vector<data> & v)
{
    int mi,t;
    if(dp[n] || n==0)
    {
        return dp[n];
    }
    else
    {
        mi = 1e9;
        for(int i = 0 ;i < v.size() ; i++)
        {
            t = n-v[i].v;
                if(t>=0)
            mi = min(mi,recur(t,v)+v[i].p);
        }
    }
    dp[n] = mi;
    return  dp[n];
}  
