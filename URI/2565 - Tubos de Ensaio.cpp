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

	int n;
	double v[1111];
	
	while( scanf("%d", &n ) != EOF ){
		double sum = 0, ans = 0;
		rep( i, 0, n ) scanf("%lf", &v[i] ), sum += v[i];
		sum /= n;
		rep( i, 0, n ) ans += fabs( v[i] - sum );
		rep( i, 0, n ){
			double aux = 0;
			rep( j, 0, n ) aux += fabs( v[j] - v[i] );
			ans = min( ans, aux );
		}
		printf("%.2f\n", ans );
	}
}
