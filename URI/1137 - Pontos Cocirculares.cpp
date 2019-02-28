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
#define EPS 1e-5
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

inline int cmp( double x, double y = 0, double tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

struct point{
	double x, y;
	point(double x=0, double y=0): x(x), y(y){}
	void read(){
		scanf("%lf %lf", &x, &y);
	}
	point operator +(point q){ return point(x+q.x, y+q.y); }
	point operator -(point q){ return point(x-q.x, y-q.y); }
	point operator *(double t){ return point(x*t, y*t); }
	point operator /(double t){ return point(x/t, y/t); }
	
	double operator *(point q){ return x*q.x + y*q.y; }
	double operator %(point q){ return x*q.y - y*q.x; }
	
	int cmp(point q) const{
		if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y,q.y);
	}
	bool operator == (point q) const { return cmp(q) == 0; };
	bool operator != (point q) const { return cmp(q) != 0; };
	bool operator < (point q) const { return cmp(q) < 0; };
};

typedef pair<point, double> circle;

circle circumcenter(point p, point q, point r) {
	point a = p-r, b = q-r, c = point( a * (p+r)/2, b * (q+r)/2);
	point d = point(c % point(a.y, b.y), point(a.x, b.x)%c) / (a%b);
	double dx = fabs( p.x - d.x ), dy = fabs( p.y - d.y );
	return mk( d, dx*dx + dy*dy );
}

inline bool colineares( point a, point b, point c ){
	return ! cmp( ( a-b )%( c-b ) );
}

int main(){
	int n;
	point v[101];
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		vector < circle > centers;
		rep( i, 0, n ) v[i].read();
		rep( i, 0, n ){
			rep( j, i+1, n ){
				rep( k, j+1, n ){
					if( colineares( v[i], v[j], v[k] ) ) continue;
					centers.pb( circumcenter( v[i], v[j], v[k] ) );
				}
			}
		}
		int resp = 0;
		rep( i, 0, centers.size() ){
			int cnt = 0;
			rep( j, 0, n ){
				double dx = fabs( v[j].x - centers[i].F.x );
				double dy = fabs( v[j].y - centers[i].F.y );
				if( !cmp( dx*dx + dy*dy, centers[i].S ) ) cnt++;
			}
			resp = max( resp, cnt );
		}
		if( centers.empty() ) resp = min( 2, n );
		printf("%d\n", resp );
	}
}

