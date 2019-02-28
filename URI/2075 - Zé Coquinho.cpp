#include <bits/stdc++.h>
 
#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
 
using namespace std;
 
typedef pair <int, int> ii;
typedef long long int ll;

ll aux, pd[60][2][60][2];

ll solve( int p, int pref, int z, int a ){
	if( p == -1 ) return a || ( z != 0 );
	ll &ans = pd[p][pref][z][a];
	if( ans != -1 ) return ans;
	ans = 0;
	if( pref ){
		if( aux & ( 1LL << p ) ){
			ans = solve( p-1, 0, z+1, a );
			if( z ) ans += solve( p-1, 1, z-1, a );
			else ans += solve( p-1, 1, z, 1 );
		}
		else ans = solve( p-1, 1, z+1, a );
	}
	else{
		ans = solve( p-1, 0, z+1, a );
		if( z ) ans += solve( p-1, 0, z-1, a );
		else ans += solve( p-1, 0, z, 1 );
	}
	return ans ; 
}


int main(){

	ll n, k, t;
	scanf("%lld", &t );
	while( t-- && scanf("%lld%lld", &n, &k ) != EOF ){
		ll lo = 0, hi = 1LL << n, mid, i; k++;
		while( lo < hi ){
			mid = ( lo + hi )/2;
			aux = mid;
			memset( pd, -1, sizeof pd );
			ll ans = solve( n-1, 1, 0, 0 );
			if( ans >= k ) hi = mid;
			else if( ans < k ) lo = mid+1;
		}
		if( hi == 1LL << n ){
			puts("-1");
			continue;
		}
		string s;
		for( i = n-1; i >= 0; --i, hi >>= 1 ){
			if( hi&1 ) s.pb(')');
			else s.pb('(');
		}
		reverse( all(s) );
		printf("%s\n", s.c_str() );
	}
	

}
