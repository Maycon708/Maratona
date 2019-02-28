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

int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int n, vis[1300][1300], mat[1300][1300], cnt, L, C;

inline bool fora( int x, int y ){
	return( x < 0 || y < 0 || x >= L || y >= C || mat[x][y] );
}

int bfs( int X, int Y ){
	queue<ii> q;
	q.push( ii( X, Y ) );
	while( !q.empty() ){
		int x = q.front().F;
		int y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = cnt;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( fora( xx, yy ) ) continue; 
			q.push( ii( xx, yy ) );
		}
	}
}

void vertical( int l, int k ){
	if( l - 2 >= 0 ) mat[l-2][k] = 1;
	if( l - 1 >= 0 ) mat[l-1][k] = 1;
	mat[l][k] = 1;
	if( l + 1 < L ) mat[l+1][k] = 1;
	if( l + 2 < L ) mat[l+2][k] = 1;
}

void horizontal( int l, int k ){ 
	if( k - 2 >= 0 ) mat[l][k-2] = 1;
	if( k - 1 >= 0 ) mat[l][k-1] = 1;
	mat[l][k] = 1;
	if( k + 1 < C ) mat[l][k+1] = 1;
	if( k + 2 < C ) mat[l][k+2] = 1;
}

int main(){
//	freopen( "F.in", "r", stdin );
//	freopen( "out.txt", "w", stdout );
	char s[400];
	while( scanf("%d", &n ) != EOF ){
		C = ( n << 2 ) + 1;
		L = C - 2;
		rep( i, 0, L ) rep( j, 0, C ) mat[i][j] = vis[i][j] = 0;
		
		rep( i, 0, 2*n-1 ){
			scanf("%s", s );
			rep( j, 0, n ){
				int l = ( i << 1 ) ^ 1;
				int k = j << 2;
				if( i&1 ){
					k += 3;
					if( s[j] == 'V' ) vertical( l, k );
					else horizontal( l, k );
				}
				else{
					k++;
					if( s[j] == 'V' ) vertical( l, k );
					else horizontal( l, k );
				}
			}
		}
		cnt = 0;
		rep( i, 0, L ){
			rep( j, 0, C ){
				if( !vis[i][j] && !mat[i][j] ) cnt++, bfs( i, j );
			}
		}
//		debug("---")
//		debugM( mat, L, C )
//		debug("---")
//		debugM( vis, L, C )
//		debug("---")
		printf("%d\n", cnt-1 );
	}
}

