#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 6000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

vector < int > adj[MAXV], Adj[MAXV];
bool vis[MAXV], Vis[MAXV], S[MAXV];
int ssc[MAXV];
vector < int > G;

void dfs( int u ){
	vis[u] = 1;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( !vis[v] )
			dfs( adj[u][i] );
	}
	G.pb( u );
}

void SSC( int u ){
	Vis[u] = 1;
	rep( i, 0, Adj[u].size() ){
		int v = Adj[u][i];
		if( !Vis[v] ){
			ssc[v] = ssc[u];
			SSC( v );
		}
	}
}

void init( int n ){
	rep( i, 0, n+1 ){
		adj[i].clear();
		Adj[i].clear();
		vis[i] = 0;
		Vis[i] = 0;
		S[i] = 1;
	}
	G.clear();
}

int main(){
	
	while( 1 ){
		int n = readInt();
		if( !n ) break;
	
		init( n );	
		
		int m = readInt();
		rep( i, 0, m ){
			int u = readInt()-1;
			int v = readInt()-1;
			adj[u].pb( v );
		}
		rep( i, 0, n ){
			rep( j, 0, adj[i].size() ){
				int v = adj[i][j];
				Adj[v].pb( i );
			}
		}
		rep( i, 0, n ){
			if( !vis[i] ){
				dfs( i );
			}
		}
		for( int i = n-1; i >= 0; i-- ){
			int v = G[i];
			
			if( !Vis[v] ){
				ssc[v] = v;
				SSC( v );
			}
		}
		rep( i, 0, n ){
			rep( j, 0, adj[i].size() ){
				int v = adj[i][j];
				if( ssc[i] != ssc[v] ){
					S[ ssc[i] ] = 0;
					break;
				}
			}
		}
		bool aux = 0;
		rep( i, 0, n ){
			if( S[ ssc[i] ] ){
				if( aux ) printf(" ");
				aux = 1;
				printf("%d", i+1 );
			}
		}
		printf("\n");
	}	

}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}



