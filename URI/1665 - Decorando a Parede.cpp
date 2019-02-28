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

struct Q{
	int x1, y1, x2, y2;
	
	Q(){};
	Q( int _x1, int _y1, int _x2, int _y2 ){
		x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
	}
	
	void read(){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2 );
	}
};

int n, w, h;

bool check( vector<Q> &v, Q s ){
	if( s.y2 > h || s.x2 > w ) return 0;
	rep( i, 0, n ){
		if( max( s.x1, v[i].x1 ) < min( s.x2, v[i].x2 ) && max( s.y1, v[i].y1 ) < min( s.y2, v[i].y2 )) return 0;
	}
	return 1;
}

int main(){
	int t, x, y;
	scanf("%d", &t );
	while( t-- && scanf("%d%d%d", &n, &w, &h ) != EOF ){
		n++;
		vector<Q> v(n);
		v[0] = Q( -1, -1, 0, 0 );
		rep( i, 1, n ) v[i].read();
		scanf("%d%d", &x, &y );
		Q s = Q(0, 0, x, y );
		int xa = INF, ya = INF;
		rep( i, 0, n ){
			rep( j, 0, n ){
				x = v[i].x2;
				y = v[j].y2;
				if( check( v, Q( s.x1+x, s.y1+y, s.x2+x, s.y2+y ) ) && ( y < ya || y == ya && x < xa ) ){
					ya = y;
					xa = x;
				}
			}
		}
		if( xa != INF ) printf("%d %d\n", xa, ya );
		else puts("Fail!");
	}	
}
