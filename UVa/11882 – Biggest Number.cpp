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

int n, m;
char mat[22][22];
bool used[22][22];
int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };
string ans;

inline bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != '#';
}

inline bool cmp( string a, string b ){
	if( a.size() != b.size() ) return a.size() < b.size();
	return a < b;
}

string bfs( int x, int y ){
	queue<ii> q;
	char aux[100], t = 0;
	bool vis[33][33];
	memset( vis, 0, sizeof vis );
	
	rep( i, 0, 4 ){
		int xx = x + dx[i], yy = y + dy[i];
		if( dentro( xx, yy ) ) q.push( ii( xx, yy ));
	}
	
	while( !q.empty() ){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		if( vis[x][y] || used[x][y] ) continue;
		vis[x][y] = 1;
		aux[t++] = mat[x][y];
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) ) q.push( ii( xx, yy ));
		}
	}
	aux[t] = '\0';
	sort( aux, aux+t );
	reverse( aux, aux+t );
	return aux;
}

void back( int x, int y, string s ){
	if( cmp( ans, s ) ) ans = s;
	else{
		string a = bfs( x, y );
		if( s.size() + a.size() < ans.size() ) return;
		else if( cmp( s+a, ans ) ) return;
	}
	rep( i, 0, 4 ){
		int xx = x + dx[i], yy = y + dy[i];
		if( !dentro( xx, yy ) || used[xx][yy] ) continue;
		used[xx][yy] = 1;
		back( xx, yy, s + mat[xx][yy] );
		used[xx][yy] = 0;
	}
}

int main(){
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		rep( i, 0, n ) scanf("%s", mat[i] );
		ans.clear();
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( mat[i][j] == '#') continue;
				used[i][j] = 1;
				string aux = "";
				aux += mat[i][j];
				back( i, j, aux );
				used[i][j] = 0;
			}
		}
		puts(ans.c_str());
	}		
}

