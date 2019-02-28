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

#define N 100010
const int mod = 1000000007;

ll fat[N], inv[N], pot[N], sum[N];

ll fastExp( ll b, ll e ){
	ll ans = 1;
	for( ; e; e >>= 1 ){
		if( e&1 ) ans = ( ans * b )%mod;
		b = ( b*b )%mod;
	}
	return ans;
}

void pre(){
	fat[0] = inv[0] = pot[0] = 1;
	rep( i, 1, N ){
		fat[i] = ( fat[i-1] * i )%mod;
		inv[i] = ( fastExp(fat[i], mod-2 ) )%mod; 
		pot[i] = ( pot[i-1] * 10LL )%mod;
	} 	
}

ll C( int n, int k ){
	if( k > n ) return 0;
	return (( fat[n] * inv[k] )%mod * inv[n-k] )%mod;
}

int main(){
	int n, k;
	char s[N];
	pre();
	while( scanf("%d%d", &n, &k ) != EOF ){
		scanf("%s", s );
		rep( i, 0, n ) sum[i] = s[i] - '0' + ( ( i ) ? sum[i-1]:0 );
		
		ll ans = 0;
		rep( i, 0, n-1 ){
			ans += ( ( pot[i] * C( n-i-2, k-1 ))%mod * sum[n-i-2] )%mod;
			ans %= mod;
		}
		rep( i, 0, n ){
			ans += ( (( s[i]-'0' ) * pot[n-i-1])%mod * C(i, k) )%mod;
			ans %= mod;
		}
		printf("%I64d\n", ans ); 
	}
}

