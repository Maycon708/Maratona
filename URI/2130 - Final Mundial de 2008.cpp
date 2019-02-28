#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 111
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int m[MAXV][MAXV][MAXV], V;

void floyd(){
    rep( k, 1, V+1 )
		rep( i, 0, V+1 )
		    rep( j, 0, V+1 )
		        m[i][j][k] = min( m[i][j][k-1], m[i][k][k-1] + m[k][j][k-1] ); 
		    
}


int main(){
	int M, u, v, c, k, t = 1;
	while( scanf("%d%d", &V, &M ) != EOF ){
		rep( i, 0, V+1 ){
			rep( j, 1, V+1 ){
				rep( k, 0, V+1 ){
					if( i == j ) m[i][j][k] = 0;
					else m[i][j][k] = INF;
				}
			}
		}
		while( M-- ){
			scanf("%d%d%d", &u, &v, &c );
			m[u][v][0] = min( m[u][v][0], c ); 
		}
		floyd();
		int q;
		scanf("%d", &q );
		printf("Instancia %d\n", t++ );
		while( q-- ){
			scanf("%d%d%d", &u, &v, &k );
			if( m[u][v][k] == INF ) printf("-1\n");
			else
				printf("%d\n", m[u][v][k] );
		}
		printf("\n");
	}
}


