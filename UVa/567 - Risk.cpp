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
	int mat[30][30], n, q, u, v, test = 1;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 1, 21 )
			rep( j, 1, 21 )
				mat[i][j] = INF * ( i != j );
		rep( i, 0, n ){
			scanf("%d", &u );
			mat[1][u] = mat[u][1] = 1;
		}
		rep( i, 2, 20 ){
			scanf("%d", &n );
			rep( j, 0, n ){
				scanf("%d", &u );
				mat[i][u] = mat[u][i] = 1;
			}
		}
		rep( k, 1, 21 )
			rep( i, 1, 21 )
				rep( j, 1, 21 )
					mat[i][j] = min( mat[i][j], mat[i][k] + mat[k][j] );
		scanf("%d", &q );
		printf("Test Set #%d\n", test++ );
		while( q-- ){
			scanf("%d%d", &u, &v );
			printf("%2d to %2d: %d\n", u, v, mat[u][v] );
		}
		printf("\n");
	}
}
