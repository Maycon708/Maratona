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

int n, m, s, k;
int dist[100100][111];
vector<int> v[111], adj[100100];

void bfs( int s ){
	queue<ii> q;
	int vis[100100];
	rep( i, 1, n+1 ) vis[i] = 0;
	rep( i, 0, v[s].size() ) q.push( ii( v[s][i], 0 ));
	while( !q.empty() ){
		int u = q.front().F;
		int c = q.front().S;
		q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		dist[u][s] = c;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			q.push( ii( v, c+1 ) );			
		}
	}
}

int main(){
	int aux, a, b;
	while( scanf("%d%d%d%d", &n, &m, &s, &k ) != EOF ){
		rep( i, 0, n+1 ) adj[i].clear();
		rep( i, 0, s+1 ) v[i].clear();
		rep( i, 1, n+1 ){
			scanf("%d", &aux );
			v[aux].pb(i);
		}
		rep( i, 0, m ){
			scanf("%d%d", &a, &b );
			adj[a].pb(b);
			adj[b].pb(a);
		}
		rep( i, 1, s+1 ){
			bfs(i);
		}
		rep( i, 1, n+1 ){
			priority_queue<int> pq;
			int ans = 0;
			rep( j, 1, s+1 ){
				pq.push( dist[i][j] );
				ans += dist[i][j];
				if( pq.size() > k ){
					ans -= pq.top();
					pq.pop();
				}
			}
			printf("%d ", ans );
		}
		printf("\n");
	}
	
}
