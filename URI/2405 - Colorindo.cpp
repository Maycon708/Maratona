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
int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 1, 0, -1, -1, 1, -1, 0, 1 };
bool vis[210][210];

bool dentro( int x, int y ){
	return x > 0 && x <= n && y > 0 && y <= m;
}

int bfs( int x, int y ){
	queue<ii> q;
	q.push( ii( x, y ) );
	int cnt = 0;
	while( !q.empty() ){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		cnt++;
		rep( k, 0, 8 ){
			int xx = x + dx[k], yy = y + dy[k];
			if( dentro( xx, yy ) ) q.push( ii( xx, yy ));
		}
	}
	return cnt;
}

int main(){
	int a, b, x, y, k;
	while( cin >> n >> m >> x >> y >> k ){
		memset( vis, 0, sizeof vis );
		while( k-- ){
			cin >> a >> b;
			vis[a][b] = 1;
		}
		printf("%d\n", bfs( x, y ));
	}	
}

