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

int pd[40][800][800], V[44], A[44], n;

int solve( int p, int v, int a ){
	if( p == n ) return 0;
	if( pd[p][v][a] != -1 ) return pd[p][v][a];
	int ans = solve( p+1, v, a );
	if( V[p] < 0 && v + V[p] >= 0 ) ans = max( ans, solve( p+1, v+V[p], a+A[p] ) + 1 );
	if( A[p] < 0 && a + A[p] >= 0 ) ans = max( ans, solve( p+1, v+V[p], a+A[p] ) + 1 ); 
	return pd[p][v][a] = ans;
}

int main(){

	int a, v;
	while( scanf("%d", &n ) != EOF ){
		scanf("%d%d", &v, &a );
		rep( i, 0, n ) scanf("%d%d", &V[i], &A[i] ), memset( pd[i], -1, sizeof pd[i] );
		printf("%d\n", solve( 0, v, a ) );
	}

}
