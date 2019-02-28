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

struct T{
	int a, b, c;
	T(){};
	T( int x, int y, int z ){
		a = x; b = y; c = z;
	};
};

char mat[53][53]; 
int n;

void bfs( T ini ){
	queue < pair < T, int > > q;
	int vis[53][53][53];
	
	rep( i, 0, n+1 ) rep( j, 0, n+1 ) rep( k, 0, n+1 ) vis[i][j][k] = 0;
	
	q.push( mk( ini, 0 ) );
	while( !q.empty() ){
		T u = q.front().F;
		int c = q.front().S;
		q.pop();
		int x = u.a, y = u.b, z = u.c; 
		
		if( x == y && y == z ){
			printf("%d\n", c );
			return;
		}
		if( vis[x][y][z] ) continue;
		vis[x][y][z] = 1; 
		
		rep( i, 1, n+1 ){
			if( mat[x][i] == mat[y][z] ) q.push( mk( T( i, y, z ), c+1 ) );
			if( mat[y][i] == mat[x][z] ) q.push( mk( T( x, i, z ), c+1 ) );
			if( mat[z][i] == mat[y][x] ) q.push( mk( T( x, y, i ), c+1 ) );
		}
	}
	printf("impossible\n");
}

int main(){
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		T ini;
		scanf("%d%d%d", &ini.a, &ini.b, &ini.c );
		rep( i, 1, n+1 ){
			rep( j, 1, n+1 ){
				
				cin >> mat[i][j];
			}
		}
		
		bfs( ini );
		
	}

}

