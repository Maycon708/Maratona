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

ii v[20], s, e;
bool check;
bool used[20];
int t, n;
char ans[100];

void back( int p, int d ){
	if( p == t ){
		if( d == e.F ) check = 1;
		return;
	}
	for( int i = 0; i < n && !check; i++ ){
		if( !used[i] && d == v[i].F ) used[i] = 1, back( p+1, v[i].S ), used[i] = 0;
		if( !used[i] && d == v[i].S ) used[i] = 1, back( p+1, v[i].F ), used[i] = 0;
	}
} 
	
int main(){

	while( scanf("%d%d", &t, &n ) != EOF && t ){
		scanf("%d%d", &s.F, &s.S );
		scanf("%d%d", &e.F, &e.S );
		rep( i, 0, n ) scanf("%d%d", &v[i].F, &v[i].S );
		back( 0, s.S );
		if( check ) puts("YES");
		else puts("NO");
		check = 0;
	}
	
	 	
	return 0;
}
