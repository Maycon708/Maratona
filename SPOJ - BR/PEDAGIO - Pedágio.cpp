#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;
typedef vector<int> vec;

vec adj[MAXV];
bool vis[MAXV];
int N, C;

vec bfs( int ini ){
	queue < ii > q;
	q.push( ii( ini, 0 ) );
	vec aux;
	while( !q.empty() ){
		int u = q.front().F;
		int c = q.front().S;
		q.pop();
		if( c > C || vis[u] ) continue;
		vis[u] = 1;
		if( u != ini ) aux.pb( u );
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			q.push( ii( v, c+1 ) );
		}
	}
	sort( all( aux ) );
	return aux;
}

int main(){

	int ini, m, t = 1, a, b;
	while( cin >> N >> m >> ini >> C ){
		if( !N && !m && !ini && !C ) break;
		
		rep( i, 0, N+1 )
			vis[i] = 0, adj[i].clear();
		
		while( m-- ){
			cin >> a >> b;
			adj[a].pb( b );
			adj[b].pb( a );
		}
		
		vec a = bfs( ini );
		
		printf("Teste %d\n", t++ );
		rep( i, 0, a.size() ){
			if( i ) printf(" ");
			printf("%d", a[i] );
		}
		printf("\n\n");
	}

}


