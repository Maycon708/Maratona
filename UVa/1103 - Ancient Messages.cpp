#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int N = 300;

int n, m, cnt, dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
bool vis[N][N];
string mat[N];

inline bool D( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs_w( int x, int y ){
	cnt++;
	queue<ii> q;
	q.push( ii( x, y ) );
	while( !q.empty() ){
		x = q.front().F, y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		mat[x][y] = '2';
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y +dy[i];
			if( D( xx, yy ) ){
				if( mat[xx][yy] == '0' ) q.push( ii( xx, yy ) );
			}
		}
	}
}

void bfs_b( int x, int y ){
	queue<ii> q;
	q.push( ii( x, y ) );
	while( !q.empty() ){
		x = q.front().F, y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		mat[x][y] = '3';
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y +dy[i];
			if( D( xx, yy ) ){
				if( mat[xx][yy] == '0' ) bfs_w( xx, yy );
				else if( mat[xx][yy] == '1') q.push( ii( xx, yy ) );
			}
		}
	}
}

string C( char c ){
	if( c == '0' ) return "0000";
	if( c == '1' ) return "0001";
	if( c == '2' ) return "0010";
	if( c == '3' ) return "0011";
	if( c == '4' ) return "0100";
	if( c == '5' ) return "0101";
	if( c == '6' ) return "0110";
	if( c == '7' ) return "0111";
	if( c == '8' ) return "1000";
	if( c == '9' ) return "1001";
	if( c == 'a' ) return "1010";
	if( c == 'b' ) return "1011";
	if( c == 'c' ) return "1100";
	if( c == 'd' ) return "1101";
	if( c == 'e' ) return "1110";
	if( c == 'f' ) return "1111";
}

int main(){
	int t = 1;
	char aux2[] = { 'W', 'A', 'K', 'J','S', 'D'}, aux[N];
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n ) break;
		
		rep( i, 0, N ){
			mat[i].clear();
			rep( j, 0, N ){
				vis[i][j] = 0;
			}
		}
		
		
		rep( i, 0, n ){
			scanf("%s", aux );
			rep( j, 0, m ) mat[i] += C( aux[j] );
		}
		m <<= 2;
		rep( i, 0, n ){
			if( mat[i][0] == '0' ) bfs_w( i, 0 );
			if( mat[i][m-1] == '0' ) bfs_w( i, m-1 );
		}
		rep( i, 0, m ){
			if( mat[0][i] == '0' ) bfs_w( 0, i );
			if( mat[n-1][i] == '0' ) bfs_w( n-1, i );
		}
		vector<char> v;
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( mat[i][j] == '1'){
					cnt = 0;
					bfs_b( i, j );
					v.pb( aux2[cnt] );
				}
			}
		}
		sort( all(v) );
		printf("Case %d: ", t++ );
		rep( i, 0, v.size() ) printf("%c", v[i] );
		printf("\n");
	}
}

