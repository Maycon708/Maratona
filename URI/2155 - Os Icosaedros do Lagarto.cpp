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

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

inline int cmp( long double x, long double y = 0, double tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

int main(){
	
	long double dist[10][10];
	int t, x[10], y[10], a, b, c;
	cin >> t;
	rep( T, 1, t+1 ){
		scanf("%d%d", &x[3], &y[3] );
		rep( i, 0, 6 ){
			scanf("%d%d%d", &a, &b, &c );
			a--; x[a] = b, y[a] = c;
		}	
		rep( i, 0, 7 )
			rep( j, 0, 7 )
				dist[i][j] = hypot( x[i] - x[j], y[i] - y[j] );
		
		double ans = INF;
		vector< int > v;
		
		rep( i, 0, 7 ){
			if( i == 3 ) continue;
			rep( j, 0, 7 ){
				if( j == i || j == 3 ) continue;
				rep( k, 0, 7 ){
					if( k == i || k == j || k == 3 ) continue;
					rep( l, 0, 7 ){
						if( l == i || l == j || l == k || l == 3 ) continue;
						rep( m, 0, 7 ){
							if( m == i || m == j || m == k || m == l || m == 3 ) continue;
							rep( n, 0, 7 ){
								if( n == i || n == j || n == k || n == l || n == m || n == 3 ) continue;
								double d = dist[3][i] + dist[i][j] + dist[j][k] + dist[k][l] + dist[l][m] + dist[m][n] + dist[n][3];
								if( cmp( d, ans ) == -1 ){
									ans = d;
									v.clear();
									v.pb( 3 );
									v.pb( i );
									v.pb( j );
									v.pb( k );
									v.pb( l );
									v.pb( m );
									v.pb( n );
									v.pb( 3 );
								}
							}
						}
					}
				}
			}
		}
	
	
		printf("Caso %d:\n", T );
		rep( i, 0, v.size() ){
			if( i ) printf("->");
			printf("%d", v[i]+1 );
		}
		printf(": %.5f\n", ans );
	}
}
