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

ll pd[2010][4010];
int memo[2010][4010], cnt, a[2010], b[2010], n;

ll solve( int p, int t ){
	if( t - 2000 >= n-p ) return 0;
	if( p == n ) return 1LL << 60;
	if( memo[p][t] == cnt ) return pd[p][t];
	memo[p][t] = cnt;
	return pd[p][t] = min( b[p] + solve(p+1, t+a[p]), solve(p+1, t-1) );
}

int main(){
	while( scanf("%d", &n ) != EOF	 ){
		rep( i, 0, n ) scanf("%d%d", &a[i], &b[i] );
		cnt++;
		printf("%lld\n", solve(0, 2000) );
	}
}
