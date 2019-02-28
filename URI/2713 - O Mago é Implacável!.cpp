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

double pd[1111][111], atk;
int memo[1111][111], cnt, n, v[1111], a[1111];

double solve( int p, int m ){
	if( p == n ) return 0;
	if( memo[p][m] == cnt ) return pd[p][m];
	memo[p][m] = cnt;
	double &ans = pd[p][m];
	ans = solve( p+1, m ) + v[p]/atk;
	if( m ) ans = min( ans, solve( p+1, m-1 ) + v[p]/(atk+a[p]) );
	return ans;
}

int main(){
	int m;
	while( scanf("%d%d%lf", &n, &m, &atk ) != EOF ){
		rep( i, 0, n ) scanf("%d%d", &v[i], &a[i] );
		cnt++;
		printf("%.4f\n", solve(0, m ) );
	}
}
