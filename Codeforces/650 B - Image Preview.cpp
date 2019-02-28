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
#define N 500500
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int n, a, b, T;
int cost[2*N];
char s[N];

int solve(){
	cost[n] = 1 + b * ( s[0] == 'w' );
	for( int i = n+1; i < 2*n; i++ ){
		cost[i] = 1 + a + cost[i-1] + b * ( s[i-n] == 'w' );
	}
	int st = n, ed = n, ans = 0;
	for( int i = n-1; i >= 0; i-- ){
		cost[i] = 1 + 2*a + cost[i+1] + b * ( s[i] == 'w' );
		if( T >= cost[i] ) st = i, ans++;
	}
	while( st <= n && ed < 2*n ){
		if( cost[st] + cost[ed] - cost[n] <= T ){
			ans = max( ans, ed-st+1 );
			ed++;
		}
		else st++;
	}
	return min( ans, n );
}

int main(){
	
	while( scanf("%d%d%d%d", &n, &a, &b, &T ) != EOF ){
		scanf("%s", s );
		int ans = solve();
		reverse( s+1, s+n );
		ans = max( ans, solve());
		printf("%d\n", ans );
	}
}
