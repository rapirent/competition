#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct bignumber{
	int len;
	int num[200];

	void clear(){
		len = 0;
		memset(num, 0, sizeof(num));
	}

	void init(char *s){
		len=strlen(s);
		for(int i=0; i<len; ++i)
			num[i] = s[len-1-i]-'0';
	}

	void print() const{
		for(int i=len-1; i>=0; --i)
			printf("%d", num[i]);
		printf("\n");
	}

	bool operator < (bignumber b) const{
		if(len < b.len)	return true;
		if(len > b.len)	return false;
		for(int i=len-1; i>=0; --i){
			if(num[i] < b.num[i])	return true;
			if(num[i] > b.num[i])	return false;
		}
		return false;
	}

	bool operator <= (bignumber b){
		if(len < b.len)	return true;
		if(len > b.len)	return false;
		for(int i=len-1; i>=0; --i){
			if(num[i] < b.num[i])	return true;
			if(num[i] > b.num[i])	return false;
		}
		return true;
	}

	bool operator == (bignumber b){
		if(len < b.len)	return false;
		if(len > b.len)	return false;
		for(int i=len-1; i>=0; --i){
			if(num[i] < b.num[i])	return false;
			if(num[i] > b.num[i])	return false;
		}
		return true;
	}

	bignumber operator = (bignumber b){
		len = b.len;
		for(int i=0; i<len; ++i)
			num[i] = b.num[i];
		return b;
	}
};

bignumber operator - (bignumber a, bignumber b){
	for(int i=0; i<a.len && i<b.len; ++i){
		a.num[i] -= b.num[i];
		if(a.num[i] < 0){
			--a.num[i+1];
			a.num[i] += 10;
		}
	}
	while(a.len > 0 && a.num[a.len-1] == 0)
		--a.len;
	return a;
}

bignumber operator * (bignumber a, bignumber b){
	bignumber c;
	c.clear();
	for(int i=0; i<a.len; ++i)
		for(int j=0; j<b.len; ++j)
			c.num[i+j] += a.num[i]*b.num[j];
	c.len = a.len+b.len-1;
	for(int i=0; i<c.len; ++i)
		if(c.num[i] > 9){
			c.num[i+1] += c.num[i]/10;
			c.num[i] %= 10;
		}
	if(c.num[c.len] > 0)
		++c.len;
	return c;
}

bignumber operator * (bignumber a, int b){
	a.num[0] *= b;
	for(int i=1; i<a.len; ++i){
		a.num[i] *= b;
		if(a.num[i-1] > 9){
			a.num[i] += a.num[i-1]/10;
			a.num[i-1] %= 10;
		}
	}
	if(a.num[a.len-1] > 9){
		a.num[a.len] = a.num[a.len-1]/10;
		a.num[a.len-1] %= 10;
		++a.len;
	}
	return a;
}

bignumber pow_ten(bignumber a, int p){
	if(p <= 0)
		return a;
	for(int i=a.len-1; i>=0; --i)
		a.num[i+p] = a.num[i];
	a.len += p;
	for(int i=0; i<p; ++i)
		a.num[i] = 0;
	return a;
}

bignumber operator / (bignumber a, bignumber b){
	bignumber c;
	bignumber d;
	c.clear();
	bool flag = true;
	while(a.len > 0){
		int n;
		if(a.num[a.len-1] > b.num[b.len-1])
			n = a.len-b.len;
		else if(a.num[a.len-1] <= b.num[b.len-1])
			n = a.len-b.len-1;
		if(n <= 0)
			n = 0;
		d = pow_ten(b, n);
		while(d <= a){
			a = a-d;
			++c.num[n];
			if(flag){
				flag = false;
				c.len = n+1;
			}
		}
	}
	while(c.len > 0 && c.num[c.len-1]==0)
		--c.len;
	for(int i=0; i<c.len; ++i){
		if(c.num[i] > 9){
			c.num[i+1] += c.num[i]/10;
			c.num[i] %= 10;
		}
	}
	if(c.num[c.len])
		++c.len;
	return c;
}

bignumber gcd(bignumber a, bignumber b){
	bignumber c;
	while(true){
		if(a.len==0) return b;
		if(b.len==0) return a;
		int n;
		if(b < a){
			if(a.num[a.len-1] > b.num[b.len-1])
				n = a.len-b.len;
			else
				n = a.len-b.len-1;
			c = pow_ten(b, n);
			while(c <= a){
				a = a-c;
			}
		}
		else{
			if(b.num[b.len-1] > a.num[a.len-1])
				n = b.len-a.len;
			else
				n = b.len-a.len-1;
			c = pow_ten(a, n);
			while(c <= b){
				b = b-c;
			}
		}
	}
}

int main(){
	int T;
	int N, L;
	char x[200][200];
	bool is_gcd[200];
	map<bignumber, char> m;
	vector<bignumber> sort_v;
	vector<bignumber> v;
	bignumber a, b, c;
	scanf("%d", &T);
	for(int ca=1; ca<=T; ++ca){
		m.clear();
		v.clear();
		sort_v.clear();
		memset(is_gcd, false, sizeof(is_gcd));
		scanf("%d %d", &N, &L);
		scanf("%s", x[0]);
		for(int i=1; i<L; ++i){
			scanf("%s", x[i]);
			a.init(x[i-1]);
			b.init(x[i]);
			c = gcd(a, b);
			if(c == a){
				if(i==1)
					v.push_back(c);
				v.push_back(c);
			}
			else{
				if(i==1){
					v.push_back(a/c);
					m[v[0]] = '0';
					is_gcd[0] = true;
				}
				v.push_back(c);
				m[v[i]] = '0';
				is_gcd[i] = true;
			}
		}
		v.push_back(b/c);
		if(v[v.size()-1].len!=1 || v[v.size()-1].num[0]!=1){
			m[v[v.size()-1]] = '0';
			is_gcd[v.size()-1] = true;
		}
		for(int i=0; i<v.size()-1; ++i){
			if(is_gcd[i] && !is_gcd[i+1]){
				a.init(x[i]);
				v[i+1] = a/v[i];
				m[v[i+1]] = '0';
				is_gcd[i+1] = true;
			}
		}
		for(int i=v.size()-1; i>0; --i){
			if(is_gcd[i] && !is_gcd[i-1]){
				a.init(x[i-1]);
				v[i-1] = a/v[i];
				m[v[i-1]] = '0';
				is_gcd[i-1] = true;
			}
		}
		for(map<bignumber, char>::iterator it=m.begin(); it!=m.end(); ++it)
			sort_v.push_back(it->first);
		sort(sort_v.begin(), sort_v.end());
		for(int i=0; i<sort_v.size(); ++i)
			m[sort_v[i]] = 'A'+i;

		printf("Case #%d: ", ca);
		for(int i=0; i<v.size(); ++i)
			printf("%c", m[v[i]]);
		printf("\n");
	}
	return 0;
}
