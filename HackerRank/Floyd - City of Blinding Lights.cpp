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

int main(){
	
	int n, m, u, v, c, mat[411][411];
	while( cin >> n >> m ){
		
		memset( mat, INF, sizeof mat );
		while( m-- ){
			cin >> u >> v >> c;
			u--, v--;
			mat[u][v] = c;
		}
		
		rep( i, 0, n ) mat[i][i] = 0;
		rep( k, 0, n ){
			rep( i, 0, n ){
				rep( j, 0, n ){
					mat[i][j] = min( mat[i][j], mat[i][k] + mat[k][j] );
				}
			}
		}
		int q;
		cin >> q;
		while( q-- ){
			cin >> u >> v;
			u--, v--;
			if( mat[u][v] == INF ) printf("-1\n");
			else printf("%d\n", mat[u][v] );
		}
	}
	
}

