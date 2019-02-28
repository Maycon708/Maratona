#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int mat[1111][1111], n;

bool dentro( int x, int y ){
	return x >= 0 && x < n && y >=0 && y < n;
}

int bfs( int x, int y ){
	int c = mat[x][y];
	int cnt = 0;
	queue<ii> q;
	q.push(ii(x, y));
	while( !q.empty() ){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		if( mat[x][y] != c ) continue;
		mat[x][y] = -1;
		cnt++;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro(xx,yy) ) q.push( ii(xx,yy) );
		} 
	}
	return cnt;
}

int main(){
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		int ans = n*n;
		rep( i, 0, n ) rep( j, 0, n ) scanf("%d", &mat[i][j] );
		rep( i, 0, n ){
			if( mat[0][i] == 0 ) ans -= bfs(0, i);
			if( mat[n-1][i] == 0 ) ans -= bfs(n-1, i);
			if( mat[i][0] == 0 ) ans -= bfs(i, 0);
			if( mat[i][n-1] == 0 ) ans -= bfs(i, n-1);
		}
		printf("%.2f\n", ans/2.0 );
	}
}
