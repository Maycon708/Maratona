#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define MAXN 200100
#define B 33

typedef unsigned long long H;

char s[MAXN];
vector<char> m[MAXN];
vector<H> ht[MAXN], hti[MAXN];
H pwr[MAXN];
int n,w,h;

void gen(int k) {
	ht[k].resize(m[k].size()+1);
	ht[k][0] = 0;
	hti[k].resize(m[k].size()+1);
	hti[k][0] = 0;
	pwr[0] = 1;
	for (int i = 0; i<m[k].size(); i++) {
		ht[k][i+1] = ht[k][i] * B + m[k][i];
		pwr[i+1] = pwr[i] * B;
	}
	for (int i = 0; i<m[k].size(); i++)
		hti[k][i+1] = hti[k][i] * B + m[k][m[k].size()-i-1];
}

H sect(int k, int a, int b) {
	if (a > b) return 0;
	return ht[k][b+1] - ht[k][a] * pwr[b - a + 1];
}

H secti(int k, int a, int b) {
	a=m[k].size()-a-1;
	b=m[k].size()-b-1;
	if (a > b) return 0;
	return hti[k][b+1] - hti[k][a] * pwr[b - a + 1];
}

int ipal(int k, int x) {
	int es = 1, di = min(min(x+1,2*w-x), (int)(m[k].size()/2+1)/2);
	di=min(di,n-k*w-x);
	
	while (es < di) {
		int me = (es+di+1)/2;
		if (secti(k, x, x-me+1) == sect(k, x, x+me-1)) es = me;
		else di = me-1;
	}
	return 2*es-1;
}

int ppal(int k, int x) {
	int es = 0, di = min(min(x,2*w-x), (int)m[k].size()/4);
	di=min(di,n-k*w-x);
	
	while (es < di) {
		int me = (es+di+1)/2;
		if (secti(k, x-1, x-me) == sect(k, x, x+me-1)) es = me;
		else di = me-1;
	}
	return 2*es;
}

int sh[MAXN], sp[MAXN];
int v[MAXN];

int histogram(int *v, int n) {
	int qs=1, curh=0;
	long long res=0;
	
	sh[0]=-1; sp[0]=0;
	v[n]=-1;
	
	for (int i=0; i<n+1; i++) {
		if (i<n && v[i]>=curh) {
			sh[qs]=v[i];
			sp[qs++]=i;
		}
		else {
			while (sh[qs-1]>v[i]) {
				qs--;
				res=max(res, (long long) sh[qs]*(i-sp[qs]));
			}
			sh[qs++]=v[i];
		}
		curh=v[i];
	}
	
	return res;
}

int main() {

	while (scanf("%d%d",&n,&w)==2 && n+w) {
		memset(s,0,sizeof(s));
		scanf(" %s",s);
		
		h=(n+w-1)/w;
		
		REP(i,h) {
			m[i].resize(2*w);
			REP(j,2*w)
				m[i][j]=s[i*w+j];
			gen(i);
		}
		
		int res=0;
		REP(j,2*w) {
			REP(i,h)
				v[i] = ipal(i,j);
			res = max(res, histogram(v, h));
			REP(i,h)
				v[i] = ppal(i,j);
			res = max(res, histogram(v, h));
		}
		
		printf("%d\n",res);
	}
	
	return 0;
}
