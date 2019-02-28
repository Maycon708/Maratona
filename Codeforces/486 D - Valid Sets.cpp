#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

const int mod = 1e9+7;
const int N = 2018;

vector<int> adj[N];
ll a[N], ans[N], d, aux;

void dfs( int u, int p = -1 ){
	ans[u] = 1;
	for( auto v : adj[u] ){
		if( v == p || a[v] > a[aux] || a[v] < a[aux]-d || a[v] == a[aux] && v < aux  ) continue;
		dfs(v, u);
		ans[u] = ( ans[u] * (ans[v]+1) )%mod;
	}
}

int main(){
	int n, u, v;
	cin >> d >> n;
	rep( i, 1, n+1 ) scanf("%d", &a[i] );
	rep( i, 1, n ){
		scanf("%d%d", &u, &v );
		adj[u].pb(v);
		adj[v].pb(u); 
	}
	ll resp = 0;
	rep( i, 1, n+1 ){ 
		aux = i;
		dfs(i);
		resp = ( resp + ans[i] )%mod;
	}
	cout << resp << "\n";
}

