#include <stdio.h>

int n, m, mat[220][220], vis[220][220];
int cnt, dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

int dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs( int x, int y ){
	int xx, yy, i;
	if( vis[x][y] ) return;
	vis[x][y] = 1;
	cnt++;
	for( i = 0; i < 4; i++ ){
		xx = x + dx[i];
		yy = y + dy[i];
		if( dentro( xx, yy ) && mat[xx][yy] == mat[x][y] ) dfs( xx, yy );
	}
}

int min( int a, int b ){
	if( a < b ) return a;
	return b;
}

int main(){
	int i, j, ans;
	while( scanf("%d%d", &n, &m ) != EOF ){
		ans = 202 * 202;
		for( i = 0; i < n; i++ ){
			for( j = 0; j < m; j ++ ){
				vis[i][j] = 0;
				scanf("%d", &mat[i][j] );
			}
		}
		for( i = 0; i < n; i++ ){
			for( j = 0; j < m; j ++ ){
				if( !vis[i][j] ){
					cnt = 0;
					dfs( i, j );
					ans = min( ans, cnt );
				}
			}
		}
		printf("%d\n", ans );
	}
}

