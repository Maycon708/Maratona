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

#define NN 256

int g[NN][NN], v[NN], w[NN], na[NN], n;
bool a[NN];

int stoer_wagner(){
	for( int i = 0; i < n; i++ ) v[i] = i;
	ll best = INF;
	while( n > 1 ){
		a[v[0]] = true;
		for( int i = 1; i < n; i++ ){
			a[v[i]] = false;
			na[i - 1] = i;
			w[i] = g[v[0]][v[i]];
		}
		int prev = v[0];
		for( int i = 1; i < n; i++ ){
			int zj = -1;
			for( int j = 1; j < n; j++ )
				if( !a[v[j]] && ( zj < 0 || w[j] > w[zj] ) )
					zj = j;
			a[v[zj]] = true;
			if( i == n - 1 ){
				best = min(best,ll( w[zj] ));
				for( int j = 0; j < n; j++ )
					g[v[j]][prev] = g[prev][v[j]] += g[v[zj]][v[j]];
				v[zj] = v[--n];
				break;
			}
			prev = v[zj];

			for( int j = 1; j < n; j++ ) if( !a[v[j]] ) w[j] += g[v[zj]][v[j]];
		}
	}
	return best;
}

int main(){
	
	int t, m, u, v, c;
//	freopen("out.txt", "r", stdin );
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &m );
		memset( g, 0, sizeof g );	
		while( m-- ){ 	
			scanf("%d%d%d", &u, &v, &c );
			u--, v--;
			g[u][v] = c, g[v][u] = c;
		}
		printf("%d\n", stoer_wagner() );
	}
}
