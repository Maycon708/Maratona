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

int n, m;
char mat[55][55];
bool vis[55][55];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

inline bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != 'X';
}

void bfs( int x, int y ){
	queue<ii> q;
	q.push( ii( x, y ) );
	while( !q.empty() ){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		mat[x][y] = 'T';
		vis[x][y] = 1;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) ) q.push( ii( xx, yy ));
		}
	}
}

int main(){
	while( scanf("%d%d", &n, &m ) != EOF && n+m ){
		memset( vis, 0, sizeof vis );
		rep( i, 0, n ) scanf("%s", mat[i] );
		rep( i, 0, n )
			rep( j, 0, m )
				if( mat[i][j] == 'T' ) bfs( i, j );
		rep( i, 0, n ) printf("%s\n", mat[i] );
		printf("\n");
	}
}

