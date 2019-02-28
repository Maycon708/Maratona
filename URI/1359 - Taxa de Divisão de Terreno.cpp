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

double pd[410][410], cost;
int sum[410], v[410];

double solve( int i, int j ){
	if( i == j ) return 0;
	if( pd[i][j] > -1 ) return pd[i][j];
	double ans = INF;
	rep( k, i, j ){
		double a = solve( i, k );
		double b = solve( k+1, j );
		int sa = sum[k];
		if( i ) sa -= sum[i-1];
		int sb = sum[j] - sum[k];
		ans = min( ans, a + b + max( sa, sb ) * cost );
	}	
	return pd[i][j] = ans;
}

int main(){
	int n;
	while( scanf("%d%lf", &n, &cost ) != EOF ){
		if( !n ) break;
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			sum[i] = v[i];
			if( i ) sum[i] += sum[i-1];
		}
		rep( i, n, 2*n ){
			v[i] = v[i-n];
			sum[i] = v[i] + sum[i-1];
		}
		rep( i, 0, 2*n ){
			rep( j, 0, 2*n ){
				pd[i][j] = -INF;
			}
		}
		double ans = INF;
		rep( i, 0, n ){
			ans = min( ans, solve( i, i+n-1 ) );
		}
		printf("%.2f\n", ans );
	}
}

