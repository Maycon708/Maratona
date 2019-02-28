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
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

void busca( double x, double y, double dx, double dy, double a, double b, double &xx, double &yy ){
	double lo = 0, hi = 10000, mid;
	while( fabs(lo-hi) > 1e-9 ){
		mid = (lo+hi)/2.0;
		xx = x + dx*mid;
		yy = y + dy*mid;
		double result = (xx*xx)/(a*a) + (yy*yy)/(b*b);
		if( result > 1 ) hi = mid;
		else lo = mid;
	}
	if( fabs(xx) < 1e-9 ) xx = 0;
	if( fabs(yy) < 1e-9 ) yy = 0; 
}

typedef pair<double, double> dd;

int main(){
	
	double x, y, dx, dy, a, b;
	
	while( scanf("%lf%lf%lf%lf%lf%lf", &x, &y, &dx, &dy, &a, &b ) != EOF ){
		double xx, yy;
		busca( x, y, dx, dy, a, b, xx, yy );
		printf("%.3f %.3f\n", xx, yy );
		
		dd T = dd( a*a*yy, -b*b*xx );
		dd D = dd( dx, dy );
		
		double num = ( T.F * D.S - T.S * D.F ), den = ( T.F * D.F + T.S * D.S );
		double tangente = num/den;
		double theta = -2 * atan(tangente);
		double ddx = dx * cos(theta) + dy * -sin(theta), ddy = dx * sin(theta) + dy * cos(theta);
		busca( xx, yy, ddx, ddy, a, b, x, y );
		
		printf("%.3f %.3f\n", x, y );
		
	}
}
