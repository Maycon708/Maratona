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

const int mod = 1e9+7;

ll arranjo( int n, int k ){
	ll ans = 1;
	rep( i, 0, k ){
		ans *= (n-i);
		ans %= mod;
	}
	return ans;
}

ll solve( int n, int k, int q ){
	ll ans = (( 1LL << k ) * arranjo( q, ( 1 << k )-1 ))%mod;
	ans = ( ans * ( 1LL << ( n - k ) ))%mod;
	ans = ( ans * arranjo( ( 1 << n ) - ( 1 << k ), ( 1 << n ) - ( 1 << k ) ))%mod;
	return ans;
}

ll modulo( ll aux ){
	return (( aux%mod ) + mod )%mod;
}

int main(){
	int n, k, h, aux;
	while( scanf("%d%d", &n, &k ) != EOF ){
		scanf("%d", &h );
		int cnt = 0;
		rep( i, 1, 1 << n ){
			scanf("%d", &aux );
			if( aux <= h ) cnt++;
		}
		printf("%lld\n", modulo( solve( n, k-1, cnt ) - solve( n, k, cnt ) ));
	}
}
