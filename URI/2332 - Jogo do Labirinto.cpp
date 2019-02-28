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

int n, m, mat[55][55], vis[55][55][10];
int dx[] = { -1, 1, 0, 0, 0 }, dy[] = { 0, 0, -1, 1, 0 };

bool dentro( int x, int y ){
	return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs(){
	queue< pair<ii, int> > q;
	q.push( mk( ii(0, 0), 0 ));
	memset( vis, 0, sizeof vis );
	while( !q.empty() ){
		int x = q.front().F.F;
		int y = q.front().F.S;
		int t = q.front().S;
		q.pop();
		if( x == n-1 && y == m-1 ) return t;
		if( vis[x][y][t%10] ) continue;
		vis[x][y][t%10] = 1;
		rep( i, 0, 5 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( !dentro( xx, yy ) ) continue;
			if( ( mat[xx][yy] + t )%10 - ( mat[x][y] + t )%10 > 1  ) continue;
			q.push( mk( ii( xx, yy ), t+1 ) );
		}
	}
}

int main(){
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ){
			rep( j, 0, m ){
				scanf("%d", &mat[i][j] );
			}
		}
		printf("%d\n", bfs() );
	}
}

