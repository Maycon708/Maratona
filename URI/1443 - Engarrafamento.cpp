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

int main(){
	
	int n, i, f;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		double x = 0, v = 0, t = 0;
		rep( j, 0, n ){
			scanf("%d%d", &i, &f );
			t = i - t;
			t = min( t, v/2 );
			x = x + v * t - t * t;
			v = v - 2 * t;
			t = f - i;
			double dt = min( t, 10.0-v );
			x = x + v * dt + dt * dt / 2;
			v = v + dt;
			if( dt < t ) x = x + v * ( t - dt );
			t = f;
		}
		printf("%.2f\n", x );
	}
	
}

