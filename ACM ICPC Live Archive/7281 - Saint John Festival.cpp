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
	ll x, y;
	point(ll x=0, ll y=0): x(x), y(y){}
	void read(){
		scanf("%lld%lld", &x, &y);
	}
	point operator +(point q){ return point(x+q.x, y+q.y); }
	point operator -(point q){ return point(x-q.x, y-q.y); }
	point operator *(ll t){ return point(x*t, y*t); }
	point operator /(ll t){ return point(x/t, y/t); }
	
	ll operator *(point q){ return x*q.x + y*q.y; }
	ll operator %(point q){ return x*q.y - y*q.x; }
	
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

//	Determina se q está entre o segmento fechado [p,r], inclusive
bool between(point p, point q, point r){
	return ccw(p, q, r) == 0 && cmp(vec(q, p) * vec(q, r)) <= 0;
}

//	Retorna o angulo entre os vetores qp e qr
double angle(point p, point q, point r){
	point u = vec(q, p), v = vec(q, r);
	return atan2((u % v), (u * v));
}

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
		while (j>1 && ccw(U[j-2], U[j-1], T[i]) <= 0)
			U.pop_back(), j--; // Descarta U.back()
		U.pb(T[i]); j++;
	}
	return U;
}

int main(){
	
	int n, m;
	while( scanf("%d", &n ) != EOF ){
		polygon a, b, c;
		a.resize(n);
		rep( i, 0, n ) a[i].read();
		a = GrahamScan(a);
		
		scanf("%d", &m );
		c.resize(m);
		rep( i, 0, m ) c[i].read();
		
		int t = a.size()-1;
		b.pb(a[0]);
		while( a[t] < a[t-1] ){
			b.push_back(a[t--]);
			a.pop_back();
		}
		b.pb(a[t]);
		sort(all(c));
		
	
		int aa = 1, bb = 1;
		int cnt = 0;
		rep( i, 0, c.size() ){
			while( aa+1 < a.size() && a[aa].x <= c[i].x ) aa++;
			while( bb+1 < b.size() && b[bb].x <= c[i].x ) bb++;
			polygon t1;
			t1.pb(a[aa-1]), t1.pb(a[aa]), t1.pb(b[bb]), t1.pb(b[bb-1]);
			if( in_poly( c[i], t1 ) ) cnt++;
		}
		printf("%d\n", cnt );
	}	
		
	return 0;
}

