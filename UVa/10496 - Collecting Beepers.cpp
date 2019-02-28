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

int pd[20][1<<10], n, x[20], y[20];

int D( int i, int j ){
	return abs( x[i] - x[j] ) + abs( y[i] - y[j] );
}

int solve( int pos, int mask ){
	if( mask == ( 1 << n ) -1 ) return D( pos, 11 );
	if( pd[pos][mask] != -1 ) return pd[pos][mask];
	int ans = INF;
	rep( i, 0, n ){
		if( mask & ( 1 << i )) continue;
		ans = min( ans, solve( i, mask | ( 1 << i )) + D( pos, i ) );
	}
	return pd[pos][mask] = ans;
}

int main(){
	
	int t;
	cin >> t;
	while( t-- ){
		cin >> x[11] >> y[11];
		cin >> x[11] >> y[11];
		cin >> n;
		rep( i, 0, n ){
			cin >> x[i] >> y[i];
		}		
		memset( pd, -1, sizeof pd );
		printf("The shortest path has length %d\n", solve( 11, 0 ) );
	}
	
}

