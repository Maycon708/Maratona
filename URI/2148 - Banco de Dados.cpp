#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
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

int n;
ll pd[20][100];

ll solve( int pos, int rest ){
	if( pos == n ) return !rest;
	if( pd[pos][rest] != -1 ) return pd[pos][rest];
	ll ans = 0;
	rep( i, 1, min( 6, rest )+1 ){
		ans += solve( pos+1, rest-i );
	}
	return pd[pos][rest] = ans;
}

int main(){

	int t, a;
	cin >> t;
	while( t-- ){
		cin >> a >> n;
		memset( pd, -1, sizeof pd );
		ll ans = solve( 0, a );
		cout << fixed << setprecision(15) <<  ans / ( long double ) powl( 6.0, n ) << "\n";
	}

}
