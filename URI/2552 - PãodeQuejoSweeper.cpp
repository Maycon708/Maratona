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

int main(){
	int n, m, a;
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { -1, 1, 0, 0 };
	char mat[111][111];
	while( scanf("%d%d", &n, &m ) != EOF ){
		memset( mat, '0', sizeof mat );
		rep( i, 1, n+1 ){
			rep( j, 1, m+1 ){
				scanf("%d", &a );
				if( !a ) continue;
				mat[i][j] = '9';
				rep( k, 0, 4 ){
					int x = i + dx[k], y = j + dy[k];
					if( mat[x][y] != '9' ) mat[x][y]++;
				}
			}
			mat[i][m+1] = '\0';
		}
		rep( i, 1, n+1 ){
			rep( j, 1, m+1 ){
				printf("%c", mat[i][j] );
			}
			printf("\n");
		}
	}
}
