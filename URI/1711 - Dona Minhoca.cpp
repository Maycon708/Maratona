#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int N = 11111;

vector<ii> adj[N];
int num[N], low[N], tam[N], scc[N];
stack<int> s;
int inSt[N];
int nDfs, nScc, k, x, y, ss, t;

void tarjanScc( int v, int last ){
 
    num[v] = low[v] = nDfs++;
    s.push(v), inSt[v] = true;
     
    rep( i, 0, adj[v].size() ){
        int w = adj[v][i].F;
        if( w == last ) continue;
        if( num[w] == -1 ){
            tarjanScc(w, v);
            low[v] = min ( low[v], low[w] );
        }
        else if( inSt[w] )
			low[v] = min ( low[v], low[w] );
    }
    if( low[v] == num[v]){
        int t;
        do{
            t = s.top();
            inSt[t] = false;
            scc[t] = nScc;
            s.pop();
        }while( t != v );
        nScc++;
    }
}
         
void init( int n ){
    rep( i, 0, n ){
        adj[i].clear();
        num[i] = -1;
        low[i] = -1;
        inSt[i] = false;
    }
    while( !s.empty() ) s.pop();
    nDfs = nScc = 0;
}

#define gc getchar_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}


int dijkstra( int ini, int t ){
	priority_queue<ii> pq;
	vector<bool> vis( N, 0 );
	vector<int> dist( N, INF );
	dist[ini] = 0;
	pq.push( ii( 0, ini ) );
	int resp = INF;
	while( !pq.empty() ){
		int u = pq.top().S;
		int c = -pq.top().F;
		pq.pop();
		if( dist[u] != c ) continue;
		if( tam[ scc[u] ] >= t ) resp = min( resp, 2 * c + tam[ scc[u] ] );
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int d_u_v = adj[u][i].S;
			if( dist[v] > d_u_v + c ){
				dist[v] = c + d_u_v;
				pq.push( ii( -dist[v], v ) );
			}
		}
	}
	if( resp == INF ) return -1;
	return resp;
} 
 
int main(){
	int n, m, u, v, c;
	while( 42 ){
		scan(n), scan(m);
		if( !n ) break;
		init(n);
		rep( i, 0, m ){
			scan(u), scan(v), scan(c);
			u--, v--;
			adj[u].pb( ii( v, c ) );
			adj[v].pb( ii( u, c ) );
		}
		rep( i, 0, n ){
			if( num[i] == -1 ) tarjanScc(i, -1);
		}
		rep( i, 0, nScc ) tam[i] = 0;
		rep( i, 0, n ){
			rep( j, 0, adj[i].size() ){
				v = adj[i][j].F;
				if( v < i || scc[i] != scc[v] ) continue;
				tam[ scc[i] ] += adj[i][j].S;
			}
		}
		int q;
		scan(q);
		while( q-- ){
			scan(u), scan(v), u--;
			printf("%d\n", dijkstra( u, v ) );
		}
	}
}

