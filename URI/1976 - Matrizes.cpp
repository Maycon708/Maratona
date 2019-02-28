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

int c[1010], l[1010], pd[1010][1010], mat[1010][1010], cnt[1010][1010];
bool aux;

int solve( int n ){
	rep( i, 0, n ) pd[i][i] = 0;
	rep( len, 1, n ){
		rep( i, 0, n - len + 1 ){
			int j = i + len;
			mat[i][j] = cnt[i][j] = 0;
			pd[i][j] = ( 1 << 30 );
			rep( k, i, j ){
				ll u = pd[i][k] + pd[k+1][j] + l[i] * c[k] * c[j];
				if( u < pd[i][j] ){
					pd[i][j] = u;
					mat[i][j] = k;
					cnt[i][j] = 0;
				}
				if( u == pd[i][j] ) cnt[i][j]++;
			}
		}
	}
	rep( i, 0, n ){
		rep( j, 0, n )
			if( cnt[i][j] > 1 ) aux = 1;
		if( aux ) break;
	}
	return pd[0][n-1];
}

void bck( int i, int j ){
	if( i == j ){
		printf("A%d", i+1 );
		return;
	}
	int k = mat[i][j];
	mat[i][j] = 0;
	printf("(");
	bck( i, k );
	bck( k+1, j );
	printf(")");
}
	
int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		rep( i, 0, n ){
			scanf("%lld%lld", &l[i], &c[i] );
		}
		aux = 0;
		int ans = solve( n );
		if( aux ) printf("%d", ans );
		else bck( 0, n-1 );
		printf("\n");
	}
}

