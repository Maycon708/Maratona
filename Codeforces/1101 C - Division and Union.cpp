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
typedef pair <int, int> ii;

int t, n, g[100100], cnt, last, aux[100100];
pair<ii, int> v[100100];

int main(){
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		rep( i, 0, n ) scanf("%d%d", &v[i].F.F, &v[i].F.S ), v[i].S = i;
		sort( v, v+n );
		g[0] = 1; cnt = 0; last = v[0].F.S;
		for( int i = 1; i < n; i++ ){
			if( v[i].F.F <= last ) g[i] = g[i-1];
			else g[i] = 1-g[i-1], cnt++;
			last = max( last, v[i].F.S );
		}
		if( !cnt ) puts("-1");
		else{
			rep( i, 0, n ) aux[v[i].S] = g[i];
			rep( i, 0, n ) printf("%d ", aux[i]+1 );
			printf("\n");
		}
	}
}
