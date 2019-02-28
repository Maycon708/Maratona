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

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int n, m;
char mat[111][111];
ll pd[111][111][111];
int memo[111][111][111];
const int mod = 1e9+7;

ll solve( int i, int j, int k ){
	if( !i ) return 1;
	ll &ans = pd[i][j][k]; 
	if( !memo[i][j][k] ){
		memo[i][j][k] = 1;
		ans = 0;
		int ii = i, jj = j-1;
		if( !jj ) ii = i-1, jj = m;
		if( k >= j && mat[i][j] == '0' ) return ans = 0;
		if( k < j && mat[i][j] != '1' ) ans = ( ans + solve(ii, jj, k) )%mod;
		if( mat[i][j] != '0' ) ans = ( ans + solve(ii, jj, max(k, j) ) )%mod;
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &m );
	
	rep( i, 1, n+1 ) scanf("%s", mat[i]+1 );
	printf("%lld\n", solve(n, m, 0) );
	
	return 0;
}
