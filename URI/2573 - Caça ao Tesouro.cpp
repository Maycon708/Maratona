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
#define EPS 1e-9

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

struct vec { 
	double x, y; // name: ‘vec’ is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {} 
};

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

vec toVec(point a, point b) {
	// convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y); 
}

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0; 
}

point lineIntersectSeg(point p, point q, point A, point B) {
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); 
}

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
	vector<point> P;
	for (int i = 0; i < (int)Q.size(); i++) {
		double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
		if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
		if (left1 > -EPS) P.push_back(Q[i]);
		// Q[i] is on the left of ab
		if (left1 * left2 < -EPS)
		// edge (Q[i], Q[i+1]) crosses line ab
		P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
	}
	if (!P.empty() && !(P.back() == P.front()))
	P.push_back(P.front());
	// make P’s first point = P’s last point
	return P; 
}
//*/

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) { // returns angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

double area(const vector<point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size()-1; i++) {
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0; 
}

#define vec(a,b) (b-a)
bool between(point p, point q, point r){
	return ccw(p, q, r) == 0 && cmp(vec(q, p) * vec(q, r)) <= 0;
}

double angle2(point p, point q, point r){
	point u = vec(q, p), v = vec(q, r);
	return atan2((u % v), (u * v));
}

int in_poly(point p, vector<point>& T) {
    double a = 0; int N = T.size();
    rep(i, 0, N-1){
        if (between(T[i], p, T[(i + 1)%N])) return -1;
        a += angle2(T[i], p, T[(i + 1)%N]);
    }
    return cmp(a) != 0;
}

int main(){
	
	double x, y, a1, a2, b1, b2;
	while( scanf("%lf%lf", &x, &y ) != EOF ){
		scanf("%lf%lf", &a1, &b1 );
		scanf("%lf%lf", &a2, &b2 );
		double at = x * y;
		vector<point> q, ans;
		q.pb( point( 0, 0 ) );
		q.pb( point( x, 0 ) );
		q.pb( point( x, y ) );
		q.pb( point( 0, y ) );
		q.pb( point( 0, 0 ) );
		point mid = point( (a1+a2)/2, (b1+b2)/2 ), aux;
		double xx = mid.x-a1, yy = mid.y-b1;
		if( !xx ) aux = point( mid.x+1, mid.y );
		else if( !yy ) aux = point( mid.x, mid.y+1 );
		else{
			double m = -xx/yy;
			aux = point( 0, mid.y + m * - mid.x );
		}
		ans = cutPolygon(mid, aux, q);
		double area1 = area(ans), area2 = at-area1;
		if( in_poly( point(a2, b2), ans ) ) swap( area1, area2 );
		printf("%.6f %.6f\n", area1/at, area2/at );
	}	

}
