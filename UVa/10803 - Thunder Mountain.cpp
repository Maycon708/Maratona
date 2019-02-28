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
typedef pair<double, int> di;

int main(){
	int t, n, x[200], y[200], test = 1;
	double m[200][200];
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		rep( i, 0, n ){
			scanf("%d%d", &x[i], &y[i] );
		}
		rep( i, 0, n ){
			rep( j, 0, n ){
				m[i][j] = INF;
			}
			m[i][i] = 0;
		}
		
		rep( i, 0, n ){
			rep( j, i+1, n ){
				int dx = x[i] - x[j], dy = y[i] - y[j];
				double d = dx*dx + dy*dy;
				if( d <= 100 ){
					d = sqrt(d);
					m[i][j] = m[j][i] = d;
				}
			}
		}
		rep( k, 0, n ){
			rep( i, 0, n ){
				rep( j, 0, n ){
					m[i][j] = min( m[i][j], m[i][k] + m[k][j] );
				}
			}
		}
		double ans = 0;
		rep( i, 0, n )
			rep( j, 0, n )
				ans = max( ans, m[i][j] );
		printf("Case #%d:\n", test++ );
		if( ans > 100000 ) printf("Send Kurdy\n\n");
		else printf("%.4f\n\n", ans );
	}
}

