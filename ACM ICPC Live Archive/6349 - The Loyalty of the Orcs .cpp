#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

#define N 100100

vector<int> adj[N];
ll d[N], cnt[N];

void dfs( int u, int p, ll c ){
	cnt[u] += c;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == p ) continue;
		dfs( v, u, c + d[u] );
	}
}

int main(){
	int t, n, m, u, v;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		rep( i, 0, n+1 ) d[i] = 0,  cnt[i] = 1, adj[i].clear();
		rep( i, 1, n ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
		}
		scanf("%d", &m );
		while( m-- ){
			scanf("%d", &u );
			d[u] = 1;
		}
		dfs(1, -1, 0);
		long double ans = 0;
		rep( i, 1, n+1 ){
			ans += ( 1.0L - 1.0L/cnt[i] );
		}
		printf("%.10LF\n", ans );
	}
}
