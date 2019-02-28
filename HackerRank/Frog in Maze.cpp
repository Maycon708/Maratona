#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
typedef double ld;

ld A[404][404], ans[404][404], base[404][404], start[404][404], prob[404][404], C[404][404];

void matMultiply( int op, int n ){
	rep( i, 0, n ) 
		rep( j, 0, n ){ 
			if( op ) A[i][j] = ans[i][j];
			else A[i][j] = base[i][j];
			C[i][j] = 0;
		}
	rep( k, 0, n )
		rep( i, 0, n )
			rep( j, 0, n )
				C[i][j] += A[i][k] * base[k][j];
	rep( i, 0, n ) 
		rep( j, 0, n ) 
			if( op ) ans[i][j] = C[i][j];
			else base[i][j] = C[i][j];
}

void matPower( int exp, int n ){
	rep( i, 0, n ) rep( j, 0, n ) base[i][j] = prob[i][j], ans[i][j] = (i==j);
	while( exp ){
		if( exp&1 ) matMultiply( 1,  n );
		matMultiply( 0, n );
		exp >>= 1;
	}
	rep( i, 0, n ) rep( j, 0, n ) prob[i][j] = ans[i][j];
}


int main(){
		
	int n, m, k, a[30][30], b[30][30], cnt = 0, i1, i2, j1, j2;
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	char mat[30][30];

	while( scanf("%d%d%d", &n, &m, &k ) != EOF ){
		cout << fixed << setprecision(10);
		rep( i, 0, n ){
			scanf("%s", mat[i] );
			rep( j, 0, m ) if( mat[i][j] != '#' ) a[i][j] = b[i][j] = cnt++;
		}
		rep( i, 0, cnt ){
			start[0][i] = 0; 
			rep( j, 0, cnt ) prob[i][j] = 0;
		}
		while( k-- ){
			scanf("%d%d%d%d", &i1, &j1, &i2, &j2 );
			swap( b[i1-1][j1-1], b[i2-1][j2-1] );
		}
		vector<int> end;
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( mat[i][j] == '#' ) continue;
				if( mat[i][j] == '%' ) end.pb( a[i][j] );
				if( mat[i][j] == '*' || mat[i][j] == '%' ){
					prob[a[i][j]][a[i][j]] = 1;
					continue;
				}
				if( mat[i][j] == 'A' ) start[0][a[i][j]] = 1;
				long double cnt = 0;
				rep( k, 0, 4 ){
					int xx = i + dx[k], yy = j + dy[k];
					if( xx >= 0 && xx < n && yy >= 0 && yy < m && mat[xx][yy] != '#' ) cnt++;
				}
				if( cnt == 0 ) prob[b[i][j]][b[i][j]] = 1;
				rep( k, 0, 4 ){
					int xx = i + dx[k], yy = j + dy[k];
					if( xx >= 0 && xx < n && yy >= 0 && yy < m && mat[xx][yy] != '#' ) prob[b[i][j]][a[xx][yy]] = 1/cnt;
				}
			}
		}
		matPower( 100000, cnt );
		ld ans[1][404];
		rep( j, 0, 404 ) ans[0][j] = 0;
		rep( k, 0, cnt )
			rep( j, 0, cnt )
				ans[0][j] += start[0][k] * prob[k][j];
		
		long double resp = 0;
		rep( i, 0, end.size() ) resp += ans[0][end[i]];
		cout << resp << endl;
	}
}
