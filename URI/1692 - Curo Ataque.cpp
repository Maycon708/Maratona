#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int can[1010], n, k, a, b;
vector<int> adj[1010];

bool bfs( int f, int p, int k, int &cnt ){
	queue<ii> q;
	int u = f;
	q.push(ii(u, 0));
	int vis[1010], c;
	rep( i, 0, n+1 ) vis[i] = 0;
	vis[p] = vis[u] = 1; cnt = 0;
	while( !q.empty() ){
		u = q.front().F;
		c = q.front().S;
		q.pop();
		cnt++;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			if( !vis[v] && c+1 <= k && v != p){
				vis[v] = 1;
				q.push(ii(v, c+1)); 
			}
		}
	}
	
	return c == k;
}

int main(){
	
	int x[1010], y[1010];
	
	while( scanf("%d%d", &n, &k ) != EOF ){
		rep( i, 0, n+1 ){
			adj[i].clear();
		}
		rep( i, 1, n ){
			scanf("%d%d", &a, &b );
			x[i] = a, y[i] = b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		int ans = -INF;
		rep( i, 1, n ){
			int a, b;
			if( bfs(x[i], y[i], (k-1)/2, a) && bfs(y[i], x[i], (k-1)-(k-1)/2, b ) ){
				ans = max( ans, a+b );
			}
			if( bfs(x[i], y[i], (k-1)-(k-1)/2, a) && bfs(y[i], x[i], (k-1)/2, b ) ){
				ans = max( ans, a+b );
			}
		}
		if( ans == -INF ) puts("Impossible revenge!");
		else printf("%d\n", ans );
	}
	
	
}

