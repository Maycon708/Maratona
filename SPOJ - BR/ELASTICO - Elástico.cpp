#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c) { sort(all(c); (c).resize( unique(all(c))-c.begin() ); }
#define pb push_back

#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v,n) {cout<<#v<<"[] ={ "; rep(i,0,n) cout<<v[i]<<" "; cout << "}\n";}

#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

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
typedef vector<point> polygon;

#define vec(a,b) (b-a)

double norma(point u) {
	return sqrt(u*u);
}

int ccw(point p, point q, point r) {
	return cmp(vec(p,q) % (vec(q,r)));
}

point pivot = point( 0, 0 );

point v[210];

bool radial_lt(point a, point b){
	int R = ccw(pivot, a, b);
	if (R == 0) return (pivot-a)*(pivot-a) < (pivot-b)*(pivot-b);
	else return (R == 1);
}

int pd[210][210], n;

int solve( int l, int a ){
	if( a == n-1 ) return 1;
	if( pd[l][a] != -1 ) return pd[l][a];
	int ans = 0;
	rep( i, a+1, n ){
		if( ccw( v[l], v[a], v[i] ) > 0 ) 
			ans = max( ans, 1 + solve( a, i ) );
	}
	return pd[l][a] = ans;
}

int main(){
	
	point a;
	int t = 1;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		memset( pd, -1, sizeof pd );
		v[0] = v[n+1] = pivot;
		rep( i, 1, n+1 ){
			v[i].read();
		}
		n += 2;
		sort( v+1, v+n-1, radial_lt );
		
		int ans = 0;
		rep( i, 1, n-1 ){
			ans = max( ans, solve( 0, i ) );
		}
		
		printf("Teste %d\n", t++ );
		printf("%d\n", ans );
		printf("\n");
	}
	
	return 0;
}

