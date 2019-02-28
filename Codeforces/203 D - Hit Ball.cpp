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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	double a, b, m;
	double x, y, z;
	
	cin >> a >> b >> m;
	cin >> x >> y >> z;
	
	x = a/2+x*m/-y;
	z = z*m/-y;
	
	while( x < 0 || x > a ){
		if( x > a ) x = 2*a-x;
		if( x < 0 ) x = -x;
	}
	
	while( z < 0 || z > b ){
		if( z > b ) z = 2*b-z;
		if( z < 0 ) z = -z;
	}
	
	printf("%.10f %.10f\n", x, z );
	
}
