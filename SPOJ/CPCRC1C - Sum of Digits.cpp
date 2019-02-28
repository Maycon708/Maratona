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

ll pd[20][9*16][2]; 
string s;

ll solve( int pos, ll t, bool pre ){
	if( pos == s.size() ) return t;
	if( pd[pos][t][pre] != -1 ) return pd[pos][t][pre];
	ll ans = 0;
	if( pre ){
		int c = s[pos] - '0';
		rep( i, 0, c ) ans += solve( pos+1, t+i, 0 );
		ans += solve( pos+1, t+c, 1 );
	}
	else{
		rep( i, 0, 10 ) ans += solve( pos+1, t+i, 0 );
	}
	return pd[pos][t][pre] = ans;
}

int main(){
	
	int t;
	string a;
	
//	cin >> t;
	while( cin >> a >> s ){
		if( a == "-1" && s == "-1" ) break;
		
		memset( pd, -1, sizeof pd );
		ll ans = solve( 0, 0, 1 );
		
		rep( i, 0, a.size() ) ans += a[i] - '0';
		
		s = a;
		memset( pd, -1, sizeof pd );
		ans -= solve( 0, 0, 1 );
		
		printf("%lld\n", ans );
	}
}	

