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

int w, h, mat[111][111], sx, sy, rx, ry, ans;
int vis[111][111][1<<8];
char s[111][111];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool dentro( int x, int y ){
	return x >= 0 && x < h && y >= 0 && y < w;
	
}

void bfs( int k ){
	queue< pair<ii,ii> > q;
	q.push( mk( ii( sx, sy ), ii( 0, k ) ) );
	while( !q.empty() ){
		int x = q.front().F.F, y = q.front().F.S;
		int mask = q.front().S.F, k = q.front().S.S;
		q.pop();
		if( x == rx && y == ry ) ans = max( ans, __builtin_popcount(mask) );
		if( vis[x][y][mask] || !k ) continue;
		vis[x][y][mask] = 1;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) && s[xx][yy] != '#' ){
				int aux = mask;
				if( mat[xx][yy] != -1 ) aux |= ( 1 << mat[xx][yy] );
				q.push( mk( ii( xx, yy ), ii( aux, k-1 ) ) );
			} 
		}
	}
}

int main(){

	int n, m;
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		scanf("%d%d", &w, &h );
		rep( i, 0, h ) scanf("%s", s[i] );
		int cnt = 0;
		ans = -1;
		memset( vis, 0, sizeof vis );
		memset( mat, -1, sizeof mat );
		rep( i, 0, h )
			rep( j, 0, w )
				if( s[i][j] == '*' ) mat[i][j] = cnt++;
				else if( s[i][j] == 'R' ) sx = i, sy = j;
				else if( s[i][j] == 'S' ) rx = i, ry = j;
		bfs(m);
		printf("%d\n", ans );
	}
	
}
