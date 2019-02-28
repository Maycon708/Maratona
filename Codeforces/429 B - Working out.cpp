#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

ll pd1[1010][1010];
ll pd2[1010][1010];
ll pd3[1010][1010];
ll pd4[1010][1010];
ll mat[1010][1010], n, m;

ll solve1( int x, int y ){
	if( x == 1 && y == 1 ) return mat[x][y];
	ll &ans = pd1[x][y];
	if( ans == -1 ){
		if( x > 1 ) ans = solve1( x-1, y );
		if( y > 1 ) ans = max( ans, solve1(x, y-1) );
		ans += mat[x][y];
	}
	return ans;
}


ll solve2( int x, int y ){
	if( x == n && y == m ) return mat[x][y];
	ll &ans = pd2[x][y];
	if( ans == -1 ){
		if( x < n ) ans = solve2( x+1, y );
		if( y < m ) ans = max( ans, solve2(x, y+1) );
		ans += mat[x][y];
	}
	return ans;
}

ll solve3( int x, int y ){
	if( x == 1 && y == m ) return mat[x][y];
	ll &ans = pd3[x][y];
	if( ans == -1 ){
		if( x > 1 ) ans = solve3( x-1, y );
		if( y < m ) ans = max( ans, solve3(x, y+1) );
		ans += mat[x][y];
	}
	return ans;
}

ll solve4( int x, int y ){
	if( x == n && y == 1 ) return mat[x][y];
	ll &ans = pd4[x][y];
	if( ans == -1 ){
		if( x < n ) ans = solve4( x+1, y );
		if( y > 1 ) ans = max( ans, solve4(x, y-1) );
		ans += mat[x][y];
	}
	return ans;
}

int main(){
	
	cin >> n >> m;
	rep( i, 1, n+1 ) rep( j, 1, m+1 ) cin >> mat[i][j];
	ll ans = 0;
	memset( pd1, -1, sizeof pd1 );
	memset( pd2, -1, sizeof pd2 );
	memset( pd3, -1, sizeof pd3 );
	memset( pd4, -1, sizeof pd4 );
	rep( x, 2, n ) rep( y, 2, m ) ans = max( ans, solve1( x-1, y ) + solve2( x+1, y ) + solve3( x, y+1 ) + solve4(x, y-1) );
	rep( x, 2, n ) rep( y, 2, m ) ans = max( ans, solve1( x, y-1 ) + solve2( x, y+1 ) + solve3( x-1, y ) + solve4(x+1, y) );
	cout << ans << endl;
}
