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

ll readInt();

int dx[] = {  1, -1,  0,  0,  1,  1, -1, -1,  0,  0,  2, -2,  1,  1, -1, -1,  2,  2, -2, -2,  2,  2, -2, -2 };
int dy[] = {  0,  0, -1,  1,  1, -1,  1, -1, -2,  2,  0,  0, -2,  2, -2,  2, -1,  1, -1,  1,  2, -2,  2, -2 };
int C[]  = {  2,  2,  2,  2,  3,  3,  3,  3,  5,  5,  5,  5,  6,  6,  6,  6,  6,  6,  6,  6,  7,  7,  7,  7 };

int r, c, mat[1010][1010], dist[1010][1010], vis[1010][1010];

inline bool dentro( int x, int y ){
	return x >= 0 && x < r && y >= 0 && y < c && mat[x][y] != -1;
}

int dijkstra( ii ini, ii fim ){
	rep( i, 0, r ){
		rep( j, 0, c ){
//			printf("%d ", mat[i][j]);
			dist[i][j] = INF, vis[i][j] = 0;
		}
//		printf("\n");
	}
	dist[ini.F][ini.S] = 0;
	priority_queue < pair< int, ii > > pq;
	pq.push( mk( 0, ini ) );
	while( !pq.empty() ){
		ii u = pq.top().S;
		pq.pop();
		if( vis[u.F][u.S] ) continue;
		vis[u.F][u.S] = 1;
		if( u == fim ) return dist[u.F][u.S];
		rep( i, 0, 24 ){
			int xx = u.F + dx[i], yy = u.S + dy[i];
			if( dentro( xx, yy ) ){
				if( dist[xx][yy] > dist[u.F][u.S] + C[i] ){
					dist[xx][yy] = dist[u.F][u.S] + C[i];
					pq.push( mk( -dist[xx][yy], ii( xx, yy ) ) );
				}
			}
		}
	}
	return -1;
}

int main(){

	while( 1 ){
		c = readInt();
		r = readInt();
		if( !c && !r ) break;
		rep( i, 0, r )
			rep( j, 0, c )
				mat[i][j] = 0;
		int y0 = readInt()-1;
		int x0 = readInt()-1;
		int y1 = readInt()-1;
		int x1 = readInt()-1;
		int k = readInt();
		while( k-- ){
			int c1 = readInt()-1;
			int r1 = readInt()-1;
			int c2 = readInt();
			int r2 = readInt();
			rep( i, r1, r2 ){
				rep( j, c1, c2 ) mat[i][j] = -1;
			} 
		}
		int ans = dijkstra( ii( x0, y0 ), ii( x1, y1 ) );
		if( ans == -1 ) printf("impossible\n");
		else printf("%d\n", ans );
	}

}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

