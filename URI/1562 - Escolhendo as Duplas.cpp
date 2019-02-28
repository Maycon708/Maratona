#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i <= int(b); i++)
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

#define N 10100

int n, adj[N], p[N], g[N];

bool check(){
	priority_queue<ii> pq;
	rep( i, 1, n )	pq.push( ii( -g[i], -i ) );
	while( !pq.empty() ){
		int u = -pq.top().S;
		int d = -pq.top().F;
		pq.pop();
		if( p[u] ) continue;
		int v = adj[u];
		if( !p[v] ) p[u] = v, p[v] = u, g[adj[v]]--, pq.push( ii( -g[adj[v]], -adj[v] ) );
	}
	bool aux = 1;
	rep( i, 1, n ) if( !p[i] ) return 0;
	return 1;
}

int main(){
	while( scanf("%d", &n ) != EOF ){
		rep( i, 1, n ) g[i] = p[i] = 0;
		rep( i, 1, n ) scanf("%d", &adj[i] ), g[ adj[i] ]++;
		if( n&1 || !check() ) puts("IMPOSSIBLE");
		else rep( i, 1, n ) printf("%d%s", p[i], i == n ? "\n" : " " );
	}
}

