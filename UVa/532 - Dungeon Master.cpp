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

int a, b, c, vis[33][33][33];
char m[33][33][33];
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

bool dentro( int x, int y, int z ){
	return x >= 0 && x < a && y >= 0 && y < b && z >= 0 && z < c && m[x][y][z] != '#';
}

int bfs( int x, int y, int z ){
	queue< pair<ii, ii> > q;
	q.push( mk( ii( x, y ), ii( z, 0 ) ));
	while( !q.empty() ){
		x = q.front().F.F;
		y = q.front().F.S;
		z = q.front().S.F;
		int c = q.front().S.S;
		q.pop();
		if( vis[x][y][z] ) continue;
		vis[x][y][z] = 1;
		if( m[x][y][z] == 'E' ) return c;
		rep( i, 0, 6 ){
			int xx = x + dx[i], yy = y + dy[i], zz = z + dz[i];
			if( dentro( xx, yy, zz ) ) q.push( mk( ii( xx, yy ), ii( zz, c+1 ) ) );
		}
	}
	return -1;
}

int main(){
	int x, y, z;
	while( scanf("%d%d%d", &a, &b, &c ) != EOF && a ){
		rep( i, 0, a )
			rep( j, 0, b )
				scanf("%s", m[i][j] );
		rep( i, 0, a ){
			rep( j, 0, b ){
				rep( k, 0, c ){
					vis[i][j][k] = 0;
					if( m[i][j][k] == 'S' ) x = i, y = j, z = k;
				}
			}
		}
		int ans = bfs(x, y, z);
		if( ans == -1 ) puts("Trapped!");
		else printf("Escaped in %d minute(s).\n", ans );
	}
}
