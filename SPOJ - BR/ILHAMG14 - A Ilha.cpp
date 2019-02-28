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

int vis[1035][1035], n, t, mat[1035][1035];

inline bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < n;
}

int bfs( ){
	int dx[] = { 1, -1, 0,  0 };
	int dy[] = { 0,  0, 1, -1 };
	queue < ii > q;
	rep( i, 0, n ){
		rep( j, 0, n ) vis[i][j] = 0;
		if( mat[0][i] < t ) q.push( ii( 0, i ) );
		if( mat[i][0] < t ) q.push( ii( i, 0 ) );
		if( mat[n-1][i] < t ) q.push( ii( n-1, i ) );
		if( mat[i][n-1] < t ) q.push( ii( i, n-1 ) );
	}
	while( !q.empty() ){
		int x = q.front().F;
		int y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) && mat[xx][yy] < t ){
				q.push( ii( xx, yy ) );
			}
		}
	}
	int cont = 0;
	rep( i, 0, n ){
		rep( j, 0, n ){
			cont += ( !vis[i][j] );
		}
	}
	return cont;
}

int main(){

	while( 1 ){
		n = readInt();
		t = readInt();
		if( !n && !t ) break;
		rep( i, 0, n ){
			rep( j, 0, n ){
				mat[i][j] = readInt();
			}
		}
		printf("%d\n", bfs() );
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



