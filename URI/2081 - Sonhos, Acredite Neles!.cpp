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

struct C{
	int x1, y1, x2, y2;
	C(){};
	C( int a, int b, int c, int d ){
		x1 = a; y1 = b; x2 = c; y2 = d;
	}
	bool operator < ( C a ) const { 
		if( x1 != a.x1 ) return x1 < a.x1;
		if( y1 != a.y1 ) return y1 < a.y1;
		if( x2 != a.x2 ) return x2 < a.x2;
		return y2 < a.y2;
	}
	bool operator == ( C a ) const{ return x1 == a.x1 && y1 == a.y1 && x2 == a.x2 && y2 == a.y2; }
};

int n, m;
char m1[60][60], m2[60][60];

inline bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

C ini, fim;

void D( C a ){
	printf("x1 = %d, y1 = %d, x2 = %d y2 = %d\n", a.x1, a.y1, a.x2, a.y2 );
}

bool vis[51][51][51][51];

void bfs(){
	int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
	queue < pair < C, int > > q;
	
	rep( i, 0, n ) rep( j, 0, m ) rep( k, 0, n ) rep( l, 0, m ) vis[i][j][k][l] = 0;
	
	q.push( mk( ini, 0 ) );
	while( !q.empty() ){
		C a = q.front().F;
		int x1 = a.x1;
		int y1 = a.y1;
		int x2 = a.x2;
		int y2 = a.y2;
		int c = q.front().S;
		q.pop();
		if( a == fim ){
			printf("%d\n", c );
			return;
		}
		if( vis[x1][y1][x2][y2] || c == 50 ) continue;
		vis[x1][y1][x2][y2] = 1;
		rep( i, 0, 4 ){
			C v;
			int x = x1 + dx[i], y = y1 + dy[i];
			if( !dentro( x, y ) || m1[x][y] == 'B' ) continue;
			if( m1[x][y] == '#' ) x = x1, y = y1;
			int xx = x2 + dx[i], yy = y2 + dy[i];
			if( !dentro( xx, yy ) || m2[xx][yy] == 'B' ) continue;
			if( m2[xx][yy] == '#' ) xx = x2, yy = y2;
			q.push( mk( C( x, y, xx, yy ), c+1 ) );	
		}
	}
	printf("impossivel\n");
	return;
}

int main(){

	int t = readInt();
	while( t-- ){
		n = readInt();
		m = readInt();
		rep( i, 0, n ){
			rep( j, 0, m ){
				char ch = getchar();
				m1[i][j] = ch;
				if( ch == 'R' ) ini.x1 = i, ini.y1 = j; 
				if( ch == 'F' ) fim.x1 = i, fim.y1 = j;
			}
			getchar();
		}
		rep( i, 0, n ){
			rep( j, 0, m ){
				char ch = getchar();
				m2[i][j] = ch;
				if( ch == 'R' ) ini.x2 = i, ini.y2 = j;
				if( ch == 'F' ) fim.x2 = i, fim.y2 = j;
			}
			getchar();
		}
		bfs();
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



