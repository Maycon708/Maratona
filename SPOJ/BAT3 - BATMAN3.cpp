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

int pd[1010], r, n, v[1010], t;

int solve( int pos ){
	if( pd[pos] != -1 ) return pd[pos];
	int ans = 0;
	rep( i, pos+1, n+1 ){
		if( v[pos] > v[i] ) ans = max( ans, solve( i ) + 1 );
		else if( pos == r ) ans = max( ans, solve( i ) + 1 );
	}
	return pd[pos] = ans;
}

int main(){
	
	v[0] = INF;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &r ); r++;
		rep( i, 1, n+1 ) scanf("%d", &v[i] );
		memset( pd, -1, sizeof pd );
		printf("%d\n", solve( 0 ) );
	}
}

