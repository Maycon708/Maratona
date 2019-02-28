#include <bits/stdc++.h>

#define INF 30
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef pair <ll, ll>  ii;

#define N 50005

vector<int> adj[N];
int g[N], p[N], used[N];

bool cmp( int a, int b ){
	return g[a] < g[b];
}

int main(){
	
	int n, m, u, v;
	while( scanf("%d%d", &n, &m ) != EOF && n ){
		rep( i, 0, n ) g[i] = used[i] = 0, adj[i].clear(), p[i] = i;
		if( !m ){
			puts("Y");
			continue;
		}
		while( m-- ){
			scanf("%d%d", &u, &v );
			u--; v--;
			adj[u].pb(v); adj[v].pb(u);
			g[u]++, g[v]++;
		} 
		sort( p, p+n, cmp );
		rep( i, 0, n ){
			u = p[i];
			if( !used[u] ){
				rep( j, 0, adj[u].size() ){
					int v = adj[u][j];
					g[v]--;
					used[v] = 1;
				}
			}
		}
		int cnt = 0, mn = n;
		rep( i, 0, n ){
			int u = p[i];
			if( used[u] ){
				cnt++;
				mn = min( mn, 1 + g[u] );
			}
		}
		printf("%s\n", (cnt==mn)? "Y" : "N");
	}
}
