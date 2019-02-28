#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAX 50010
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const ll x = 33, mod = 1e9+7;
ll H[MAX], X[MAX];
ll HR[MAX], XR[MAX];

inline int C( char c ){
	return c - 'a' + 1;
}

void precomp( string s ){
	H[0] = 0, X[0] = 1;
	s = "$" + s;
	rep( i, 1, s.size()+1 ){
		H[i] = H[i-1] * x + C( s[i] );
		H[i] %= mod;
		X[i] = ( X[i-1] * x )%mod;
	}
}

void precompR( string s ){
	s = "$" + s + "$";
	int n = s.size();
	HR[n] = 0;
	for( int i = n-1; i >= 0; i-- ){
		HR[i] = HR[i+1] * x + C( s[i] );
		HR[i] %= mod;
	}
}

inline ll HashR( int l, int r ){
	ll ans = ( ( HR[l] - ( HR[r+1] * X[ r-l+1 ] )%mod ) + mod ) %mod;
	return ans;
}

inline ll Hash( int l, int r ){
	ll ans = ( ( H[r] - ( H[l-1] * X[ r-l+1 ] )%mod ) + mod ) %mod;
	return ans;
}

int pd[3000], n;

int solve( int pos ){
	if( pos == n ) return 0;
	if( pd[pos] != -1 ) return pd[pos];
	int ans = 1 << 30;
	ans = min( ans, solve(pos+1) + 1 );
	rep( i, pos+1, n ){
		ll a = Hash( pos, i );
		ll b = HashR( pos, i );
		if( a == b ) ans = min( ans, solve( i+1 ) + 1 );
	}
	return pd[pos] = ans;
}

int main(){
	char s[MAX], ss[MAX];
	int t = 1;
	while( scanf("%d", &n ) != EOF && n ){
		n++;
		rep( i, 0, n ) pd[i] = -1;
		scanf("%s", s );
		precomp(s);
		precompR(s);
		printf("Teste %d\n%d\n\n", t++, solve( 1 ) );
	}
}

