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

int n, v[111], p[111], pd[111][11111];

int solve( int i, int k ){
	if( i == n ) return 0;
	if( pd[i][k] != -1 ) return pd[i][k];
	pd[i][k] = solve( i+1, k );
	if( k >= p[i] ) pd[i][k] = max( pd[i][k], solve( i+1, k-p[i] ) + v[i] );
	return pd[i][k];
}

int main(){

	int k;

	while( scanf("%d%d", &n, &k ) != EOF ){
		rep( i, 0, n ) scanf("%d", &v[i] );
		rep( i, 0, n ) scanf("%d", &p[i] );
		memset( pd, -1, sizeof pd );
		printf("%d\n", solve( 0, k ) );
	}
}
