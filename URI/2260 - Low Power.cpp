#include <bits/stdc++.h>

#define INF 1 << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 200010

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll v[1000100], n, k;

bool check( ll d ){
	ll t = 2 * n * k, j = 2;
	rep( i, 2, n+1 ){
		bool aux = 1;
		for( ; j <= min(2*(i-1)*k, t-2 ); ++j ){
			if( v[j+1]-v[j] <= d ){
				aux = 0;
				j+=2;
				break;
			}
		}
		if( aux ) return 0;
	}
	return 1;
}

int main(){
	while( scanf("%lld%lld", &n, &k ) != EOF ){
		ll t = 2 * n * k;
		rep( i, 0, t ){
			scanf("%lld", &v[i] );
		}
		sort( v, v+t );
		ll lo = v[1] - v[0], hi = 1000000000LL, ans = 1LL << 60;
		while( lo < hi ){
			ll mid = (lo+hi)/2;
			if( check(mid) ){
				ans = min( ans, mid );
				hi = mid;
			}
			else lo = mid+1;
		}
		printf("%lld\n", ans );//*/
	}
}
