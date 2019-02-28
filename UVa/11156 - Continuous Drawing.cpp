#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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

double pd[1<<20];
double dist[30][30];
int g[30], v[30], n, end;
bool have[30];

double solve( int mask ){
	int k = __builtin_popcount( mask );
	if( k + 2 >= n ) return 0;
	if( pd[mask] > -1 ) return pd[mask];
	
	double ans = 1<<29;
	rep( i, 0, n ){
		if( mask & ( 1 << i ) ) continue;
		rep( j, i+1, n ){
			if( mask & ( 1 << i ) ) continue;
			ans = min( ans, solve( mask | ( 1 << i ) | ( 1 << j ) ) + dist[v[i]][v[j]] );
		}
	}
	
	return pd[mask] = ans;
}

double resp;

void addEdge( ii a, ii b ){
	int u = a.F * 5 + a.S, v = b.F * 5 + b.S;
	if( dist[u][v] < 42 ) resp -= dist[u][v]; 
	dist[u][v] = dist[v][u] = hypot( a.F - b.F, a.S - b.S );
	g[u]++, g[v]++;
	have[u] = have[v] = 1;
	resp += dist[u][v];
}

int main(){
	
	int k, test;
	string s1, s2;
	scanf("%d", &test );
	rep( t, 1, test+1 ){
		scanf("%d", &k );
		resp = 0;
		map< string, int > mp;
		rep( i, 0, 1 << 20 ) pd[i] = -42;
		rep( i, 0, 30 ){
			rep( j, 0, 30 ) dist[i][j] = 42*42;
			dist[i][i] = 0;
			have[i] = 0;
			g[i] = 0;
		}
		
		rep( i, 0, k ){
			cin >> s1 >> s2;
			int x1 = s1[0] - 'A', y1 = s1[1] - '1';
			int x2 = s2[0] - 'A', y2 = s2[1] - '1';
			int dx = abs( x1 - x2 ), dy = abs( y1 - y2 );
			if( !dx ){
				while( y2 != y1 ){
					int y = ( y1 > y2 ) ? y1-1 : y1+1;
					addEdge( ii( x1, y1 ), ii( x1, y ) );
					y1 = y;
				}
			}
			else if( !dy ){
				while( x1 != x2 ){ 
					int x = ( x1 > x2 ) ? x1 -1 : x1 + 1;
					addEdge( ii( x1, y1), ii( x, y1 ) );
					x1 = x;
				}
			}
			else{
				int aux = __gcd( dx, dy );
				dx /= aux, dy /= aux;
				while( x1 != x2 ){
					int x = x1 + ( ( x1 > x2 ) ? ( -dx ) : ( dx ) );
					int y = y1 + ( ( y1 > y2 ) ? ( -dy ) : ( dy ) );
					addEdge( ii( x1, y1 ), ii( x, y ) );
					x1 = x, y1 = y;
				}
			}
		}
		
		rep( k, 0, 25 )
			rep( i, 0, 25 )
				rep( j, 0, 25 )
					dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
		
		n = 0;
		rep( i, 0, 25 ){ 
			if( g[i]&1 ){
				v[n++] = i;
			}
		}
		bool ok = 1;
		rep( i, 0, 25 )
			rep( j, 0, 25 )
				if( dist[i][j] > 42 && have[i] && have[j] ) ok = 0;
		
		if( ok ) printf("Case %d: %.2f\n", t, resp + solve( 0 ) );
		else printf("Case %d: ~x(\n", t );
	}

}

