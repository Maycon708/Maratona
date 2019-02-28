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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

int n, t[30], mat[30][30];
bool vis[1<<20];
vector < ii > adj[30];

int solve( int pos ){
	if( t[pos] > 7 * 60 ) return 0;
	int tt = 7 * 60 - t[pos];
	priority_queue < pair < ii, ii > > pq;
	pq.push( mk( ii( tt, pos ), ii( ( 1 << pos ), 1 ) ));
	int ans = 1;
	while( !pq.empty() ){
		int u = pq.top().F.S;
		int T = pq.top().F.F;
		int mask = pq.top().S.F;
		int cont = pq.top().S.S;	
		ans = max( ans, cont );
		pq.pop();
		if( vis[mask] ) continue;
		vis[mask] = 1;
		int ans = cont;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].S;
			int cost = -adj[u][i].F;
			if( !( mask & ( 1 << v ) ) && T >= cost )
				pq.push( mk( ii( T - cost, v ), ii( mask | ( 1 << v ), cont+1 ) ) );
		}
	}
	return ans;
}

void pre(){
	rep( i, 0, n ) adj[i].clear();
	rep( i, 0, n ){
		rep( j, 0, n ){
			if( i != j ){
				adj[i].pb( ii( -( mat[i][j] + t[j] ), j ) );
				adj[j].pb( ii( -( mat[i][j] + t[i] ), i ) );
			}
		}
	}
}

int main(){
//	freopen( "out.txt", "w", stdout );
	while( 1 ){
		n = readInt();
		if( !n ) break;
		rep( i, 0, n ) t[i] = readInt();
		rep( i, 0, n ){
			rep( j, 0, n ){
				mat[i][j] = readInt();
			}
		}
		memset( vis, 0, sizeof vis );
		pre();
		int ans = 0;
		rep( i, 0, n ){
			ans = max( ans, solve( i ) );
			if( ans == n ) break;
		}
		printf("%d\n", ans );
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


