#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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

const int MAX = 110;
int n, m;
char mat[MAX][MAX];

inline bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < n;
}

inline int C( char c ){
	if( c >= 'A' && c <= 'Z' ) return 0;
	return 1;
}

int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int vis[MAX][MAX];

inline int D( char c ){
	if( C(c) ) return c - 'a';
	return c - 'A';
}

int bfs( int mask ){
	queue< pair< ii, int > > q;
	q.push( mk( ii( 0, 0 ), 1 ) );
	memset( vis, 0, sizeof vis );
	int k = D( mat[0][0] );
	if( C(mat[0][0]) && mask & ( 1 << k ) ) return INF;
	if( !C(mat[0][0]) && !( mask & ( 1 << k ) ) ) return INF;
	while( !q.empty() ){
		int x = q.front().F.F;
		int y = q.front().F.S;
		int c = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		if( x == n-1 && y == n-1 ) return c;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy )){
				char cc = mat[xx][yy];
				if( C( cc ) && ( !( mask & ( 1 << D(cc)) ) ) ) q.push( mk( ii( xx, yy ), c+1 ));
				else if( !C(cc) && ( mask & ( 1 << D(cc) ) ) ) q.push( mk( ii( xx, yy ), c+1 ));
			}
		}
	}
	return INF;
}

int main(){
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			scanf("%s", mat[i] );
		}
		int ans = INF;
		rep( i, 0, 1<<10 ){
			ans = min( ans, bfs( i ));
		}
		if( ans == INF ) printf("-1\n");
		else printf("%d\n", ans );
	}
}

