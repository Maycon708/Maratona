#include <bits/stdc++.h>

#define rep(i, a, b) for(int i=a; i<b; i++)
#define INF 1e13

typedef long long int ll;
using namespace std;

int n, m;
ll custo[110][110];
ll tree[110];
ll pd[110][110][110];
int mem[110][110][110];

ll solve(int i, int k, int last){
	//cout << i << "  " << k << endl;
	if(k<0) return INF;
	if(i==n){
		if(k==0) return 0;
		return INF;
	}
	ll &p=pd[i][k][last];
	if(p!=-1) return p;
	
	ll ret=INF;
	if(tree[i]==last){
		ret=min(ret, solve(i+1, k, last));
	}
	else if(tree[i]==0){
		rep(j, 1, m+1){
			if(j==last){
				ret=min(ret, solve(i+1, k, j)+custo[i][j]);
			}
			else ret=min(ret, solve(i+1, k-1, j)+custo[i][j]);
		}
	}
	else{
		ret=min(ret, solve(i+1, k-1, tree[i]));
	}
	
	return p=ret;
}
int main(){
	
	int k;	
	while (cin >> n >> m >> k){
		for (int i=0; i < n; i++)
			cin >> tree[i];
		
		for (int i=0; i < n; i++)
			for (int j=1; j <= m; j++)
				cin >> custo[i][j];
				
		ll out=INF;
		memset(pd, -1, sizeof pd);
		if(tree[0]==0){
			rep(i, 1, m+1)
				out=min(out, solve(1, k-1, i)+custo[0][i]);
		}
		else out=solve(1, k-1, tree[0]);
		
		if(out>=INF) printf("-1\n");
		else printf("%lld\n", out);
			
	}	
	
	return 0;
}