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

char mat[111][111];
int n, m;
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs( int x, int y, int op ){
	if( mat[x][y] != '.' ) return;
	mat[x][y] = op? 'B' : 'W';
	rep( i, 0, 4 ){
		int xx = x + dx[i], yy = y + dy[i];
		if( dentro( xx, yy ) ) dfs( xx, yy, !op );
	}
}

int main(){
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ) scanf("%s", mat[i] );
		
		rep( i, 0, n )
			rep( j, 0, m )
				if( mat[i][j] == '.' ) dfs( i, j, 1 );
		
		rep( i, 0, n ) puts( mat[i] );
	}
}

