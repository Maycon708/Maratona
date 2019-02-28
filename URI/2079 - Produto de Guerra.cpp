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

ll readInt();

int resp, vis[MAXV];
vector < int > adj[MAXV];

bool dfs( int u, int pai ){
	bool ans = 1;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == pai ) continue;
		if( dfs( v, u ) ) ans = 0;
	}
	resp += ans;
	return vis[u] = ans;
}

int main(){
//	freopen( "out.txt", "w+", stdout );	
	int t = readInt();
	while( t-- ){
		int n = readInt();
		rep( i, 0, n+1 ) adj[i].clear(), vis[i] = -1;
		rep( i, 1, n ){
			int u = readInt();
			int v = readInt();
			adj[u].pb( v );
			adj[v].pb( u );
		}
		resp = 0;
		
		rep( i, 1, n+1 ) if( vis[i] == -1 ) dfs( i, -1 );
		printf("%d\n", resp );
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



