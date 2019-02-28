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

ll n, m, cc[MAXV], c[MAXV], vis[MAXV];
vector< int > adj[MAXV];
void bfs(){
	c[n] = cc[n] = 1;
	priority_queue < int > q;
	q.push( n );
	while( !q.empty() ){
		int u = q.top();
		q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			cc[v] += cc[u];
			q.push( v );
		}
	}
}

void bfs_(){
	c[n] = cc[n] = 1;
	priority_queue < int > q;
	q.push( n );
	rep( i, 0, n+1 ) vis[i] = 0;
	while( !q.empty() ){
		int u = q.top();
		q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			c[v] = max( c[v], c[u] + cc[v] );
			q.push( v );
		}
	}
}

int main(){

	while( scanf("%lld%lld", &n, &m ) != EOF ){
		rep( i, 0, n+1 ) adj[i].clear(), cc[i] = 0, c[i] = 0, vis[i] = 0;
		while( m-- ){
			int u = readInt();
			int v = readInt();
			adj[v].pb( u );
		}
		bfs(); bfs_();
		printf("%lld\n", c[1] );
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



