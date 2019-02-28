#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 450

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int n, m, xf, yf;
bool vis[1010][1010];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs( int x, int y ){
	queue< pair<ii, int> > q;
	q.push( mk( ii(x, y), 0 ));
	while( !q.empty() ){
		x = q.front().F.F;
		y = q.front().F.S;
		int c = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		if( x == xf && y == yf ) return c;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) ) q.push( mk( ii(xx, yy), c+1 ) );
		}
	}
	
	return -1;
}

int main(){
	int k, l, aux, c, x, y;
	while( scanf("%d%d", &n, &m ) != EOF && n ){
		scanf("%d", &k );
		memset( vis, 0, sizeof vis );
		while( k-- ){
			scanf("%d%d", &l, &aux );
			rep( i, 0, aux ){
				scanf("%d", &c );
				vis[l][c] = 1;
			}
		}
		scanf("%d%d", &x, &y );
		scanf("%d%d", &xf, &yf );
		printf("%d\n", bfs( x, y ) ) ;
	}
}
