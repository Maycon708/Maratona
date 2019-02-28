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

int pd[1011][30][90], n, O[1011], N[1011], vo, vn, v[1011];

int solve( int pos, int a, int b ){
	if( a < 0 ) a = 0; if( b < 0 ) b = 0;
	if( !a && !b ) return 0;
	if( pos == n ) return INF;
	if( pd[pos][a][b] != -1 ) return pd[pos][a][b];
	int ans = INF;
	ans = min( ans, solve( pos+1, a, b ));
	ans = min( ans, solve( pos+1, a - O[pos], b - N[pos] ) + v[pos] );
	return pd[pos][a][b] = ans;
}

int main(){

	int t;
	cin >> t;
	while( t-- ){
		cin >> vo >> vn;
		cin >> n;
		rep( i, 0, n ) cin >> O[i] >> N[i] >> v[i];
		memset( pd, -1, sizeof pd );
		cout << solve( 0, vo, vn ) << "\n";
	}
}
