#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int n, m;
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
char mat[1111][1111];
int dist[1111][1111];

int dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != 'T';
}

void bfs( int x, int y ){
	queue<ii> q;
	q.push( ii(x, y) );
	memset( dist, -1, sizeof dist );
	dist[x][y] = 0;
	while( !q.empty() ){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) && dist[xx][yy] == -1 ){
				dist[xx][yy] = dist[x][y]+1;
				q.push( ii(xx, yy) );
			}
		}
	}
	
}

int main(){
	
	int sx, sy, ex, ey;
	scanf("%d%d", &n, &m );
	rep( i, 0, n ) scanf("%s", mat[i] );
	rep( i, 0, n )
		rep( j, 0, m )
			if( mat[i][j] == 'S' ) sx = i, sy = j;
			else if( mat[i][j] == 'E' ) ex = i, ey = j;
	int ans = 0;
	bfs( ex, ey );
	rep( i, 0, n )
		rep( j, 0, m )
			if( isdigit(mat[i][j]) && dist[i][j] <= dist[sx][sy] && dist[i][j] != -1 ) 
				ans += mat[i][j]-'0';
	cout << ans << endl;
}

