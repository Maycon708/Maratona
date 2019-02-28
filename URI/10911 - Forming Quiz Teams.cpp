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

double dist[20][20], pd[1<<17];
int memo[1<<17], cnt, n;

double solve( int mask = 0, int ones = 0){
	if( ones == 2*n ) return 0;
	double &ans = pd[mask];
	if( memo[mask] != cnt ){
		memo[mask] = cnt;
		ans = INF;
		rep( i, 0, 2*n )
			rep( j, 0, 2*n )
				if( !(mask&(1<<i)) && !(mask&(1<<j)) && i != j )
					ans = min( ans, solve( mask | (1<< i) | (1 << j), ones + 2 ) + dist[i][j] );		
	}
	return ans;
}

int main(){
	int t, x[20], y[20];
	string s;
	while( scanf("%d", &n ) != EOF && n ){
		rep( i, 0, 2*n ){
			cin >> s;
			scanf("%d%d", &x[i], &y[i] );
		}
	
		rep( i, 0, 2*n ) rep( j, 0, 2*n ) dist[i][j] = hypot( x[i]-x[j], y[i]-y[j] );
		cnt++;
		printf("Case %d: %.2f\n", cnt, solve() );
	}
}
