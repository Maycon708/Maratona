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

int n, m, vis[255][255], ovelhas, lobos;
char mat[255][255];
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };

bool dentro( int x, int y ){
	return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs( int x, int y ){
	queue<ii> q;
	q.push( ii( x, y ) );
	int a = 0, b = 0, aux = 1;
	while( !q.empty() ){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		if( mat[x][y] == 'v' ) b++;
		if( mat[x][y] == 'k' ) a++;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( !dentro( xx, yy ) ){
				aux = 0;
				continue;
			}
			if( mat[xx][yy] == '#' ) continue;
			q.push( ii( xx, yy ) );
		}
	}
	if( a > b && aux ) ovelhas += a;
	else lobos += b;
}

int main(){
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ) scanf("%s", mat[i] );
		memset( vis, 0, sizeof vis );
		ovelhas = lobos = 0;
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( mat[i][j] == '#' || vis[i][j] ) continue;
				bfs( i, j );
			}
		}
		printf("%d %d\n", ovelhas, lobos );
		break;
	}
}

