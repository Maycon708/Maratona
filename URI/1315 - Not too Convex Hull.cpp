#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(ll i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c) { sort(all(c); (c).resize( unique(all(c))-c.begin() ); }
#define pb push_back

#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v,n) {cout<<#v<<"[] ={ "; rep(i,0,n) cout<<v[i]<<" "; cout << "}\n";}

#define mp make_pair
#define fst first
#define snd second

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define F first
#define S second
#define mk make_pair

typedef long long ll;
typedef pair<ll,ll> ii;

const ll INF = 1LL << 60;
const double EPS = 1e-11;


/*
	Compara double
        -1 se x < y
        0 se x == y
        1 se x > y
*/
inline ll cmp( double x, double y = 0, double tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

//	Estrutura da dados para pontos 2D
struct point{
	ll x, y;
	point(ll x=0, ll y=0): x(x), y(y){}
	void read(){
		scanf("%lld %lld", &x, &y);
	}
	point operator +(point q){ return point(x+q.x, y+q.y); }
	point operator -(point q){ return point(x-q.x, y-q.y); }
	point operator *(ll t){ return point(x*t, y*t); }
	point operator /(ll t){ return point(x/t, y/t); }
	
	ll operator *(point q){ return x*q.x + y*q.y; }
	ll operator %(point q){ return x*q.y - y*q.x; }
	
	ll cmp(point q) const{
		if(ll t = ::cmp(x, q.x)) return t;
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
ll norma(point u) {
	return sqrt(u*u);
}

/*
	Funcao determina se o giro formado pela sequencia P->Q e Q->R é para direita ou para esquerda
	Retorna
		 1 Para esquerda
		 0 Colineares
		-1 Para direita
*/
ll ccw(point p, point q, point r) {
	return cmp(vec(p,q) % (vec(q,r)));
}

//	Convex Hull
//	Encontrar um polígono convexo que engloba um conjunto de pontos (orientado +)
point pivot;
bool radial_lt(point a, point b){
	ll R = ccw(pivot, a, b);
	if (R == 0) return (pivot-a)*(pivot-a) < (pivot-b)*(pivot-b);
	else return (R == 1);
}

ll C[200][200], pd[200][200][200];

void GrahamScan(vector<point> &T, ll p ){

	ll j = 1, n = T.size(), k = (p+1 == n) ? 0 : p+1;
	polygon U;
	
	U.pb(T[p]);
	ll area = 0;
	C[p][p] = INF;
	ll i;
	for( i = k; i != p; i = (i+1)%n ){
		if( ccw( pivot, T[p], T[i] ) == -1 ){
			C[p][i] = INF;
			continue;
		}
		while (j>1 && ccw(U[j-2], U[j-1], T[i]) < 0)
			area -= norma((U[j-2]-U[j-1])%(pivot-U[j-1])), U.pop_back(), j--; // Descarta U.back()
		U.pb(T[i]); j++;
		area += norma( (U[j-2]-U[j-1])%(pivot-U[j-1]) );
		C[p][i] = area;
	}
}

ll solve( ll i, ll j, ll e ){
	if( i == j ) return INF;
	if( e == 1 ) return C[i][j];
	ll &ans = pd[i][j][e];
	if( ans == -1 ){
		ans = INF;
		rep( k, i, j ) ans = min( ans, solve(i, k, e-1) + C[k+1][j] );
	}
	return ans;
}

int main(){
	
	ll n, k;
	while( scanf("%lld%lld", &k, &n ) != EOF && n ){
		n--;
		polygon v(n);
		pivot.read();
		bool troca;
		rep( i, 0, n ) v[i].read();
		do{
			troca = 0;
			rep( i, 0, n-1 ){
				if( !radial_lt( v[i], v[i+1] ) ){
					swap( v[i], v[i+1] );
					troca = 1;
				}
			}
		}while(troca);
		
		rep( i, 0, n ) GrahamScan(v, i);
		memset( pd, -1, sizeof pd );
		printf("%.2f\n", solve(0, n-1, k)/2.0 );	
	}
		
	return 0;
}

