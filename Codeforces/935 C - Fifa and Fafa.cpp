#include <bits/stdc++.h>

#define INF 200*18+10
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
#define EPS 1e-12

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
typedef long double ld;

//***[Inicio] Funcoes que usam numeros complexos para pontos***
typedef complex<ld> cxpt; 
struct circle {
    cxpt c; ld r;
    circle(cxpt c, ld r) : c(c),r(r){}
    circle(){}
};
ld cross(const cxpt &a, const cxpt &b) {
    return imag(conj(a)*b);
}
ld dot(const cxpt &a, const cxpt &b) {
    return real(conj(a)*b);
}
 
// Line-circle intersection
// Intersects (infinite) line a-b with circle c
// Intersection points are in 'inter'
// 0 -> no intersection, 1 -> tangent, 2 -> two intersections
int line_circ_inter(cxpt a, cxpt b, circle c, vector<cxpt> &inter){
    c.c -= a; b -= a;
    cxpt m = b*real(c.c/b);
    ld d2 = norm(m-c.c);
    if (d2 > c.r*c.r) return 0;
    ld l = sqrt((c.r*c.r-d2)/norm(b));
    inter.push_back(a + m + l*b);
    if(abs(l)>EPS)
        inter.push_back(a + m - l*b);
    return inter.size();
}


ld _dist( ld x1, ld y1, ld x2, ld y2 ){
	ld dx = x1 - x2, dy = y1 - y2;
	return dx * dx + dy * dy;
}

int main(){
	
	ld R, x1, x2, y1, y2;
	cout <<  fixed << setprecision(20);
	
	while( cin >> R >> x1 >> y1 >> x2 >> y2 ){
		if( _dist( x1, y1, x2, y2 ) >= R*R ){
			cout << x1 << " " << y1 << " " << R << endl;
			continue;
		} 
		if( fabs(x1-x2) < EPS && fabs(y1-y2) < EPS ){
			cout << x1 << " " << y1+R/2 << " " << R/2 << endl;
			continue;
		}
		circle c = circle( cxpt(x1, y1), R);
		cxpt p1 = cxpt(x1, y1), p2 = cxpt(x2, y2);
		
		if( p1 == p2 ) p1 += cxpt(EPS, EPS);
		vector<cxpt> inter;
		line_circ_inter(p1, p2, c, inter );
		
		
		
		ld x3 = real(inter[0]), y3 = imag(inter[0]);
		ld x4 = real(inter[1]), y4 = imag(inter[1]);
		ld x5, y5;
		
		
		if( _dist(x2, y2, x3, y3) > _dist(x2, y2, x4, y4 ) ){
			x5 = (x3+x2)/2;
			y5 = (y3+y2)/2;
		}
		else{
			x5 = (x4+x2)/2;
			y5 = (y4+y2)/2;
		}
		
		cout << x5 << " " << y5 << " " << sqrt(_dist(x2, y2, x5, y5)) << endl;
	}
	
}
