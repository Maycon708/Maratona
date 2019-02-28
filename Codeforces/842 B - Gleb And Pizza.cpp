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

inline int cmp( double x, double y = 0, double tol = 1e-9) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

int main(){
	double r, d, x, y, z, n;
	while( scanf("%lf%lf", &r, &d ) != EOF ){
		scanf("%lf", &n );
		d = r - d;
		int cnt = 0;
		rep( i, 0, n ){
			scanf("%lf%lf%lf", &x, &y, &z );
			double dist = sqrt(x * x + y * y);
			
			if( cmp(dist - z, d ) != -1 && cmp( dist + z, r ) != 1 )  cnt++;
		}
		printf("%d\n", cnt );
	}
}
