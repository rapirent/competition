
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
#define maxn 1300
#define mod 100000000

class bn{
    int a
}

struct bignumber
{
        int n;
        int a[maxn];
        void clear()
        { n=0; memset(a,0,sizeof(a)); }
         void init(char *s)
        {
                clear();
            int len=strlen(s);
            for(int i=0;i<len;i++)
            {
                int num=(len+7-i)/8;
                a[num]=a[num]*10+(s[i]-'0');
            }
            n=(len+7)/8;
        }
        void output()
        {
            printf("%d",a[n]);for(int i=n-1;i>=1;i--) printf("%08d",a[i]); printf("\n"); }
        bool operator < (const bignumber b) const
        {
                if(n<b.n) return 1; if(n>b.n) return 0;
                for(int i=n;i>0;i--)
                { if(a[i]<b.a[i]) return 1; if(a[i]>b.a[i]) return 0; }
                return 0;
        }
        bool operator == (const bignumber b) const
        {
                if(n!=b.n) return 0;
                for(int i=n;i>0;i--) if(a[i]!=b.a[i]) return 0;
                return 1;
        }
        bool operator <= (const bignumber b) const//>返回0，<返回2，=返回1
        {
                if(n<b.n) return 1;
                if(n>b.n) return 0;
                for(int i=n;i>0;--i)
                {
                        if(a[i]>b.a[i]) return 0;
                        if(a[i]<b.a[i]) return 1;
                }
                return 1;
        }
        string content() {
            string str;
	        for (int i=n;i>=1;i--) {
		        str += to_string(a[i]);
            }
            return str;
        }
        bignumber div(bignumber a, bignumber b)
        {
            int norm=base/(b.back()+1);
                bigN x=abs()*norm;
		bigN y=b.abs()*norm;
		bigN q,r;
		q.resize(x.size());
		for(int i=int(x.size())-1;i>=0;--i){
			r=r*base+x[i];
			int s1=r.size()<=y.size()?0:r[y.size()];
			int s2=r.size()<y.size()?0:r[y.size()-1];
			int d=(LL(base)*s1+s2)/y.back();
			r=r-y*d;
			while(r.negative)r=r+y,--d;
			q[i]=d;
		}
		q.negative=negative!=b.negative;
		return q.trim(),q;
        }

};
bignumber operator + (bignumber a,bignumber b)
{
        a.n=max(a.n,b.n);
        for(int i=1;i<=a.n;i++)
        {
                a.a[i]+=b.a[i];
                a.a[i+1]+=a.a[i]/mod;
                for(;a.a[i]>=mod;a.a[i]-=mod);
        }
        if(a.a[a.n+1]>0) a.n++;
        return a;
}
bignumber operator - (bignumber a,bignumber b)
{
        for(int i=1;i<=a.n;i++)
        {
                a.a[i]-=b.a[i];
                if(a.a[i]<0) { a.a[i+1]--; a.a[i]+=mod; }
        }
        while (a.a[a.n]==0 && a.n>1) a.n--;
        return a;
}
bignumber operator * (bignumber a,int b)
{
        for(int i=1;i<=a.n;i++)
        { a.a[i]=a.a[i]*b+a.a[i-1]/mod; for(;a.a[i-1]>=mod;a.a[i-1]-=mod); }
        while (a.a[a.n]>=mod)
        { a.n++; a.a[a.n]=a.a[a.n-1]/mod; for(;a.a[a.n-1]>=mod;a.a[a.n-1]-=mod); }
        return a;
}

bignumber operator / (bignumber a,int b)
{
        int tmp=0;
        for(int i=a.n;i>0;i--)
        {
            tmp=tmp*mod+a.a[i]; a.a[i]=tmp/b;
            tmp%=b;
        }
        while (a.a[a.n]==0 && a.n>1) a.n--;
        return a;
}

bignumber gcd(bignumber a,bignumber b)
{
        int ans=0;
        bignumber c;
        while (1)
        {
                if(a.n==1 && a.a[1]==0) { c=b; break; }
                if(b.n==1 && b.a[1]==0) { c=a; break; }
                int flag=0;
                if(a.a[1]%2==0) a=a/2,flag++;
                if(b.a[1]%2==0) b=b/2,flag++;
                if(flag==2) ans++;
                if(! flag)
                if(a<b) b=b-a;
                else a=a-b;
        }
        while (ans--) c=c*2;
        return c;
}

vector<struct bignumber> number_set;
vector<struct bignumber> ciphertext;
map<string, struct bignumber> num_map;
map<string, struct bignumber>::iterator iter;
map<struct bignumber, int> plain_map;

int main()
{
    int t;
    scanf("%d",&t);
    int N, L;
    char input[1000000];
    bignumber a1,b1,c1;
    for (int i = 1; i<=t; i++) {
        printf("Case #%d: ",i);
        num_map.clear();
        number_set.clear();
        ciphertext.clear();
        scanf("%d %d",&N,&L);
        scanf("%s",input);
        a1.init(input);
        for (int j = 0; j<L-1;j++) {
            scanf("%s",input);
            b1.init(input);
            c1 = gcd(a1,b1);
            string data = c1.content();
            if((iter = num_map.find(data))==num_map.end()) {
                num_map.insert(pair<string, struct bignumber>(data,c1));
                number_set.push_back(c1);
            }
            if(j==0) {
                ciphertext.push_back(c1/a1);
            }
            ciphertext.push_back(c1);
            if(j==L-2) {
                ciphertext.push_back(c1/b1);
            }
            a1.init(input);
        }
        sort(number_set.begin(),number_set.end());
        int k=0;
        for(vector<struct bignumber>::iterator it = number_set.begin() ;it!=number_set.end() ;it++) {
            plain_map.insert(pair<struct bignumber, int>(*it, k++));
        }
        printf("k=%d\n",k);
        for(vector<struct bignumber>::iterator it = ciphertext.begin() ;it!=ciphertext.end() ;it++) {
            // (*it).output();
            printf("%c",plain_map[*it] + 'A');
        }
        printf("\n");
    }
    return 0;
}
