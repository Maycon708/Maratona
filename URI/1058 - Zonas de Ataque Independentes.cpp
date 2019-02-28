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

const int N = 100;

ll pd[N][N];
int cor[N];

ll solve( int i, int j ){
	if( i > j ) return 1;
	if( pd[i][j] != -1 ) return pd[i][j];
	ll ans = 0;
	rep( k, i+1, j+1 ){
		rep( l, k+1, j+1 ){
			int u = cor[i]+cor[l]+cor[k];
			if( u >= 2 ) ans += ( solve( i+1, k-1 ) * solve( k+1, l-1 ) * solve( l+1, j ) );
		}
	}
	return pd[i][j] = ans;
}

int main(){
	
	int T, n;
	char s[N];
	
	scanf("%d", &T );
	
	rep( t, 1, T+1 ){
		scanf("%d", &n );
		scanf("%s", s );

		rep( i, 0, n ) cor[i] = cor[i+n] = ( s[i] == 'B');
	
		memset( pd, -1, sizeof pd );
		
		ll ans = 0;
		rep( i, 0, n )
			ans = max( ans, solve( i, i + n - 1 ) );
		
		printf("Case %d: %lld\n", t, ans );		
	}
}

