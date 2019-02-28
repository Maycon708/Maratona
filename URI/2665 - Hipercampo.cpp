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

bool cmp( ii a, ii b ){
	if( a.S != b.S ) return a.S < b.S;
	return a.F < b.F; 
}

ii calc( ii a, ii b ){
	return ii( b.F-a.F, b.S-a.S );
}

int cross( ii a, ii b ){
	return a.F*b.S - a.S*b.F;
}

bool p2t( ii p, ii a, ii b, ii c ){
	ii ap = calc( a, p );
	ii ab = calc( a, b );
	ii bp = calc( b, p );
	ii bc = calc( b, c );
	ii cp = calc( c, p );
	ii ca = calc( c, a );
	return cross( ab, ap ) > 0 && cross( bc, bp ) > 0 && cross( ca, cp ) > 0;
}

int main(){
	
	int n, pd[111];
	ii a, b, v[111];
	
	while( scanf("%d%d%d", &n, &a.F, &b.F ) != EOF ){
		a.S = 0, b.S = 0;
		rep( i, 0, n ) scanf("%d%d", &v[i].F, &v[i].S );
		sort( v, v+n, cmp );
		int ans = 0;
		rep( i, 0, n ){
			pd[i] = 1;
			rep( j, 0, i ){
				if( p2t( v[j], a, b, v[i] ) ) pd[i] = max( pd[i], pd[j]+1 ); 
			}
			ans = max( ans, pd[i] );
		}
		printf("%d\n", ans );
	}
}
