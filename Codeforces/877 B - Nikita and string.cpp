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

string s;
int pd[5555][3];

int C( int p, int t ){
	if( t&1 ) return s[p] == 'b';
	return s[p] == 'a';
}

int solve( int p, int t ){
	if( p == s.size() ) return 0;
	int &ans = pd[p][t];
	if( ans == -1 ){
		ans = solve( p+1, t ) + C(p, t);
		if( t < 2 )
			ans = max( ans, solve( p+1, t+1 ) + C(p, t) );
	}
	return ans;
}

int main(){
	while( cin >> s ){
		memset( pd, -1, sizeof pd );
		int ans = max( solve( 0, 0 ), solve( 0, 1 ));
		printf("%d\n", ans );
	}
}
