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

ll eleva( ll b, ll e ){
	ll ans = 1;
	while( e ){
		if( e&1 ) ans *= b;
		b *= b;
		e >>= 1;
	}
	return ans;
}

int main(){
	string s;
	int t = 1;
	while( cin >> s ){
		ll a = 0;
		int n = s.size();
		rep( i, 0, n ){
			if( s[i] == 'b'){
				a += eleva( 2, n-i-1 );
			}
		}
		printf("Palavra %d\n", t++ );
		printf("%lld\n", a );
		printf("\n");
	}
}

