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

int main(){
	
	double p, a, b, c, d;
	int n;
	while( scanf("%lf%lf%lf%lf%lf%d", &p, &a, &b, &c, &d, &n ) != EOF ){
		double m = 0, f, ans = 0;
		rep( i, 1, n+1 ){
			f = p * ( sin( a * i + b ) + cos( c * i + d ) + 2 );
			ans = max( ans, m - f );
			m = max( m, f );
		}
		printf("%lf\n", ans );
	}
	
}

