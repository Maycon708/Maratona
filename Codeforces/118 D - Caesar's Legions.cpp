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

ll pd[111][111][2], k1, k2;
const int mod = 1e8;

ll solve( int f, int h, int t ){
	if( !f && !h ) return 1;
	ll &ans = pd[f][h][t];
	if( ans == -1 ){
		ans = 0;
		if( !t ){
			rep( i, 1, k1+1 ) if( f >= i ) ans = ( ans + solve( f-i, h, 1 ) )%mod;
		}
		else{
			rep( i, 1, k2+1 ) if( h >= i ) ans = ( ans + solve( f, h-i, 0 ) )%mod;
		}
	}
	return ans;
}

int main(){
	int n, m;
	cin >> n >> m >> k1 >> k2;
	memset( pd, -1, sizeof pd );
	cout << ( solve(n, m, 0) + solve(n, m, 1) )%mod << "\n";
}
