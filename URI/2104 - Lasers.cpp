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

int ccw(point p, point q, point r) {
	return cmp(vec(p,q) % (vec(q,r)));
}

double poly_area( polygon& T ) {
	if (T.size() < 3) return 0;
	double s = 0;   int n = T.size();
	rep(i, 0, n)
		s += T[i]% T[(i + 1)%n];
	return fabs(s / 2);
}

point pivot;
bool radial_lt(point a, point b){
	int R = ccw(pivot, a, b);
	if (R == 0) return (pivot-a)*(pivot-a) < (pivot-b)*(pivot-b);
	else return (R == 1);
}

polygon GrahamScan(vector<point> &T){
	sort(all(T));
	T.resize(unique(all(T))-T.begin());

	int j = 0, k, n = T.size();
	polygon U;

    int P0 = min_element(all(T)) - T.begin();  
    pivot = T[P0];
    swap(T[0], T[P0]);
	sort(++T.begin(), T.end(), radial_lt);
	
	for (k=n-2; k>=0 && ccw(T[0],T[n-1],T[k]) == 0; k--);
	reverse((k+1) + all(T));

	for (int i = 0; i < n; i++) {
		while (j>1 && ccw(U[j-2], U[j-1], T[i]) < 0)
			U.pop_back(), j--; 
		U.pb(T[i]); j++;
	}
	return U;
}

double busca( double z, double dz ){
	double lo = 0, hi = 1/EPS;
	while( fabs(lo-hi) > EPS ){
		double mid = (lo+hi)/2;
		if( cmp(z+dz*mid) == cmp(z) ) lo = mid;
		else hi = mid;
	}
	return lo;
}


int main(){
	int n;
	double xp, yp, zp, x, y, z;
	while( scanf("%d", &n ) != EOF && n ){
		vector<point> v;
		scanf("%lf%lf%lf", &xp, &yp, &zp );
		rep( i, 0, n ){
			scanf("%lf%lf%lf", &x, &y, &z );
			double dx = x - xp, dy = y - yp, dz = z - zp;
			double mod = sqrt( dx*dx + dy*dy + dz*dz );
			dx /= mod, dy /= mod, dz /= mod; 
			double k = busca(zp, dz);
			v.pb( point(xp+dx*k, yp+dy*k) );
		}
		v = GrahamScan(v);
		printf("%.2lf\n", poly_area(v) );
	} 
}
