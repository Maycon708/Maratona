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

map<int, int> pd[111];
int a[111], b[111], n, k;

int solve( int p, int dif ){
	if( p == n ) return (dif)? -INF : 0;
	if( pd[p].count(dif) ) return pd[p][dif];
	return pd[p][dif] = max( solve( p+1, dif ), solve( p+1, dif + a[p] - b[p]*k ) + a[p] );
}

int main(){
	while( scanf("%d%d", &n, &k ) != EOF ){
		rep( i, 0, n ) pd[i].clear();
		rep( i, 0, n ) scanf("%d", &a[i] );
		rep( i, 0, n ) scanf("%d", &b[i] );
		int ans = solve( 0, 0 );
		if( !ans ) puts("-1");
		else printf("%d\n", ans );
	}
}

