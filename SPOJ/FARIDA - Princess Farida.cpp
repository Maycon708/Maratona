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
typedef unsigned long long int ll;

int main(){

	int t, n;
	ll v[100010];
	
	scanf("%d", &t );
	rep( tt, 1, t+1 ){
		
		scanf("%d", &n );
		rep( i, 0, n )
			scanf("%lld", &v[i] );
		
		v[1] = max( v[1], v[0] );
		rep( i, 2, n )
			v[i] = max( v[i-1], v[i] + v[i-2] );
		
		if( !n ){
			printf("Case %d: 0\n", tt );
			continue;
		}
		printf("Case %d: %llu\n", tt, v[n-1] );
	}

}

