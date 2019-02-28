#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int n, m;

int dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
	
	int mat[111][111], t = 1;
	char f[111][111];
	int dx[] = { 1, 1,  1,  0, 0, -1, -1, -1 };
	int dy[] = { 1, 0, -1, -1, 1, -1,  0,  1 };
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		if( t != 1 ) printf("\n");
		rep( i, 0, n ){
			scanf("%s", f[i] );
			rep( j, 0, m ){
				if( f[i][j] == '*' ) mat[i][j] = -1;
				else mat[i][j] = 0;
			}
		}
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( mat[i][j] == -1 ){
					rep( k, 0, 8 ){
						int x = i + dx[k], y = j + dy[k];
						if( dentro( x, y ) && mat[x][y] != -1 ) mat[x][y]++;
					}
				}
			}
		}		

		printf("Field #%d:\n", t++ );
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( mat[i][j] == -1 ) printf("*");
				else printf("%d", mat[i][j] );
			}
			printf("\n");
		}
	}

}

