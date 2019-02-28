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

inline bool dentro( int x, int y, int r, int c ){
	return x >= 0 && x < r && y >= 0 && y < c;
}

int main(){
	int m[111][111], mat[111][111];
	int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
	while( 1 ){
		int n = readInt();
		int r = readInt();
		int c = readInt();
		int k = readInt();
		if( !n && !r && !c && !k ) break;
		rep( i, 0, r )
			rep( j, 0, c )
				mat[i][j] = m[i][j] = readInt();
		rep( l, 0, k ){
			rep( i, 0, r )
				rep( j, 0, c )
					rep( I, 0, 4 ){
						int xx = i + dx[I], yy = j + dy[I];
						if( dentro( xx, yy, r, c ) ){
							if( ( m[i][j]+1)%n == m[xx][yy] ) mat[xx][yy] = m[i][j];
						}
					}
			rep( i, 0, r )
				rep( j, 0, c )
					m[i][j] = mat[i][j];
		}
		rep( i, 0, r ){
			rep( j, 0, c ){
				if( j ) printf(" ");
				printf("%d", m[i][j] );
			}
			printf("\n");
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


