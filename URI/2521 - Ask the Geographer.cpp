#include <bits/stdc++.h>

#define INF 30
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef pair <ll, ll>  ii;

double a, b, c, xc, yc;

double C( double x ){
	return x * acos(-1) / 180;
}

int main(){
	
	while( scanf("%lf%lf%lf", &a, &b, &c ) != EOF ){
		b = C(b), c = C(c);
		double aa = fabs( a * sin(c) * cos(b) ) < 1e-9 ? 0 : a * sin(c) * cos(b);
		double bb = a * sin(b);
		double cc = fabs( -a * cos(c) * cos(b) ) < 1e-9 ? 0 : -a * cos(c) * cos(b);
		printf("%.2f %.2f %.2f\n", aa, bb, cc );
	}	
}

