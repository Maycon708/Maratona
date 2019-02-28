#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int pd[111][111], mod = 1000000;

int solve( int n, int k ){
	if( !k ) return !n;
	if( n < 0 ) return 0;
	if( pd[n][k] != -1 ) return pd[n][k];
	int ans = 0;
	rep( i, 0, n+1 ){
		ans += solve( n-i, k-1 );
		if( ans > mod ) ans %= mod;
	}
	return pd[n][k] = ans;
}

int main(){
	int n, k;
	while( cin >> n >> k && n+k ){
		memset( pd, -1, sizeof pd );
		printf("%d\n", solve( n, k ) );
	}
}

