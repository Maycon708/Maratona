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

#define N 1010

vector<int> adj[N];
int n, g[N];

int bfs(){
	bool vis[N];
	queue<ii> q;
	rep( i, 0, n ){
		vis[i] = 0;
		if( !g[i] ) q.push( ii( i, 1 ) );
	}
	int ans;
	while( !q.empty() ){
		int u = q.front().F;
		if( vis[u] ) continue;
		ans = q.front().S;
		q.pop();
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			g[v]--;
			if( !g[v] ) q.push( ii( v, ans+1 ) );
		} 
		adj[u].clear();
	}
	rep( i, 0, n ) if( !vis[i] ) return -1;
	return ans;
}

int main(){
	int m;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			scanf("%d", &g[i] );
			rep( j, 0, g[i] ){
				scanf("%d", &m );
				adj[--m].pb(i);
			}
		}
		printf("%d\n", bfs() );
	}
}
