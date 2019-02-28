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

int mat[110][110], n, vis[110][110];

bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < n;
}

int bfs( int x, int y ){
	memset( vis, 0, sizeof vis );
	queue<ii> q;
	int cnt = 0;
	int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
	q.push( ii( x, y ) );
	while( !q.empty() ){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		cnt++;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) && mat[xx][yy] >= mat[x][y] )
				q.push( ii( xx, yy ) );
		}
	}
	return cnt;
}

int main(){
	int x, y;
	while( scanf("%d", &n ) != EOF ){
		scanf("%d%d", &x, &y );
		x--, y--;
		rep( i, 0, n )
			rep( j, 0, n )
				scanf("%d", &mat[i][j] );
		printf("%d\n", bfs( x, y ) );
	}
}

