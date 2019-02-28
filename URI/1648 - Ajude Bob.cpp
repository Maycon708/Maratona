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

#define M 16

int main(){
	int m, p[M], a[M], n, x, y;
	double d[M][M], dp[1<<M];
	
	while( scanf("%d", &m ) != EOF && m ){
		rep( i, 0, m ) rep( j, 0, m ) d[i][j] = 1;
		rep( i, 1, 1<<m ) dp[i] = INF;
		rep( i, 0, m ){
			scanf("%d%d%d", &p[i], &a[i], &n );
			rep( j, 0, n ){
				scanf("%d%d", &x, &y );
				x--;
				d[i][x] *= ( 100 - y )/100.0;
			}
		}
		double ans = INF;
		rep( mask, 0, 1 << m ){
			double area = 0;
			rep( i, 0, m ){
				if( mask & ( 1 << i ) ) area += a[i];
				else{
					double cost = p[i];
					rep( j, 0, m )	if( mask & ( 1 << j ) ) cost *= d[j][i];
					dp[mask|(1<<i)] = min( dp[mask|(1<<i)], dp[mask] + cost );
				}
			}
			if( mask ) ans = min( ans, dp[mask]/area );
		}
		printf("%.4f\n", ans );
	}
}

