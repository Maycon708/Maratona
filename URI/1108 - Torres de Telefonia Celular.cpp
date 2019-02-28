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

//	Spanning Circle
//  Menor circulo que engloba um conjunto de pontos O(n^3)
typedef pair<point, double> circle;

bool in_circle(circle &C, point p){
	return cmp( norma(p-C.first), C.second) <= 0;
}
point circumcenter(point p, point q, point r) {
	point a = p-r, b = q-r, c = point(a*(p+r)/2, b*(q+r)/2);
	return point(c % point(a.y, b.y), point(a.x, b.x)%c) / (a%b);
}

circle spanning_circle( vector<point>& T ) {
	int n = T.size();
	random_shuffle(all(T));
	circle C(point(), -INF);

	for (int i = 0; i < n; i++) if (!in_circle(C, T[i])) {
		C = circle(T[i], 0);
		for (int j = 0; j < i; j++) if (!in_circle(C, T[j])) {
			C = circle((T[i] + T[j]) / 2, norma(T[i] - T[j]) / 2);
			for (int k = 0; k < j; k++) if (!in_circle(C, T[k])) {
				point o = circumcenter(T[i], T[j], T[k]);
				C = circle(o, norma(o - T[k]));
			}
		}
	}
	return C;
}

#define F first
#define S second

int main(){
	
	point v[50];
	int n;
//	freopen("celular.in", "r", stdin );
	while( scanf("%d", &n ) != EOF && n ){
		rep( i, 0, n ) v[i].read();
		vector<point> aux;
		double area = 1 << 30;
		rep( i, 0, n ){
			rep( j, i+1, n ){
				rep( k, j+1, n+1 ){
					aux.pb(v[i]);
					aux.pb(v[j]);
					if( k != n ) aux.pb(v[k]);
					circle a = spanning_circle(aux);
					aux.clear();
					if( a.S >= area ) continue;
					rep( l, 0, n ) if( !in_circle( a, v[l] ) ) aux.pb(v[l]);
					circle b = spanning_circle(aux);
					area = min( area, max( a.S, b.S ) );
					aux.clear();
				}
			}
		}
		printf("%.2f\n", area );
	}
		
	return 0;
}

