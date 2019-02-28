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

int mat[1010][1010], n, m;

inline int dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(){
	int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
	queue < ii > q;
	rep( i, 0, n ){
		rep( j, 0, m ){
			if( mat[i][j] ) q.push( ii( i, j ) );
		}
	}
	while( !q.empty() ){
		int x = q.front().F;
		int y = q.front().S;
		q.pop();
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) ){
				if( !mat[xx][yy] ){
					mat[xx][yy] = mat[x][y];
					q.push( ii( xx, yy ) );
				}
			}
		}
	}
}

int main(){
	int T = 1, xx[100010], yy[100010];
	while( 1 ){
		m = readInt();
		n = readInt();
		if( !n && !m ) break;
		if( T != 1 ) printf("\n");
		memset( mat, 0, sizeof mat );
		int k = readInt();
		rep( i, 1, k+1 ){
			int x = readInt()-1;
			int y = readInt()-1;
			mat[x][y] = i;
			xx[i] = x+1;
			yy[i] = y+1;
		}
		bfs();
		int l = readInt();
		printf("Instancia %d\n", T++);
		while( l-- ){
			int x = readInt()-1;
			int y = readInt()-1;
			int u = mat[x][y];
			printf("%d %d\n", xx[u], yy[u] );
		}
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


