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

int n, m, cmp[111][111], vis[111][111];
char mat[111][111];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs( int x, int y, int c ){
	if( cmp[x][y] != -1 ) return;
	cmp[x][y] = c;
	rep( i, 0, 4 ){
		int xx = x + dx[i], yy = y + dy[i];
		if( dentro( xx, yy ) && mat[xx][yy] == '#' ) dfs( xx, yy, c );
	}
}

int main(){
	int a, b, k;
	char aux[111][111];
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ) scanf("%s", mat[i] );
		int cnt = 0;
		memset( cmp, -1, sizeof cmp );
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( cmp[i][j] == -1 && mat[i][j] == '#' ) dfs( i, j, cnt++ );
			}
		}
		scanf("%d", &k );
		while( k-- ){
			scanf("%d%d", &a, &b );
			a--, b--;
			cmp[a][b] = -1;
		}
		set<int> st;
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( cmp[i][j] != -1 && !st.count( cmp[i][j] ) ){
					cnt--;
					st.insert( cmp[i][j] );
				}
			}
		}
		printf("%d\n", cnt );
	}
}

