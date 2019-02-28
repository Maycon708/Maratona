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

int main(){
	
	ll a, b, c, d, e;
	while( scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e ) != EOF ){
		ll ans = 0;
		if( a >= c && a <= d ){
			ans = ( min( b, d ) - a + ( e < a || e > min( b, d ) ));
		}
		if( c >= a && c <= b ){
			ans = ( min( b, d ) - c + ( e < c || e > min( b, d ) ));
		}
		printf("%lld\n", ans );
	}
	
}

