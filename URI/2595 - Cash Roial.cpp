#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for( int i = a; i < b; i++ )
#define pb push_back

int n, m;
char mat[1010][1010];

int count( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 'T';
}

void solve(){
	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int q, a, b;
	scanf("%d%d%d", &n, &m, &q );
	rep( i, 0, n ) scanf("%s", mat[i] );
	while( q-- ){
		scanf("%d%d", &a, &b );
		a--, b--;
		int cnt = 0;
		rep( i, 0, 8 ) cnt += count( a + dx[i], b + dy[i] );
		if( cnt >= 5 ) puts("GRRR");
		else puts("GG IZI");
	}
}

int main(){
	int t;
    scanf("%d", &t );
	while( t-- ) solve();
}
