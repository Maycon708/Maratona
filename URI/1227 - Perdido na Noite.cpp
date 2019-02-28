#include <bits/stdc++.h>
        
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debug3(x,y,z) cout << #x << " = " << x << " --- " << #y << " " << y << " --- " << #z << " " << z << "\n";
#define debugV(a, b) { for( int i = 0; i < b; i ++ ) cout << a[i] << " "; cout << endl; }
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
#define MAXV 500*500+1
        
using namespace std;
        
typedef unsigned long long ll;
typedef pair < int, int >  ii;

int a, b, c, n, x, y;
vector < int > adj[MAXV];

int bfs( int ini, int fim ){
	bool vis[MAXV];
	rep( i, 0, n+1 ) vis[i] = 0;
	queue < ii > q;
	q.push( ii( ini, 0 ) );
	while( !q.empty() ){
		int u = q.front().F;
		int c = q.front().S;
		q.pop();
		if( u == fim ) return c;
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			q.push( ii( v, c+1 ) );
		}
	} 
}

int main(){
	
	while( scanf("%d%d%d%d", &n, &a, &b, &c ) != EOF ){
		rep( i, 0, n+1 ){
			adj[i].clear();
		}
		rep(i, 0, n-1 ){
			scanf("%d%d", &x, &y );
			adj[x].pb( y );
			adj[y].pb( x );
		}
		
		double A = bfs( a, b );
		double B = bfs( a, c );
		double C = bfs( b, c );
		int Iw = ( B + A ) - C;
		Iw /= 2;
		Iw = A - Iw;
		printf("%.6f\n", 1 - Iw/C );
	}
}		
