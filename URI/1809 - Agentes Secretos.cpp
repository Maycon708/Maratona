#include <bits/stdc++.h>
        
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debug3(x,y,z) cout << #x << " = " << x << " --- " << #y << " " << y << " --- " << #z << " " << z << "\n";
#define debugV(a, b) { for( int i = 0; i < b; i ++ ) cout << a[i] << " "; cout << endl; }
#define debugM(a, b, c ) { for( int i = 0; i < b; i ++ ){ for( int j = 0; j < c; j++ ) cout << a[i][j] << " "; cout << endl;} }
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
#define MAXV 5000
        
using namespace std;
        
typedef unsigned long long ll;
typedef pair < int, int >  ii;
typedef pair < double, int >  di;

vector<di> adj[101];
int n;

double dijkstra(){
	priority_queue<di> pq;
	bool vis[110];
	double dist[110];
	rep( i, 0, 110 ) vis[i] = dist[i] = 0;
	dist[0] = 1;
	pq.push( di( 1, 0 ) );
	
	while( !pq.empty() ){
		int u = pq.top().S;
		pq.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].S;
			double d_u_v = adj[u][i].F;
			if( dist[v] < d_u_v && !vis[v]){
				dist[v] =  d_u_v;
				pq.push( di( dist[v], v ) );
			}
		}
	}
	double ans = 1;
	rep( i, 0, n ) ans *= dist[i];
//	debug( ans )
	return ans;
}

int main(){
	
	int m, u, v, t = 1;
	double p, d[111], mat[111][111];
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		if( t != 1 ) printf("\n");
		
		rep( i, 0, n ) adj[i].clear();
		
		rep( i, 0, m ){
			scanf("%d%d%lf", &u, &v, &p );
			u--, v--;
			adj[u].pb( di( 1-p, v ) );
			adj[v].pb( di( 1-p, u ) );
		}
		
		double ans = 1;
		rep( i, 0, n ) ans *= mat[0][i];
		
		
		printf("Cenario %d, probabilidade de interceptacao = %.3f\n", t++, 1-dijkstra() );
	}
}
