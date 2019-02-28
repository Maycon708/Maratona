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

struct Q{
	int p, k, m, c;		// pos, teletransport, mask, cost, qntdd
	Q(){};
	Q( int _p, int _k, int _m, int _c ){
		p = _p, k = _k, m = _m, c = _c;
	}
	bool operator < ( Q temp ) const { return c > temp.c; }
};

const int N = 16;
int n, dist[N][N][1<<N];
vector<ii> adj[N];

int solve( Q a ){
	priority_queue<Q> pq;
	pq.push(a);
	while( !pq.empty() ){
		Q u = pq.top();
		pq.pop();
		int pos = u.p, mask = u.m, cost = u.c, k = u.k;
		if( __builtin_popcount(mask) == n ) return cost;
		if( dist[pos][k][mask] < cost ) continue;
		rep( i, 0, adj[pos].size() ){
			int v = adj[pos][i].F;
			int c = adj[pos][i].S;
			if( cost + c < dist[v][k][mask|( 1 << v ) ] ){
				dist[v][k][mask|(1<<v) ] = cost + c;
				pq.push( Q( v, k, mask|( 1 << v ), cost + c ) );
			}
		}
		if( k ){
			rep( v, 0, n ){
				if( cost < dist[v][k-1][mask|( 1 << v ) ] ){
					dist[v][k-1][mask|(1<<v) ] = cost;
					pq.push( Q( v, k-1, mask|( 1 << v ), cost ) );
				}
			}
		}
	}
	return -1;
}

#define gc getchar//_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ); c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int main(){
	int t, m, k, a, b, c;
	scan(t);
	while( t-- ){
		scan(n), scan(m), scan(k);
		rep( i, 0, n ){
			adj[i].clear();
			rep( j, 0, k+1 )
				rep( l, 0, 1 << n )
					dist[i][j][l] = INF;
		}
		while( m-- ){
			scan(a), scan(b), scan(c);
			a--, b--;
			adj[a].pb( ii( b, c ) );
			adj[b].pb( ii( a, c ) );  
		}
		if( k >= n ) printf("0\n");
		else{
			dist[0][k][1] = 0;
			printf("%d\n", solve( Q( 0, k, 1, 0 ) ));
		}
	}
}

