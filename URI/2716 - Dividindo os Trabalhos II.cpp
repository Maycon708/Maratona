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

int pd[150][150*2000], n, v[150];
char memo[150][150*2000], cnt;

int solve( int p, int d ){
	if( d < 0 ) d *= -1;
	if( p == n ) return d;
	if( memo[p][d] == cnt ) return pd[p][d];
	memo[p][d] = cnt;
	return pd[p][d] = min( solve( p+1, d+v[p] ), solve( p+1, d-v[p] ));
}

int main(){
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) scanf("%d", &v[i] );
		cnt++;
		printf("%d\n", solve(0, 0) );
	}
}
