#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	ll n, c[2][2002], pd[2][2002], t[2][2002];
	while( scanf("%lld", &n ) != EOF ){
		scanf("%lld%lld", &pd[0][0], &pd[1][0] );
		rep( i, 0, 2 )
			rep( j, 0, n )
				scanf("%lld", &c[i][j] );
		rep( i, 0, 2 )
			rep( j, 0, n-1 )
				scanf("%lld", &t[i][j] );
		ll a, b;
		scanf("%lld%lld", &a, &b );
		rep( j, 0, n ){
			rep( i, 0, 2 ){
				if( j ) pd[i][j] = min( pd[i][j-1], pd[1-i][j-1] + t[1-i][j-1] );
				pd[i][j] += c[i][j];
			}
		}
		cout << min( pd[0][n-1] + a, pd[1][n-1] + b ) << endl;
	}
}
