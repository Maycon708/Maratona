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

int n, m, mat[505][505];

int bb1( int i, int v ){
	int a = 0, b = m-1, c;
	while( a < b ){
		c = ( a + b ) >> 1;
		if( mat[i][c] < v ) a = c+1;
		else b = c;
	}	
	return b;
}

int bb2( int i, int j, int v ){
	int a = 0, b = min( n-i, m-j )-1, c;
	while( a < b ){
		c = ( a + b + 1 ) >> 1;
		if( mat[i+c][j+c] > v ) b = c-1;
		else a = c;
	}
	return a+1;
}

int main(){
	int q, a, b;
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		rep( i, 0, n ){
			rep( j, 0, m ){
				scanf("%d", &mat[i][j] );
			}
		}
		scanf("%d", &q );
		while( q-- ){
			scanf("%d%d", &a, &b );
			int ans = 0;
			rep( i, 0, n ){
				int j = bb1( i, a );
				if( mat[i][j] > b || mat[i][j] < a ) continue;
				ans = max( ans, bb2( i, j, b ) );
				if( n - i < ans ) break;
			}
			printf("%d\n", ans );
		}
		printf("-\n");
	}
}

