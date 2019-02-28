#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debug3(x,y,z) cout << #x << " = " << x << " --- " << #y << " = " << y << " --- " << #z << " = " << z << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int N = 505;

int n, v[N], pd[N], pd2[N][N], mn[N][N], f[N][N];

inline bool check( int a, int b ){
	int tam = abs( a - b ) + 1;
	vector<int> aux( N, 0 );
	rep( i, a, b+1 ){
		if( v[i] > tam ) return 0;
		aux[ v[i] ] = 1;
	}
	rep( i, 1, tam+1 ){
		if( !aux[i] ) return 0;
	}
	return 1;
}

inline int cost( int i, int k, int j ){
	int a = mn[i][k], b = mn[k+1][j];
	int aux;
	if( a < b ) aux = abs( f[i][b-1] - f[k+1][b-1] );
	else aux = abs( f[k+1][a-1] - ( ( j+1 < n ) ? f[j+1][a-1] : 0 ) );
	return abs( ( j - i + 1 ) - aux );
}

int S2( int i, int j ){
	if( i == j ) return 0;
	if( pd2[i][j] != -1 ) return pd2[i][j];
	int ans = INF;
	
	int a = 1, b = INF;
	rep( k, i, j ){
		ans = min( ans, S2( i, k ) + S2( k+1, j ) + cost( i, k, j ) );
	}
	return pd2[i][j] = ans;
}

int S( int pos ){
	if( pos == n ) return 0;
	if( pd[pos] != -1 ) return pd[pos];
	pd[pos] = INF;
	rep( i, pos, n ){
		if( check( pos, i ) ) pd[pos] = min( pd[pos], S( i+1 ) + S2( pos, i ) );
	}
	return pd[pos];
}

int main(){
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			pd[i] = -1;
			rep( j, 0, N ) pd2[i][j] = -1, f[i][j] = 0;
		}
		rep( i, 0, n ){
			int m = v[i];
			rep( j, i, n ){
				f[i][ v[j] ]++;	
				m = min( m, v[j] );
				mn[i][j] = m;
			}
		}
		rep( i, 0, n )
			rep( j, 2, n )
				f[i][j] += f[i][j-1];
		
		int ans = S(0);
		if( ans >= INF ) printf("impossible\n");
		else printf("%d\n", ans );
	}
}

