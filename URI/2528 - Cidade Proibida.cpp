#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

vector<int> adj[1010];
int n, u, v, c, r, e, m;

int bfs(){
	vector<int> vis(n+1, 0);
	queue<ii> q;
	q.push( ii( c, 0 ) );
	vis[e] = 1;
	
	while( !q.empty() ){
		u = q.front().F;
		int d = q.front().S;
		q.pop();
		if( u == r ) return d;
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			v = adj[u][i];
			q.push( ii( v, d+1 ) );
		}
	}
}

int main(){
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n+1 ) adj[i].clear();
		while( m-- ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
		}
		scanf("%d%d%d", &c, &r, &e );
		printf("%d\n", bfs() );
	}
}

