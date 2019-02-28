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

int vis[110][110], n, m, mat[110][110];
int dx[] = {  1, 1, 1,  0, 0, -1, -1, -1 };
int dy[] = { -1, 0, 1, -1, 1, -1,  0,  1 };

int dentro( int x, int y ){
	return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs( int x, int y ){
	
	int d, ans;
	queue< pair<ii, int> > q;
	q.push( mk( ii(x, y), 0 ));
	
	memset( vis, 0, sizeof vis );
	
	while( !q.empty() ){
		x = q.front().F.F;
		y = q.front().F.S;
		d = q.front().S;
		q.pop();
		
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		ans = d;
		
		rep( i, 0, 8 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) && mat[xx][yy] ) 
				q.push( mk( ii( xx, yy ), d+1 ));
		}
	}
	return ans;
}

int main(){
	int t, x, y;
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		rep( i, 0, n )
			rep( j, 0, m )
				cin >> mat[i][j];
		cin >> x >> y;
		x--, y--;
		cout << bfs( x, y ) << "\n";
	}
}
