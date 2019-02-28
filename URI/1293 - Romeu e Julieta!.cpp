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

double deg2Rad( double g ){
	return g * acos(-1)/180;
}

int main(){
	
	double x1, x2, y1, y2, a, b;
	while( scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &a, &b ) != EOF ){
		printf("%.3f\n", hypot( x1-x2, y1-y2 ) * ( tan(deg2Rad(90-a) ) + tan(deg2Rad(90-b) ) ) );
	}
	
}
