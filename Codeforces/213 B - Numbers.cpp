#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

const int mod = 1e9+7;

ll pd[10][111];
ll C[111][111];
int a[111];

void pascal(){
	C[0][0] = 1;
	for( int i = 1; i < 111; i++ ){
		C[i][0] = C[i][i] = 1;
		for( int j = 1; j < i; j++ ) C[i][j] = ( C[i-1][j-1] + C[i-1][j] )%mod;
	}
}

ll solve( int p, int k ){
	if( p == 10 ) return !k;
	if( k < a[p] ) return 0;
	ll &ans = pd[p][k];
	if( ans == -1 ){
		ans = 0;
		if( !p ) for( int i = a[0]; i <= k-1; i++ ) ans = ( ans + solve(p+1, k-i) * C[k-1][i] )%mod;
		else for( int i = a[p]; i <= k; i++ ) ans = ( ans + solve(p+1, k-i) * C[k][i] )%mod;
	}
	return ans;
}

int main(){
	int n;
	pascal();
	scanf("%d", &n );
	rep( i, 0, 10 ) scanf("%d", &a[i] );
	memset( pd, -1, sizeof pd );
	ll ans = 0;
	rep( i, 1, n+1 )
		ans = ( ans + solve(0, i) )%mod;
	cout << ans << "\n";
}


