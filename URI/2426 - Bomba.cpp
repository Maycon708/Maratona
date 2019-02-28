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

int vis[555][5];
vector<ii> adj[555];

void bfs( int s, int e ){
	queue<pair<ii, int> > q;
	q.push( mk( ii( s, 0 ), 0 ) );
	memset( vis, 0, sizeof vis );
	int ans = 1 << 30;
	while( !q.empty() ){
		int u = q.front().F.F;
		int t = q.front().F.S;
		int d = q.front().S;
		q.pop();
		if( vis[u][t] ) continue;
		vis[u][t] = 1;
		if( u == e ) ans = min( ans, d );
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int op = adj[u][i].S;
			if( op && !t ) q.push( mk( ii( v, 1 ) , d+1 ));
			else if( !op && t ) q.push( mk( ii( v, (t+1)%3), d+1 ));
		}
	}
	if( ans == 1 << 30 ) printf("*\n");
	else printf("%d\n", ans );
}

int main(){
	int n, s, e, m, u, v, op;
	while( scanf("%d%d%d%d", &n, &s, &e, &m ) != EOF ){
		rep( i, 0, n ) adj[i].clear();
		while( m-- ){
			scanf("%d%d%d", &u, &v, &op );
			adj[u].pb( ii( v, op ));
		}
		bfs( s, e );
	}
}
