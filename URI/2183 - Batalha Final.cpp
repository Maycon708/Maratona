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

int pd[110][110][32][11], k, n, dx[] = { 1, 0 }, dy[] = { 0, 1 };
char mat[110][110];

inline bool fora( int x, int y ){
	return x < 0 || x >= n || y < 0 || y >= n || mat[x][y] == '#';
}

inline int C( char c ){
	if( c == 'P' ) return 0;
	if( c == 'O' ) return 1;
	if( c == 'W' ) return 2;
	if( c == 'E' ) return 3;
	if( c == 'R' ) return 4;
}

int solve( int x, int y, int mask, int t ){
	if( mat[x][y] == 'F' ) return 0;
	if( pd[x][y][mask][t] != -1 ) return pd[x][y][mask][t];
	int ans = INF;
	rep( i, 0, 2 ){
		int xx = x + dx[i], yy = y + dy[i];
		if( fora( xx, yy ) ) continue;
		if( isdigit( mat[xx][yy] ) ){
			if( t ) ans = min( ans, solve( xx, yy, mask, t-1 ) );
			else ans = min( ans, solve( xx, yy, mask, 0 ) + ( mat[xx][yy] - '0' ) ); 
		}	
		else{
			int aux = mask | ( 1 << C( mat[xx][yy] ) );
			if( aux == 31 ) ans = min( ans, solve( xx, yy, 0, k ) );
			else ans = min( ans, solve( xx, yy, aux, max( t-1, 0 ) ));
		}
	}
	return pd[x][y][mask][t] = ans;
}

int main(){
	while( scanf("%d%d", &n, &k ) != EOF ){
		rep( i, 0, n ){
			rep( j, 0, n ){
				memset( pd[i][j], -1, sizeof pd[i][j] );
				cin >> mat[i][j];
			}
		}
		mat[0][0] = '0';
		int ans = solve( 0, 0, 0, 0 );
		if( ans >= INF ) printf("-1\n");
		else printf("%d\n", ans + 1 );
	}
}

