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
#define MAXV 10100
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int n, mat[20][20];
ll pd[1<<20];

ll solve( int mask ){
	if( mask == ( 1 << n ) -1 ) return 1;
	if( pd[mask] != -1 ) return pd[mask];
	ll ans = 0;
	int cnt = 0, aux = mask;
	while( aux ){
		if( aux&1 ) cnt++;
		aux >>= 1;
	}
	rep( i, 0, n ){
		if( mat[cnt][i] && !( mask & ( 1 << i ) )) ans += solve( mask | ( 1 << i ));
	} 
	return pd[mask] = ans;
}

int main(){
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		rep( i, 0, n ){
			rep( j, 0, n ){
				scanf("%d", &mat[i][j] );
			}
		}
		rep( j, 0, 1 << n ){
			pd[j] = -1;
		}
		printf("%lld\n", solve( 0 ) );
	}
}
