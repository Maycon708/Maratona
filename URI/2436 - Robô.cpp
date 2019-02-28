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

int mat[1001][1001];
int n, m, cnt, dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs( int i, int j ){
	bool aux = 1;
	rep( k, 0, 4 ){
		int x = i + dx[k], y = j + dy[k];
		if( !dentro(x,y) || mat[x][y] == 0 ) continue;
		mat[i][j] = aux = 0;
		dfs( x, y );
	}
	if( aux ) printf("%d %d\n", i+1, j+1 );
}


int main(){
	int a, b;
	while( cin >> n >> m ){
		cin >> a >> b;
		rep( i, 0, n ) rep( j, 0, m ) cin >> mat[i][j];
		dfs( a-1, b-1 );
	}
}

