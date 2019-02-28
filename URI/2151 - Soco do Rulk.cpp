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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int aux[110][110], n, m;

inline bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs( int a, int b ){
	int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 }, dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };
	queue< pair< ii, int > > q;
	q.push( mk( ii( a, b ), 9 ) );
	while( !q.empty() ){
		int x = q.front().F.F;
		int y = q.front().F.S;
		int c = q.front().S;
		q.pop();
		if( !c ) return;
		if( aux[x][y] ) continue;
		aux[x][y] = c;
		rep( i, 0, 8 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) )
				q.push( mk( ii( xx, yy ), c-1 ) );
		}
	}
}

int main(){

	int t, x, y, mat[110][110];
	scanf("%d", &t );
	rep( k, 1, t+1 ){
		scanf("%d%d%d%d", &n, &m, &x, &y );
		rep( i, 0, n )
			rep( j, 0, m ){
				scanf("%d", &mat[i][j] );
				aux[i][j] = 0;
			}
		bfs( x-1, y-1 );
		printf("Parede %d:\n", k );
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( j ) printf(" ");
				printf("%d", mat[i][j] + aux[i][j] +1 );
			}
			printf("\n");
		}
	}
}
