#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int mat[505][505], n, m, resp[505][505];

inline int dentro( int x, int y ){
	return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs(){
	int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
	queue < ii > q;
	q.push( ii( n-1, m-1 ) );
	resp[n-1][m-1] = mat[n-1][m-1];
	bool vis[505][505];
	rep( i, 0, n )
		rep( j, 0, m )
			vis[i][j] = 0;
	while( !q.empty() ){
		int x = q.front().F, y = q.front().S;
		q.pop();
//		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) ){
				if( resp[xx][yy] < min( resp[x][y] - 1, mat[xx][yy] ) ) 
				resp[xx][yy] = min( resp[x][y] - 1, mat[xx][yy] ),
				q.push( ii( xx, yy ) );
			}
		}
	}
}

int main(){
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ){
			rep( j, 0, m ){
				scanf("%d", &mat[i][j] );
				resp[i][j] = 0;
			}
		}
		bfs();
		printf("%d\n", max( resp[0][0]-1, -1 ) );
	}	
}


