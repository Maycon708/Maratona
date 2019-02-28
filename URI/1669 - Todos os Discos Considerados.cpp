#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 120000
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
int g[MAXV], g2[MAXV];

int n1, n2;
inline int check( int a ){
	return a < n1;
}

inline bool same( int x, int y, int a ){
	return ( x < a && y < a ) || ( x >= a && y >= a );
}

int dfs( int op, int d[MAXV] ){
	queue <int> q;
	int cont = 0, add = 0;
	int vis[MAXV];
	rep( i, 1, n1 ){
		vis[i] = 0;
	}
	rep( i, n1, n1+n2 ){
		vis[i] = 0;
	}
	sqrone:
	if( op )
		rep( i, 1, n1 ){
			if( !d[i] ) q.push( i );
		}
	else 
		rep( i, n1, n1+n2 ){
			if( !d[i] ) q.push( i );
		}
	while( !q.empty() ){
		int u = q.front();
//		debug2( u, op )
		q.pop();
		if( vis[u] ) continue;
		if( op != check( u ) ){
			cont++, op = check( u );
			if( !add ){
				rep( i, n1*(!op), n1 + n2*(!op) ) if( !d[i] ) q.push( i );
				add = 1;
			}
		} 
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			d[v]--;
			if( !d[v] ) q.push( v );
		}
	}
	if( !add ){
		cont++;
		op = !op;
		add = 1;
		goto sqrone;
	}
	return ( cont+2 );
}

int main(){
	while( 1 ){
		n1 = readInt()+1;
		n2 = readInt();
		int D = readInt();
		if( n1 == 1 && !n2 && !D ) break;
		rep( i, 0, n1+n2 ) g[i] = 0, adj[i].clear();
		g[0] = g2[0] = 1;
		while( D-- ){
			int x = readInt();
			int y = readInt();
			if( same( x, y, n1 ) ) continue;
			adj[y].pb( x );
			g[x]++;
			g2[x]++;
		}
		printf("%d\n", min( dfs( 0, g ), dfs( 1, g2 )));
//		debug( dfs( 0, g ) );
//		debug( "____----____");
//		debug( dfs( 1, g2 ) );
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


