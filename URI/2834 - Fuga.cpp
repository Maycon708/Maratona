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

int vis[20][20], n, m, xf, yf, xi, yi, ans;
int dx[] = { 2, -2, 0, 0 }, dy[] = { 0, 0, 2, -2 };

void solve( int x, int y, int c ){
	if( x == xf && y == yf ){
		ans = max( ans, c );
		return;
	}
	rep( i, 0, 4 ){
		int xx = x + dx[i], yy = y + dy[i];
		if( xx > 0 && xx <= n && yy > 0 && yy <= m && !vis[xx][yy] ){
			vis[xx][yy] = 1;
			solve( xx, yy, c+2 );
			vis[xx][yy] = 0;
		}  
	}
}

int main(){
	while( scanf("%d%d", &n, &m ) != EOF ){
		ans = 0;
		scanf("%d%d%d%d", &xi, &yi, &xf, &yf );
		vis[xi][yi] = 1;
		solve(xi, yi, 0);
		cout << ans+1 << endl;
	}
}
