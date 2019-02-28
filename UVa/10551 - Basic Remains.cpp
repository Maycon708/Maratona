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

ll A2B( int a, int b, ll n ){
	ll ans = 0;
	for( ll aux = 1; n; aux *= a, n /= b )
		ans += ( aux * ( n%b ) );
	return ans;
}

int main(){
	ll b, m, n;
	char s[1111];
	while( scanf("%lld", &b ) != EOF && b ){
		scanf("%s%lld", s, &m );
		int t = strlen(s);
		int mod = A2B( b, 10, m );
		n = 0;
		rep( i, 0, t ){
			n *= b;
			n += ( s[i] - '0' );
			n %= mod;
		}
		printf("%lld\n", A2B( 10, b, n ));
	}
}

