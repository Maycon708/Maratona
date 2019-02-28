#include <bits/stdc++.h>

#define INF 9.223371e+18
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

typedef long long int ll;
typedef pair <int, int> ii;

ll readInt();

ll d, pd[110][1010];
vector < pair < int, ii > > adj[110];
ll solve( int pos, int b ){
	if( pos == d ) return 0;
	if( pd[pos][b] != -1 ) return pd[pos][b];
	ll ans = -INF;
	rep( i, 0, adj[pos].size() ){
		int u = adj[pos][i].F;
		int f = adj[pos][i].S.F;
		int c = adj[pos][i].S.S;
		if( b >= c ) ans = max( ans, solve( u, b - c ) + f );
	}
	return pd[pos][b] = ans;
}

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		int m = readInt();
		int p = readInt();
		d = readInt();
		int b = readInt();
		rep( i, 0, n+1 ){
			adj[i].clear();
			rep( j, 0, b+1 ) pd[i][j] = -1;		
		} 
		while( m-- ){
			int x = readInt();
			int y = readInt();
			int f = readInt();
			int s = readInt();
			adj[x].pb( mk( y, ii( f, s ) ) );
			adj[y].pb( mk( x, ii( f, s ) ) );
		}
		ll ans = solve( p, b );
		if( ans < 0 ) printf("-1\n");
		else printf("%lld\n", ans );
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


