#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 101000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

vector < int > adj[MAXV];

inline int bfs( int n, int k ){
	queue < int > q;
	int vis[MAXV];
	rep( i, 0, MAXV ) vis[i] = 0;
	q.push( k+1 );
	while( !q.empty() ){
		int u = q.front(); q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			q.push( v );
		}
	}
	rep( i, k+1, n+k+1 ) if( !vis[i] ) return 0;
	return 1;
}

int main(){
	while( 1 ){
		int n = readInt();
		int k = readInt();
		if( !n && !k ) break;
		rep( i, 0, n+k+1 ) adj[i].clear();
		rep( i, 1, n+1 ){
			int u = readInt();
			while( u-- ){
				int v = readInt();
				adj[i+k].pb( v );
				adj[v].pb( i+k );
			}
		}
		if( bfs( n, k ) ) printf("S\n");
		else printf("N\n");
	}
}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}


