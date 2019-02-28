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

double dist( int x1, int y1, int x2, int y2 ){
	return hypot( x1-x2, y1-y2 );
}

int main(){
	int xi, yi, xf, yf, v, xl, yl, xr, yr;
	while( scanf("%d%d%d%d%d", &xi, &yi, &xf, &yf, &v ) != EOF ){
		scanf("%d%d%d%d", &xl, &yl, &xr, &yr );
		double d = min( dist(xi, yi, xl, yl) + dist(xr, yl, xf, yf ), dist(xi, yi, xl, yr) + dist(xr, yr, xf, yf) ) + xr-xl;
		printf("%.1f\n", d/v ); 
	}
}
