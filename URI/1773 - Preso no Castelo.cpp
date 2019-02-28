#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010
#define MAXN 1100
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

int vis[MAXV][MAXV], check[MAXV], n, m, key[MAXV];
vector < int > adj[MAXV];
bool bfs(){
	memset( vis, 0, sizeof vis );
	memset( check, 0, sizeof check );
	queue < ii >  q;
	q.push( ii( 1, 0 ) );
	while( !q.empty() ){
		int u = q.front().F;
		int c = q.front().S;
		q.pop();
		if( vis[u][c] ) continue;
		vis[u][c] = check[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			if( check[ key[v] ] ){
				q.push( ii( v, c + !check[v] ) ); 
				check[v] = 1;
			} 
		}
	}
	rep( i, 1, n+1 )
		if( !check[i] ){
			return 0;
		} 
	return 1;
}

int k = 0;

int main(){
	while( scanf("%d%d", &n, &m ) != EOF ){
	    if( k == 22 ) printf("%d %d\n", n, m );
		rep( i, 0, n+1 ) adj[i].clear();
		while( m-- ){
			int a = readInt();
			int b = readInt();
			if( k == 22 ) printf("%d %d\n", a, b );
			adj[a].pb(b);
			adj[b].pb(a);
		}
		key[1] = 1;
		rep( i, 2, n+1 ){
			key[i] = readInt();
			if( k == 22 ) printf("%d ", key[i] );
		}
		if( k == 22 ) printf("\n");
		if( bfs() ) printf("sim\n");
		else printf("nao\n");
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

