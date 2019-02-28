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

int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[] = { -1, 1, -1, 1, 2, -2, 2, -2 };
int mat[1010][1010], n, m;

int dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs( int x, int y ){
	queue<ii> q;
	q.push( ii(x, y) );
	mat[x][y] = 1;
	while( !q.empty() ){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		rep( i, 0, 8 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro(xx, yy) && mat[xx][yy] == -1 ){
				mat[xx][yy] = 1-mat[x][y];
				q.push( ii(xx, yy ) );
			}
		}
	}
}

int main(){
	int a = 0, b = 0;
	scanf("%d%d", &n, &m );
	rep( i, 0, n ) rep( j, 0, m ) mat[i][j] = -1;
	rep( i, 0, n ) rep( j, 0, m ) if( mat[i][j] == -1 ) bfs(i, j);
	rep( i, 0, n ) rep( j, 0, m ) a += mat[i][j];
	rep( i, 0, n ) rep( j, 0, m ) mat[i][j] = -1;
	rep( j, 0, m ) rep( i, 0, n ) if( mat[i][j] == -1 ) bfs(i, j);
	rep( i, 0, n ) rep( j, 0, m ) b += mat[i][j];
	cout << max(a, b) << "\n";
	
}
