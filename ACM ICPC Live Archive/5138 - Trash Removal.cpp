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
typedef double ld;

const int INF = 0x3f3f3f3f;
const ld EPS = 1e-11;


/*
	Compara ld
        -1 se x < y
        0 se x == y
        1 se x > y
*/
inline int cmp( ld x, ld y = 0, ld tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

//	Estrutura da dados para pontos 2D
struct point{
	ld x, y;
	point(ld x=0, ld y=0): x(x), y(y){}
	void read(){
		scanf("%lf %lf", &x, &y);
	}
	point operator +(point q){ return point(x+q.x, y+q.y); }
	point operator -(point q){ return point(x-q.x, y-q.y); }
	point operator *(ld t){ return point(x*t, y*t); }
	point operator /(ld t){ return point(x/t, y/t); }
	
	ld operator *(point q){ return x*q.x + y*q.y; }
	ld operator %(point q){ return x*q.y - y*q.x; }
	
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
ld norma(point u) {
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
ld angle(point p, point q, point r){
	point u = vec(q, p), v = vec(q, r);
	return atan2((u % v), (u * v));
}


// Rotaciona ponto P em relação a origem T graus no sentido antihorário
point rotate(point p, ld t){
	// t = t * acos(-1)/180.0; 	 //conversao para radianos
	return point(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));	
}


//	Distancia do ponto p a reta [a,b]
ld Pt2Line(point p, point a, point b) {
	return ((a-p)%(b-p))/norma(a-b);
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
		while (j>1 && ccw(U[j-2], U[j-1], T[i]) <= 0)
			U.pop_back(), j--; // Descarta U.back()
		U.pb(T[i]); j++;
	}
	return U;
}

int main(){
	int n, test = 1;
	while( scanf("%d", &n) != EOF && n ){
		polygon v(n);
		rep( i, 0, n ) v[i].read();
		v = GrahamScan(v);
		ld ans = INF;
		n = v.size();
		rep( i, 0, n ){
			ld aux = 0;
			rep( j, 0, n ){
				if( j == i || j == (i+1)%n ) continue;
				aux = max( aux, Pt2Line( v[j], v[i] , v[(i+1)%n] )); 
			}
			ans = min( ans, aux );
		}
		printf("Case %d: %.2lf\n", test++, ans + 0.00499 );
	}	
	return 0;
}

