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

ll bit[N][N], n, m;

void update( int x, int y, int v ){
	for( int i = x; i <= n; i += ( i&-i ))
		for( int j = y; j <= m; j += (j&-j )) 
			bit[i][j] += v;
}

ll query( int x, int y ){
	ll sum = 0;
	for( int i = x; i > 0; i -= ( i&-i ))
		for( int j = y; j > 0; j -= (j&-j )) 
			sum += bit[i][j];
	return sum;
}

ll _query( int a, int b, int c, int d ){
	ll ans = query( c, d );
	if( a ) ans -= query( a-1, d );
	if( b ) ans -= query( c, b-1 );
	if( a && b ) ans += query( a-1, b-1 );
	return ans;
}

void _update( int a, int b, int c, int d ){
	update( a, b, -1 );
	update( c, d, 1 );
}

int main(){
	int v, op, a, b, c, d;
	while( scanf("%lld%lld", &n, &m ) != EOF ){
		memset( bit, 0, sizeof bit );
		rep( i, 1, n+1 ){
			rep( j, 1, m+1 ){
				scanf("%d", &v );
				if( v ) update( i, j, v );
			}
		}
		scanf("%d", &v );
		while( v-- ){
			scanf("%d%d%d%d%d", &op, &a, &b, &c, &d );
			if( op ) printf("%lld\n", _query( a, b, c, d ) ); 
			else _update( a, b, c, d );
		}
	}
}
