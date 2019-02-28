#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
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

struct bloco{
	int x, y, z;
	void scan(){
		scanf("%d%d%d", &x, &y, &z );
	}
};
bloco v[20];
int n, pd[16][3][1<<16];

inline bool C( int a, int i, int b, int j ){
	int x1, y1, x2, y2;
	
	if( !i ) x1 = v[a].x, y1 = v[a].y;
	else if( i == 1 ) x1 = v[a].z, y1 = v[a].y;
	else x1 = v[a].x, y1 = v[a].z;
	
	if( !j ) x2 = v[b].x, y2 = v[b].y;
	else if( j == 1 ) x2 = v[b].z, y2 = v[b].y;
	else x2 = v[b].x, y2 = v[b].z;
	
	if( x1 > y1 ) swap( x1, y1 );
	if( x2 > y2 ) swap( x2, y2 );
	
	return x2 <= x1 && y2 <= y1;
}

inline int D( int a, int i ){
	if( !i ) return v[a].z;
	if( i == 1 ) return v[a].x;
	return v[a].y;
}

int solve( int b, int p, int mask ){
	if( pd[b][p][mask] != -1 ) return pd[b][p][mask];
	int ans = 0;
	rep( i, 0, n ){
		if( mask & ( 1 << i ) ) continue;
		rep( j, 0, 3 )
			if( C( b, p, i, j ) ) 
				ans = max( ans, solve( i, j, mask | ( 1 << i ) ) + D( i, j ) );
	}
	return pd[b][p][mask] = ans;
}

int main(){
	
	int t;
	scanf("%d", &t );
	while( t-- ){		
		scanf("%d", &n );
		rep( i, 0, n ) v[i].scan();
		memset( pd, -1, sizeof pd );
		int ans = 0;
		rep( i, 0, n ){
			rep( j, 0, 3 ){
				ans = max( ans, solve( i, j, 1 << i ) + D( i, j ));
			}
		}
		printf("%d\n", ans );
	}
}

