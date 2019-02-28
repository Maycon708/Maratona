#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int mat[111][111][111], n, m, u, v, w, q;

int main(){
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		FOR( i, 0, n ){
			FOR( j, 0, n ){
				FOR( k, 0, n ) mat[i][j][k] = INF;
			}
			FOR( k, 0, n ) mat[k][i][i] = 0;
		}
		while( m-- ){
			scanf("%d%d%d", &u, &v, &w );
			mat[0][u][v] = mat[0][v][u] = min(w, mat[0][u][v]);
		}
		
		FOR(k, 1, n){
			FOR(i, 1, n)
				FOR(j, 1, n)
					mat[k][i][j] = mat[k-1][i][j];
			FOR(i, 1, n){
				FOR(j, 1, n){
					mat[k][i][j] = min( mat[k][i][j], mat[k][i][k] + mat[k][k][j] );
				}
			}
		}
		
		scanf("%d", &q );
		while(q--){
			scanf("%d%d%d", &u, &v, &w );
			printf("%d\n", mat[w][u][v] >= INF? -1 : mat[w][u][v] );
		}
	}
	
}
