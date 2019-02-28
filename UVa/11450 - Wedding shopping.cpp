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

int c, pd[30][300];
vector < int > v[30];

int solve( int pos, int cap ){
	if( pos == c ) return 0;
	if( pd[pos][cap] != -1 ) return pd[pos][cap];
	int ans = -INF;
	rep( i, 0, v[pos].size() ){
		int u = v[pos][i];
		if( u <= cap ) ans = max( ans, solve( pos+1, cap - u ) + u );
	}
	return pd[pos][cap] = ans;
}

int main(){
	int t, cap, n, u;
	scanf("%d\n", &t );
	while( t-- ){
		scanf("%d%d", &cap, &c );
		rep( i, 0, c ){
			v[i].clear();
			scanf("%d", &n );
			rep( j, 0, n ){
				scanf("%d", &u );
				v[i].pb( u );
			}
		}
		memset( pd, -1, sizeof pd );
		ll ans = solve( 0, cap );
		if( ans < 0 ) cout << "no solution\n";
		else cout << ans << "\n";
	}
}
