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
};
typedef vector<point> polygon;
#define vec(a,b) (b-a)
/* modulo de um vetor = sqrt(ux*ux + uy*uy) */
double norma(point u) {
	return sqrt(u*u);
}

/*
	Funcao determina se o giro formado pela sequencia P->Q e Q->R é para direita ou para esquerda
	Retorna
		 1 Para esquerda
		 0 Colineares
		-1 Para direita
*/
int ccw(point p, point q, point r) {
	return cmp(vec(p,q) % (vec(q,r)));
}

//	Encontra o vetor projecao de A na direcao do vetor B
point project(point a, point b) {
	return b * ((a*b) / (b*b));
}

//	Determina se q está entre o segmento fechado [p,r], inclusive
bool between(point p, point q, point r){
	return ccw(p, q, r) == 0 && cmp(vec(q, p) * vec(q, r)) <= 0;
}

//	Retorna o angulo entre os vetores qp e qr
double angle(point p, point q, point r){
	point u = vec(q, p), v = vec(q, r);
	return atan2((u % v), (u * v));
}


//	Distancia do ponto p ao segmento fechado [a,b]
double PtSeg(point p, point a, point b) {
	if ( (b-a)*(p-a) <= 0 ) return norma(a-p);
	if ( (a-b)*(p-b) <= 0 ) return norma(b-p);
	return fabs((b-a)%(p-a)) / norma(a-b);
}

double PtSeg2(point p, point a, point b){
	point pp = a + project(p-a, b-a);
	if (between(a,pp,b)) return norma(p-pp);
	else return min(norma(p-a), norma(p-b));
}


//	Decide os os segmentos fechados [a,b] e [c,d] possuem algum ponto em comum
bool intersect_seg( point a, point b, point c, point d) {
	int d1, d2, d3, d4;
	d1 = ccw(c,a,d);    d2 = ccw(c,b,d);
	d3 = ccw(a,c,b);    d4 = ccw(a,d,b);

	if (d1 * d2 == -1 && d3 * d4 == -1) return true;
	if (d1 == 0 && between(c, a, d)) return true;
	if (d2 == 0 && between(c, b, d)) return true;
	if (d3 == 0 && between(a, c, b)) return true;
	if (d4 == 0 && between(a, d, b)) return true;
	return false;
}

//	Decide os os segmentos fechados [p,q] e [r,s] possuem algum ponto em comum
//  Versao USP
bool seg_intersect(point p, point q, point r, point s) {
    point A = q - p, B = s - r, C = r - p, D = s - q;

    int a = cmp(A % C) + 2 * cmp(A % D);
    int b = cmp(B % C) + 2 * cmp(B % D);
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || p == r || p == s || q == r || q == s) return true;
    int t = (p < r) + (p < s) + (q < r) + (q < s);
    return t != 0 && t != 4;
}

// Retas
// Equação: ax + by + c = 0;
struct line{
	double a, b, c;
	line(){}
	// coeficiente ang. e pnt
	line( double m, point p ){
		if (cmp(m) == 0) a = 0;
		else a = -m;
		b = 1;
		c = m*p.x - p.y;
	}

	// reta que passa por dois pnts
	line( point p1, point p2 ){
		if (fabs(p1.x - p2.x) < EPS){
			a = 1;	b = 0;	c = -p1.x;
		}else{
			a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
			b = 1;
			c = -(double)(a * p1.x) - p1.y;
		}
	}
	
	bool parallelTo(const line s){
		return cmp(a,s.a) == 0 && cmp(b,s.b) == 0;
	}
	
	bool sameAs(const line s){
		return this->parallelTo(s) && cmp(c,s.c) == 0;
	}
};

// Ponto de Interseçãoo de duas retas
bool areIntersect( line r, line s, point& p ) {
	if (r.parallelTo(s) || r.sameAs(s)) return true;

	p.x = (s.b*r.c - r.b*s.c)/(s.a*r.b - r.a*s.b);

	if (fabs(r.b) > EPS) p.y = -(r.a * p.x + r.c)/r.b;
	else p.y = -(s.a * p.x + s.c)/s.b;
	return true;
}


// Ponto de Intersecção de duas retas definidas por pontos
point line_intersection( point p, point q, point r, point s ) {
	point a = q - p, b = s - r, c = point(p % q, r % s);
	return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}


//	Calcula a área orientada do polígono T
//  O sinal da área indica se é CW ou CCW a orientação
double poly_area( polygon& T ) {
	if (T.size() < 3)	return 0;
	double s = 0;   int n = T.size();
	rep(i, 0, n)
		s += T[i]% T[(i + 1)%n];
	return s / 2;
}

// Aplicação: Determina se um polígono qualquer é côncavo ou convexo
// Convexo -> todos os angulos internos sao <= 180, Convêxo c.c.
// Atenção para pontos colineares
bool isConvex( polygon& T ) {
	int n = (T.size());
	if (n < 3)	return false;
	bool isLeft = ccw(T[0], T[1], T[2]);

	rep(i, 1, n)
		if (ccw(T[i], T[(i + 1)%n], T[(i + 2)%n]) != isLeft)
			return false;
	return true;
}

/*
	Verificando ponto em relação a polígono
	Funciona independentemente da orientação do polígono
	-1 borda, 0 fora, 1 dentro
*/
int in_poly(point p, polygon& T) {
    double a = 0; int N = T.size();
    rep(i, 0, N){
        if (between(T[i], p, T[(i + 1)%N])) return -1;
        a += angle(T[i], p, T[(i + 1)%N]);
    }
    return cmp(a) != 0;
}

//	Convex Hull
//	Encontrar um polígono convexo que engloba um conjunto de pontos (orientado +)
point pivot;
bool radial_lt(point a, point b){
	int R = ccw(pivot, a, b);
	if (R == 0) return (pivot-a)*(pivot-a) < (pivot-b)*(pivot-b);
	else return (R == 1);
}

polygon GrahamScan(vector<point> &T){
	//  Remove pontos duplicadados
	sort(all(T));
	T.resize(unique(all(T))-T.begin());

	int j = 0, k, n = T.size();
	polygon U;

    int P0 = min_element(all(T)) - T.begin();  
    // pivot = menor x, menor y
    pivot = T[P0];
    swap(T[0], T[P0]);
	sort(++T.begin(), T.end(), radial_lt);
	
	for (k=n-2; k>=0 && ccw(T[0],T[n-1],T[k]) == 0; k--);
	reverse((k+1) + all(T));

	// troque <= por < para manter pontos colineares
	for (int i = 0; i < n; i++) {
		while (j>1 && ccw(U[j-2], U[j-1], T[i]) < 0)
			U.pop_back(), j--; // Descarta U.back()
		U.pb(T[i]); j++;
	}
	return U;
}

int main(){

	polygon T;
	int n;
	while( scanf("%d", &n ) != EOF ){
		T.resize(n);
		rep( i, 0, n ) T[i].read();
		T = GrahamScan(T);	
		printf("%.2f\n", poly_area(T) );
	}
		
	return 0;
}

