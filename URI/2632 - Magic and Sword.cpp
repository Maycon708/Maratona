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
typedef long double ld;
 
const int INF = 0x3f3f3f3f;
const ld EPS = 1e-9;
 
 
/*
	Compara double
	    -1 se x < y
	    0 se x == y
	    1 se x > y
*/
inline int cmp( ld x, ld y = 0, ld tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}
 
//  Estrutura da dados para pontos 2D
struct point{
	ld x, y;
	point(ld x=0, ld y=0): x(x), y(y){}
	void read(){
	    cin >> x >> y;
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
	bool operator > (point q) const { return cmp(q) > 0; };
	 
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
	Funcao determina se o giro formado pela sequencia P->Q e Q->R ? para direita ou para esquerda
	Retorna
	     1 Para esquerda
	     0 Colineares
	    -1 Para direita
*/
int ccw(point p, point q, point r) {
	return cmp(vec(p,q) % (vec(q,r)));
}
 
//  Encontra o vetor projecao de A na direcao do vetor B
point project(point a, point b) {
	return b * ((a*b) / (b*b));
}
 
//  Determina se q est? entre o segmento fechado [p,r], inclusive
bool between(point p, point q, point r){
	return ccw(p, q, r) == 0 && cmp(vec(q, p) * vec(q, r)) <= 0;
}
 
//  Retorna o angulo entre os vetores qp e qr
ld angle(point p, point q, point r){
	point u = vec(q, p), v = vec(q, r);
	return atan2((u % v), (u * v));
}
 
 
// Rotaciona ponto P em rela??o a origem T graus no sentido antihor?rio
point rotate(point p, ld t){
	// t = t * acos(-1)/180.0;   //conversao para radianos
	return point(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}
 
 
//  Distancia do ponto p ao segmento fechado [a,b]
ld PtSeg(point p, point a, point b){
	point pp = a + project(p-a, b-a);
	if (between(a,pp,b)) return norma(p-pp);
	else return min(norma(p-a), norma(p-b));
}
 
bool dentro( point a, point b, point c ){
	return a.x >= b.x && a.x <= c.x && a.y >= b.y && a.y <= c.y;
}

int main(){
	int mat[4][4] = { { 0, 20, 30, 50 }, { 0, 10, 25, 40 }, { 0, 25, 55, 70 }, { 0, 18, 38, 60 } };
	int power[] = { 200, 300, 400, 100 };
	int t, w, h, n, id, z = 0;
	char s[100];
	scanf("%d", &t );
	while( t-- ){
		point a, b;
		scanf("%d%d", &w, &h );
		a.read();
		scanf("%s%d", s, &n );
		b.read();
		 
		if( s[0] == 'f' ) id = 0;
		else if( s[0] == 'w' ) id = 1;
		else if( s[0] == 'e' ) id = 2;
		else if( s[0] == 'a' ) id = 3;
		else printf("%d\n", n/z );
		ld dist = min(PtSeg(b, a, point(a.x,a.y+h)), min(PtSeg(b, a, point(a.x+w,a.y)),min(PtSeg(b,point(a.x+w,a.y ),point(a.x+w,a.y+h )),PtSeg(b,point(a.x+w,a.y+h),point(a.x,a.y+h)))));
		if( cmp( dist, mat[id][n] ) != 1 || dentro( b, a, point(a.x+w, a.y+h) ) ) printf("%d\n", power[id] );
		else puts("0");
	}
}
