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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);
#define N 100100

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

ll L[N], R[N], pd[N][2][2], r[N];
const int mod = 1e9+7;

ll solve( int u, int a, int b ){
	if( u == 0 ) return a == b;
	ll &ans = pd[u][a][b];
	if( ans == -1 ){
		ans = 0;
		if( r[u] == -1 ){
			rep( i, 0, 2 ) rep( j, 0, 2 ) rep( k, 0, 2 ) rep( l, 0, 2 )
				if( !(i&&j) == a && !(k&&l) == b ) ans = ( ans + solve(L[u], i, k) * solve(R[u], j, l) )%mod;
		}
		else if( r[u] == b ) rep( i, 0, 2 ) rep( j, 0, 2 ) rep( k, 0, 2 ) rep( l, 0, 2)
			if( !(i&&j) == a ) ans = ( ans + solve(L[u], i, k) * solve(R[u], j, l) )%mod;
	}
	return ans;
}

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		memset( pd, -1, sizeof pd );
		FOR( i, 1, n ) scanf("%lld%lld%lld", &L[i], &R[i], &r[i] );
		printf("%lld\n", (solve(1, 0, 1) + solve(1, 1, 0))%mod );
	}
}


