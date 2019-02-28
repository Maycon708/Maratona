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
#define MAX  11000
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

vector < int > adj[MAX];
bool vis[MAX];

void init( int n ){
	rep( i, 0, n+1 ){
		adj[i].clear();
		vis[i] = 0;
	}
}

void bfs( int u ){
	queue < int > q;
	q.push( u );
	while( !q.empty() ){
		int v = q.front(); q.pop();
		if( vis[v] ) continue;
		vis[v] = 1;
		rep( i, 0, adj[v].size() )
			q.push( adj[v][i] );
	}
	
}

ll Q( int n ){
	return n * ( n-1 )/2;
}

int main(){
	
	int qttd[MAX], cor[MAX];
	int t = readInt();
	while( t-- ){
		
		int n = readInt();
		int m = readInt();
		int p = readInt();
		int k = readInt();
		
		init( n );
		rep( i, 0, k+1 ) qttd[i] = 0;
		
		rep( i, 0, n ) cor[i] = readInt()-1, qttd[ cor[i] ]++;
		bool aux = 1;
		rep( i, 0, m ){
			int a = readInt()-1;
			int b = readInt()-1;
			
			if( cor[a] == cor[b] ) aux = 0;
			adj[a].pb( b );	adj[b].pb( a );
		}
		int mn = 0;
		rep( i, 0, n ){
			if( !vis[i] ) bfs( i ), mn++;
		}
		mn--;
		ll mx = Q( n ) - m;
		rep( i, 0, k ){
			mx -= Q( qttd[i] );
		}
		if( p < mn || p > mx ) aux = 0;
		if( aux ) puts("Y");
		else puts("N");
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



