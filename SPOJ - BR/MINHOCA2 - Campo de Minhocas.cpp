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

int n, m, pd[1005][1005][3], memo[1005][1005][3], test = 1, mat[1005][1005];

int solve( int x, int y, int r ){
	if( x == n-1 && y == m-1  ) return mat[x][y];
	if( memo[x][y][r] == test ) return pd[x][y][r];
	memo[x][y][r] = test;
	int ans = -INF;
	if( x != n-1 ) ans = max( ans, solve( x+1, y, 0 ) + mat[x][y] );
	if( r != 1 && y != m-1 ) ans = max( ans, solve( x, y+1, 2 ) + mat[x][y] );
	if( r != 2 && y != 0 ) ans = max( ans, solve( x, y-1, 1 ) + mat[x][y] );
	return pd[x][y][r] = ans;
}

int main(){
	while( scanf("%d%d", &n, &m ) != EOF && n+m ){
		rep( i, 0, n )
			rep( j, 0, m )
				scanf("%d", &mat[i][j] );
		printf("Teste %d\n", test );
		printf("%d\n\n", solve( 0, 0, 2 ) );
		test++;
	}
}

