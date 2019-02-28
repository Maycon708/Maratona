#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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

ll pd[200], f[200], p[200], d[200], h[200], n;

ll solve( int pos ){
	if( pos == n ) return 0;
	if( pd[pos] != -1 ) return pd[pos];
	ll c = f[pos];
	ll ans = ll(1) << 62;
	rep( i, pos, n ){
		c += ( d[i] * p[pos] );
		rep( j, pos, i ){
			c += ( d[i] * h[j] );
		}
		ans = min( ans, solve( i+1 ) + c );
	}
	return pd[pos] = ans;
}

int main(){
	int t = 1;
	while( scanf("%lld", &n ) != EOF ){
		if( !n ) break;
		if( t != 1 ) printf("\n");
		rep( i, 0, n ){
			pd[i] = -1;
			scanf("%lld%lld%lld%lld", &f[i], &p[i], &h[i], &d[i] );
		}
		printf("Instancia #%d\n", t++ );
		printf("%lld\n", solve( 0 ) );
	}
}
