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

const int N = 5005;
const int mod = 1e9+7;

ll pd[N][N];

ll solve( int n, int k ){
	if( !n ) return !k;
	if( pd[n][k] != -1 ) return pd[n][k];
	pd[n][k] = 0;
	if( k ) pd[n][k] = ( ( ( n - k + 1 ) * solve( n-1, k-1 ) )%mod + ( ( k ) * solve( n-1, k ) )%mod )%mod;
	return pd[n][k];
}

int main(){
	int n, q, k;
	while( scanf("%d%d", &n, &q ) != EOF ){
		memset( pd, -1, sizeof pd );
		rep( i, 0, q ){
			scanf("%d", &k );
			ll ans = 0;
			rep( i, 0, min( k, n ) + 1 ) ans = ( ans + solve( n, i ) )%mod;
			if( i ) printf(" ");
			printf("%lld", ans );
		}
		printf("\n");
	}
}

