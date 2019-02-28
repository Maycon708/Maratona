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

ll readInt();

char mat[200][200];
int l, c;

inline int dentro( int x, int y ){
	return x >= 0 && x < l && y >= 0 & y < c && mat[x][y] != '#';
}

struct C{
	int x1, y1, x2, y2, c1, c2;
	C(){};
	C( int a, int b, int c, int d, int e, int f ){
		x1 = a; y1 = b; x2 = c; y2 = d; c1 = e; c2 = f;
	}
	bool operator < ( C a ) const {
		if( c1 != a.c1 ) return c1 < a.c1;
		if( c2 != a.c2 ) return c2 < a.c2;
		if( x1 != a.x1 ) return x1 < a.x1;
		if( y1 != a.y1 ) return y1 < a.y1;
		if( x2 != a.x2 ) return x2 < a.x2;
		if( y2 != a.y2 ) return y2 < a.y2;
	}
};

ii bfs( ii ini, ii p, ii fim ){
	int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
	priority_queue < C > pq;
	pq.push( C( ini.F, ini.S, p.F, p.S, 0, 0 ) );
	int vis[25][25][25][25];
	memset( vis, 0, sizeof vis );
	ii ans = ii( INF, INF );
	while( !pq.empty() ){
		int px = pq.top().x1;
		int py = pq.top().y1;
		int sx = pq.top().x2;
		int sy = pq.top().y2;
		ii resp;
		resp.F = -pq.top().c1;
		resp.S = -pq.top().c2;
		pq.pop();
		if( vis[px][py][sx][sy] ) continue;
		vis[px][py][sx][sy] = 1;
		if( ii( sx, sy ) == fim ) ans = min( ans, resp );
		rep( i, 0, 4 ){
			int xx = px + dx[i], yy = py + dy[i];
			if( !dentro( xx, yy ) ) continue;
			if( xx != sx || yy != sy ) pq.push( C( xx, yy, sx, sy, -resp.F, - ( resp.S + 1 ) ) );
			else{
				int xxx = sx + dx[i], yyy = sy + dy[i];
				if( !dentro( xxx, yyy ) ) continue;
				pq.push( C(  xx, yy, xxx, yyy, -( resp.F + 1 ), -( resp.S + 1 ) ) );
			}
		}
	}
	return ans;
}

int main(){
	ii ini, fim, p;
	int t = 1;
	bool aux = 0;
	while( 1 ){
		l = readInt();
		c = readInt();
		if( !l && !c ) break;
		if( aux ) printf("\n");
		aux = 1;
		rep( i, 0, l ){
			rep( j, 0, c ){
				cin >> mat[i][j];
				switch ( mat[i][j] ){
					case 'T':{
						fim = ii( i, j );
						break;
					}
					case 'S':{
						ini = ii( i, j );
						break;
					}
					case 'B':{
						p = ii( i, j );
						break;
					}
				}
			}
		}
		printf("Instancia %d\n", t++ );
		ii ans = bfs( ini, p, fim );
		if( ans.F == INF ) printf("Impossivel\n");
		else printf("%d %d\n", ans.S, ans.F );
		
	}

}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}



