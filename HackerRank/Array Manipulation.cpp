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

ll bit[10001001];
int n;

void update( int x, ll v ){
	for( int i = x; i <= n; i += (i&-i) ) bit[i] += v;
}

ll query(){
	ll ans = 0;
	for( int i = 2; i <= n; i++ ){
		bit[i] += bit[i-(i&-i)];
		ans = max( ans, bit[i] );
	}
	return ans;
}

int main(){
	int q, a, b, v;
	while( scanf("%d%d", &n, &q ) != EOF ){
		while( q-- ){
			scanf("%d%d%d", &a, &b, &v );
			update( a, v );
			update( b+1, -v );
		}
		printf("%lld\n", query() );
	}
}
