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

int pd[10001][10], n, mat[10001][10];

int solve( int x, int y ){
	if( x == n ) return y? INF:0;
	if( pd[x][y] != -INF ) return pd[x][y];
	int ans = solve( x+1, y ) + 30 - mat[x][y];
	if( y < 9 ) ans = min( solve( x+1, y+1 ) + 60 - mat[x][y], ans );
	if( y ) ans = min( ans, solve( x+1, y-1 ) + 20 - mat[x][y] );
	return pd[x][y] = ans;
}

int main(){
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		n /= 100;
		for( int i = 9; i >= 0; i-- ){
			rep( j, 0, n ){
				scanf("%d", &mat[j][i] );
				pd[j][i] = -INF;
			}
		}
		printf("%d\n\n", solve(0, 0));
	}
}

