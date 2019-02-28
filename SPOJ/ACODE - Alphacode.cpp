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

ll pd[5005];
string s;

ll solve( int p ){
	if( p == s.size() ) return 1LL;
	if( pd[p] != -1 ) return pd[p];
	ll ans = 0, aux = 0;
	rep( i, p, s.size() ){
		aux *= 10;
		aux += ( s[i] - '0' );
		if( aux > 26 ) break;
		if( s[i+1] != '0' ) ans += solve( i+1 );
	}
	return pd[p] = ans;		
}

int main(){
	while( cin >> s && s != "0" ){
		memset( pd, -1, sizeof pd );
		printf("%lld\n", solve(0) );
	}
}

