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

int mat[1001][1001], vis[1001][1001], n, m;

inline bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

inline bool bfs(){
	int dx[] = { 0, -1, -1, 0, 1, 1,  1,  0, -1 };
	int dy[] = { 0,  0,  1, 1, 1, 0, -1, -1, -1 };
	queue < ii > q;
	q.push( ii( 0, 0 ) );
	while( !q.empty() ){
		int x = q.front().F, y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		int u = mat[x][y];
		int xx = x + dx[u], yy = y + dy[u];
		if( dentro( xx, yy ) ) q.push( ii( xx, yy ) );
	}
	rep( i, 0, n )
		rep( j, 0, m )
			if( !vis[i][j] )
				return 0;
	return 1;
}

int main(){
	int k = 1;
	while( 1 ){
		if( k > 1 ) printf("\n");
		n = readInt();
		m = readInt();
		if( !n && !m ) break;
		rep( i, 0, n ){
			rep( j, 0, m ){
				mat[i][j] = readInt();
				vis[i][j] = 0;
			}
		}
		printf("Instancia %d\n", k++ );
		if( bfs() ) printf("sim\n");
		else printf("nao\n");
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


