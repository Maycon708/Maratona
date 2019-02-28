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

double C( double a ){
	return ( a * M_PI ) / 180.0;
}

int main(){
	double a, d, r;
	while( scanf("%lf%lf%lf", &a, &d, &r ) != EOF ){
		if( r < 90 ){
			r = C(r);
			printf("%.4f\n", a - d / tan(r) );
		}
		else if( r > 90 ){
			r = C(r);
			printf("%.4f\n", a + d * tan(r-M_PI/2) );
		}
		else printf("%.4f\n", a );
	}
}

