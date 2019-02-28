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

#define N 111

int a, b, m, l, k;
vector<ii> adj[N];

struct estado{
	int pos, k, dist, op;
	estado();
	estado( int _pos, int _k, int _dist, int _op ){
		pos = _pos; k = _k; dist = _dist; op = _op;
	}
	bool operator < ( estado q ) const{
		if( pos != q.pos ) return pos < q.pos;
		if( k != q.k ) return k < q.k; 
		if( dist != q.dist ) return dist < q.dist;
		return op < q.op;
	}
	void D(){
		printf("Pos = %d -- K = %d -- dist = %d -- op = %d\n", pos, k, dist, op );
	}
};

int dijkstra(){
	map<estado, int> dist;
	priority_queue< pair< int, estado > > pq;
	pq.push( mk( 0, estado( a+b, k, 0, 0 ) ) );
	int ans = 1 << 30;
	while( !pq.empty() ){
		estado u = pq.top().S;
		int d = -pq.top().F;
		pq.pop();
		if( u.pos == 1 ) ans = min( ans, dist[u] );
		if( dist[u] != d ) continue;
		rep( i, 0, adj[u.pos].size() ){
			int v = adj[u.pos][i].F;
			int d_u_v = adj[u.pos][i].S;
			estado aux = estado( v, u.k, 0, 0 );
			if( !dist.count(aux) || dist[u] + d_u_v < dist[aux] ){
				dist[aux] = dist[u] + d_u_v;
				pq.push( mk( -dist[aux], aux ));
			}
			if( u.op && u.dist >= d_u_v ){
				aux.dist = u.dist - d_u_v;
				aux.op = ( v <= a );
				if( !dist.count(aux) || dist[u] < dist[aux] ){
					dist[aux] = dist[u];
					pq.push( mk( -dist[aux], aux ));
				}
			}
			if( u.k && l >= d_u_v ){
				aux.k = aux.k - 1;
				aux.dist = l - d_u_v;
				aux.op = ( v <= a );
				if( !dist.count(aux) || dist[u] < dist[aux] ){
					dist[aux] = dist[u];
					pq.push( mk( -dist[aux], aux ));
				}
			} 
		}		 
	}
	return ans;
}

int main(){
	int t, u, v, c;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d%d%d%d", &a, &b, &m, &l, &k );
		rep( i, 0, a+b+1 ) adj[i].clear();
		while( m-- ){
			scanf("%d%d%d", &u, &v, &c );
			adj[u].pb( ii( v, c ));
			adj[v].pb( ii( u, c ));
		}
		cout << dijkstra() << "\n";
	}
}

