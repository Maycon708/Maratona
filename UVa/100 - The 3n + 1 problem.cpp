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

#define N 1000000

ll pd[N];

ll solve( ll n ){
	if( n == 1 ) return 1;
	if( n >= N ){
		if( n&1 ) return 1 + solve( 3 * n + 1 );
		else return 1 + solve( n >> 1 );
	}
	if( pd[n] ) return pd[n];
	if( n&1 ) return pd[n] = 1 + solve( 3 * n + 1 );
	return pd[n] = 1 + solve( n >> 1 );
}

int main(){
	int a, b;
	while( scanf("%d%d", &a, &b ) != EOF ){
		ll ans = 0;
		printf("%d %d", a, b );
		if( a > b ) swap( a, b );
		rep( i, a, b+1 ){
			ans = max( ans, solve(i) );
		}
		printf(" %lld\n", ans );
	}
}

