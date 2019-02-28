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

typedef long long int ll;
typedef pair <ll, ll> ii;

inline bool cmp( ii a, ii b ){
	int dif = a.F - b.F - a.S + b.S;
	if( dif ) return ( a.F - a.S ) < ( b.F - b.S );
	return a.F > b.F;
}

inline bool cmp2( ii a, ii b ){
	if( a.F != b.F ) return a.F < b.F;
	return a.S < b.S;
}

int main(){
	
	ll t, n, h, k, g, r;
	scanf("%lld", &t );
	while( t-- ){
		vector < ii > l, p;
		scanf("%lld%lld%lld", &n, &h, &k );
		rep( i, 0, n ){
			scanf("%lld%lld", &g, &r );
			if( g <= r )
				l.pb( ii( g, r ) );
			else
				p.pb( ii( g, r ) );	
		}
		sort( all( l ), cmp2 );
		ll cnt = 0;
		rep( i, 0, l.size() ){
			if( h >= l[i].F ){
				h = ( h - l[i].F + l[i].S );
				cnt++;
			}
		}
		sort( all( p ), cmp );
		rep( i, 0, p.size() ){
			if( h >= p[i].F ){
				h = ( h - p[i].F + p[i].S );
				cnt++;
			}
		}
		if( cnt + k >= n ) printf("Y\n");
		else printf("N\n");
	}
}
