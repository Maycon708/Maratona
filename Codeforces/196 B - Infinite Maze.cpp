#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair 
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 }, n, m;
char mat[2002][2002];
bool vis[2000][2000];
ii lst[2000][2000];

ii get( int x, int y ){
	return ii( (x%n+n)%n, (y%m+m)%m );
}

bool bfs( int x, int y ){
	queue< pair<ii, ii> > q;
	q.push( mp( ii(x, y), ii(x, y) ) );
	while( !q.empty() ){
		x = q.front().F.F;
		y = q.front().F.S;
		ii v = q.front().S;
		q.pop();
		if( vis[x][y] ){
			if( lst[x][y] == v ) continue;
			return 1;
		}
		vis[x][y] = 1;
		lst[x][y] = v;		
		rep( i, 0, 4 ){
			ii nx = get( v.F+dx[i], v.S+dy[i] );
			if( mat[nx.F][nx.S] != '#' ){
				q.push( mp( nx, ii( v.F+dx[i], v.S+dy[i] ) ) );
			}
		}
	}	
	return 0;
}

int main(){
	scanf("%d%d", &n, &m );
	rep( i, 0, n ) scanf("%s", mat[i] );
	rep( i, 0, n ) 
		rep( j, 0, m )
			if( mat[i][j] == 'S' )
				puts( bfs(i, j) ? "Yes" : "No" );
}

