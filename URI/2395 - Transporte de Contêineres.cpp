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

int main(){
	ll x, y, z, a, b, c;
	while( cin >> a >> b >> c ){
		cin >> x >> y >> z;
		ll ans = (x/a) * (y/b) * (z/c);
/*		ans = max( ans, (x/a) * (y/c) * (z/b) );
		ans = max( ans, (x/b) * (y/a) * (z/c) );
		ans = max( ans, (x/b) * (y/c) * (z/a) );
		ans = max( ans, (x/c) * (y/a) * (z/b) );
		ans = max( ans, (x/c) * (y/b) * (z/a) );
*/		printf("%lld\n", ans );
	}
}

