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

#define N 1505

ll bit[N][N];

void update( int x, int y, int v ){
	for( int i = x; i < N; i += ( i&-i ))
		for( int j = y; j < N; j += (j&-j )) 
			bit[i][j] += v;
}

ll query( int x, int y ){
	ll sum = 0;
	for( int i = x; i > 0; i -= ( i&-i ))
		for( int j = y; j > 0; j -= (j&-j )) 
			sum += bit[i][j];
	return sum;
}

int main(){
	int t, x, n, q, y, z, w, v;
	char op;
	while( scanf("%d%d", &n, &q ) != EOF ){
		memset( bit, 0, sizeof bit );
		rep( i, 1, n+1 ){
			rep( j, 1, n+1 ){
				scanf("%d", &v );
				if( v ) update( i, j, 1 );
			}
		}
		while( q-- ){
			scanf("%d%d", &x, &y );
			update(x, y, 1);
			scanf("%d%d%d%d", &x, &y, &v, &w );
			printf("%lld\n", query( v, w ) - query( x-1, w ) - query( v, y-1 ) + query( x-1, y-1 ) ); 
		}
	}
}
