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

int dx[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int dy[] = { 2, 2, -2, -2, 1, 1, -1, -1 };

inline int dentro( int x, int y ){
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int bfs( ii ini, ii fim ){
	
	queue< pair< ii, int > > q;
	q.push( mk( ini, 0 ) );
	map<ii, int> vis;
	
	while( !q.empty() ){
		ii u = q.front().F;
		int c = q.front().S;
		q.pop();
		if( u == fim ) return c;
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, 8 ){
			int x = u.F + dx[i], y = u.S + dy[i];
			if( dentro( x, y ) ) q.push( mk( ii( x, y ), c+1 ));
		}
	}
}

int main(){
	char p1[10], p2[10];
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%s %s", p1, p2 );
		ii ini = ii( p1[0] - 'a', p1[1] - '1' );
		ii fim = ii( p2[0] - 'a', p2[1] - '1' );
		printf("%d\n", bfs( ini, fim ) );
	}
}

