#include<bits/stdc++.h>

#define rep( i, a, b ) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << "\n";
#define debug2(a, b) cout << #a << " = " << a << " ---- " << #b << " = " << b <<  "\n";
#define F first
#define S second
#define pb push_back
#define mk make_pair
#define INF 0x3f3f3f3f

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

char mat[11][110][110];
int l, h, w, dist[11][110][110];
int pd[110][10100];

vector < ii > V;

struct T{
	int x, y, z;
	T() {};
	T( int a, int b, int c ){
		x = a; y = b; z = c;
	}
};

inline bool dentro( int x, int y, int z ){
	return x >= 0 && x < l && y >= 0 && y < h && z >= 0 && z < w && mat[x][y][z] != 'X';
}

void bfs( T ini ){
	int dy[] = { -1, 1, 0, 0 }, dz[] = { 0, 0, 1, -1 };
	queue < pair < T, int > > q;
	memset( dist, -1, sizeof dist );
	q.push( mk( ini, 0 ) );
	while( !q.empty() ){
		T u = q.front().F;
		int c = q.front().S;
		int x = u.x, y = u.y, z = u.z;
		q.pop();
		if( dist[x][y][z] != -1 ) continue;
		dist[x][y][z] = c;
		rep( i, 0, 4 ){
			int yy = y + dy[i], zz = z + dz[i];
			if( dentro( x, yy, zz ) ){
				q.push( mk( T( x, yy, zz ), c+1 ) );
			}
		}
		if( mat[x][y][z] == 'U' ){
			int xx = x + 1;
			if( dentro( xx, y, z ) ) q.push( mk( T( xx, y, z ), c+1 ) );	
		}
		if( mat[x][y][z] == 'D' ){
			int xx = x - 1;
			if( dentro( xx, y, z ) ) q.push( mk( T( xx, y, z ), c+1 ) );	
		}		
	}
}


int solve( int pos, int cap ){
	if( pos == V.size() ) return 0;
	if( pd[pos][cap] != -1 ) return pd[pos][cap];
	int ans = solve( pos+1, cap );
	if( cap >= V[pos].S ) ans = max( ans, solve( pos+1, cap - V[pos].S ) + V[pos].F );
	return pd[pos][cap] = ans;
}

int main(){
	int t, n, c, x, y, z, s, v;
	scanf("%d", &t );
	while( t-- ){
		V.clear();
		scanf("%d%d%d%d%d", &l, &h, &w, &n, &s );
		rep( i, 0, l )
			rep( j, 0, h )
				rep( k, 0, w ){
					cin >> mat[i][j][k];
					if( mat[i][j][k] == 'S' ) x = i, y = j, z = k; 
				}
		bfs( T( x, y, z ) );
		rep( i, 0, n ){
			scanf("%d%d%d%d", &x, &y, &z, &v );
			x--, y--, z--;
			if( dist[x][y][z] == -1 ) continue;
			V.pb( ii( v, 3 * dist[x][y][z] ) );	
		}			
		rep( i, 0, V.size() ){
			rep( j, 0, s+1 ){
				pd[i][j] = -1;
			}
		}
		printf("%d\n", solve( 0, s ) );		
	}
}
