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


/*
	Compara double
        -1 se x < y
        0 se x == y
        1 se x > y
*/
inline int cmp( double x, double y = 0, double tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

//	Estrutura da dados para pontos 2D
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
	
	friend ostream& operator <<(ostream& o, point p) {
		return o << "(" << p.x << ", " << p.y << ")";
	}

};
typedef vector<point> polygon;
#define vec(a,b) (b-a)
/* modulo de um vetor = sqrt(ux*ux + uy*uy) */
double norma(point u) {
	return sqrt(u*u);
}

int ccw(point p, point q, point r) {
	return cmp(vec(p,q) % (vec(q,r)));
}

point project(point a, point b) {
	return b * ((a*b) / (b*b));
}

bool between(point p, point q, point r){
	return ccw(p, q, r) == 0 && cmp(vec(q, p) * vec(q, r)) <= 0;
}


inline double PtSeg(point p, point a, point b){
	point pp = a + project(p-a, b-a);
	if (between(a,pp,b)) return norma(p-pp);
	else return min(norma(p-a), norma(p-b));
}

inline bool in( point a, point *b ){
	return a.x >= b[0].x && a.x <= b[2].x && a.y >= b[0].y && a.y <= b[2].y;
}

inline bool check( point *a, point *b, double d ){
	rep( i, 0, 4 ) if( in( a[i], b ) ) return 1;
	double ans = INF;
	rep( i, 0, 4 ){
		ans = min( ans, PtSeg( a[i], b[0], b[1] ) );
		ans = min( ans, PtSeg( a[i], b[1], b[2] ) );
		ans = min( ans, PtSeg( a[i], b[2], b[3] ) );
		ans = min( ans, PtSeg( a[i], b[3], b[0] ) );
		if( ans <= d ) return true;
	}
	rep( i, 0, 4 ) swap( a[i], b[i] );
	rep( i, 0, 4 ){
		ans = min( ans, PtSeg( a[i], b[0], b[1] ) );
		ans = min( ans, PtSeg( a[i], b[1], b[2] ) );
		ans = min( ans, PtSeg( a[i], b[2], b[3] ) );
		ans = min( ans, PtSeg( a[i], b[3], b[0] ) );
		if( ans <= d ) return true;
	}
	return 0;
}

void build( point *a, double x, double y, double l ){
	int dx[] = { -1, 1, 1, -1 };
	int dy[] = { -1, -1, 1, 1 };
	rep( i, 0, 4 ) a[i] = point( x+dx[i]*l/2, y+dy[i]*l/2 );
}

int main(){
	
	int n;
	double d, x, y, l;
	
	scanf("%d%lf", &n, &d );
	point v[2][4];
	scanf("%lf%lf%lf", &x, &y, &l );
	build( v[0], x, y, l );
	int op = 1, ans = 1;

	rep( i, 1, n ){
		scanf("%lf%lf%lf", &x, &y, &l );
		build( v[op], x, y, l );	
		if(!check( v[1-op], v[op], d ) ){
			puts("OUCH");
			return 0;
		}
		op = 1-op;
	}
	
	puts("YEAH");
		
		
	return 0;
}

