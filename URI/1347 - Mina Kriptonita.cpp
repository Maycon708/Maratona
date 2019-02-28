#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define debug(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define UNIQUE(c) { SORT(c); (c).resize( unique(ALL(c))-c.begin() ); }
#define pb push_back
#define sz size()
#define F first
#define S second
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
/*
	Compara double
        -1 se x < y
        0 se x == y
        1 se x > y
*/
inline int cmp( double x, double y = 0, double tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

/*
	Estrutura da dados para pontos
*/
struct point{
	double x, y;
	point(){}
	point(double x, double y): x(x), y(y){}
	point (point a, point b){ // vetor a->b
		 x = (b.x-a.x); y = (b.y-a.y);
	}
	point operator +(point q){ return point(x+q.x, y+q.y); }
	point operator -(point q){ return point(x-q.x, y-q.y); }
	point operator *(double t){ return point(x*t, y*t); }
	point operator /(double t){ return point(x/t, y/t); }

	int cmp(point q) const{
		if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y,q.y);
	}
	bool operator == (point q) const { return cmp(q) == 0; };
	bool operator != (point q) const { return cmp(q) != 0; };
	bool operator < (point q) const { return cmp(q) < 0; };

	double operator *(point q){ return x*q.x + y*q.y; }
	double operator %(point q){ return x*q.y - y*q.x; }

};
typedef vector<point> polygon;
typedef pair< point, point > wall;

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
	return cmp((q-p)%(r-q));
}

/*
	Encontra o vetor projecao do vetor A na direcao do vetor B
*/
point project(point a, point b) {
	return b * ((a*b) / (b*b));
}

/*
	Determina se q está entre o segmento fechado [p,r]
*/
bool between(point p, point q, point r){
	return ccw(p, q, r) == 0 && cmp((p - q)*(r - q)) <= 0;
}

/*
	Retorna o angulo entre os vetores qp e qr
*/
double angle(point p, point q, point r)
{
	point u = p-q, v = r-q;
	return atan2((u%v),(u*v));
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

	if (d1*d2 == -1 && d3*d4==-1) return true;
	if (d1==0 && between(c,a,d)) return true;
	if (d2==0 && between(c,b,d)) return true;
	if (d3==0 && between(a,c,b)) return true;
	if (d4==0 && between(a,d,b)) return true;
	return false;
}

//	Decide os os segmentos fechados [p,q] e [r,s] possuem algum ponto em comum
//  Versao IME-USP
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
	line(double m, point p){
		if (cmp(m) == 0) a = 0;
		else a = -m;
		b = 1;
		c = m*p.x - p.y;
	}

	line(point p1, point p2){
		if (fabs(p1.x - p2.x) < EPS){
			a = 1;	b = 0;	c = -p1.x;
		}else{
			a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
			b = 1;
			c = -(double)(a * p1.x) - p1.y;
		}
	}
};
bool areParallel( line r, line s) {
	return (cmp(r.a, s.a) == 0 && cmp(r.b, s.b) == 0 );
}
bool areSame( line r, line s ){
	return areParallel(r,s) && cmp(r.c, s.c) == 0;
}

// Ponto de Interseccao de duas linhas
bool areIntersect( line r, line s, point &p) {
	if (areParallel(r,s) || areSame(r,s)) return false;

	p.x = (s.b*r.c - r.b*s.c)/(s.a*r.b - r.a*s.b);

	if (fabs(r.b) > EPS) p.y = -(r.a * p.x + r.c)/r.b;
	else p.y = -(s.a * p.x + s.c)/s.b;
	return true;
}


// Ponto de Intersecção de duas linhas definidas por pontos
point line_intersect(point p, point q, point r, point s) {
	point a = q - p, b = s - r, c = point(p % q, r % s);
	return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}


//	Calcula a área orientada do polígono T
//  O sinal da área indica se é CW ou CCW a orientação
double poly_area( polygon & T) {
	if (T.size() < 3)	return 0;
	double s = 0;   int n = T.size();
	for (int i=0; i < n; i++)
		s += T[i]% T[(i+1)%n];
	return s/2;
}

// Aplicacao: Determina se um poligono qualquer é côncavo ou convexo
bool isConvex(polygon &T) {
	int n = (T.size());
	if (n < 3)	return false;
	int isLeft = ccw(T[0], T[1], T[2]);

	for (int i=1; i < n; i++)
		if (ccw(T[i], T[(i + 1)%n], T[(i + 2)%n]) != isLeft)
			return false;
	return true;
}

// Verificando ponto em relação a polígono
int in_poly(point p, polygon& T) {
    double a = 0; int N = T.size();

    for (int i = 0; i < N; i++) {
        if (between(T[i], p, T[(i+1) % N])) return -1;
        a += angle(T[i], p, T[(i+1) % N]);
    }
    return cmp(a) != 0;
}




//	Convex Hull
//	Encontrar um polígono convexo que engloba um conjunto de pontos
point pivot;
bool radial_lt(point a, point b){
	int R = ccw(pivot, a, b);
	if (R == 0) return (pivot-a)*(pivot-a) < (pivot-b)*(pivot-b);
	else return (R == 1);
}

polygon GrahamScan(vector<point> &T){

	//  Remove pontos duplicadados
	sort(ALL(T));
	T.resize(unique(ALL(T))-T.begin());

	int j = 0, k, n = T.size();
	polygon U;

    int P0; // P0 = index of min_element int T
    swap( T[0], T[P0] );
    pivot = T[0];

	sort(++T.begin(), T.end(), radial_lt);

	for (k=n-2; k>=0 && ccw(T[0],T[n-1],T[k]) == 0; k--);
	reverse((k+1) + ALL(T));

	for (int i=0; i < n; i++) {
		while (j>1 && ccw(U[j-2], U[j-1], T[i]) <= 0)
			U.pop_back(), j--;
		U.pb(T[i]); j++;
	}
	return U;
}


/*
    Determina o poligono intersecao dos dois poligonos convexos P e Q.

    ATENCAO: Tanto P quanto Q devem estar orientados positivamente.
    Testado:
		UVA - 137 Polygons
*/


polygon poly_intersect(polygon& P, polygon& Q) {
    int m = Q.size(), n = P.size();
    int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;

    polygon R;
    while ((aa < n || ba < m) && aa < 2*n && ba < 2*m) {
        point p1 = P[a], p2 = P[(a+1) % n], q1 = Q[b], q2 = Q[(b+1) % m];
        point A = p2 - p1, B = q2 - q1;
        int cross = cmp(A % B), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);

        if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A * B) < 0) {
            if (between(p1, q1, p2)) R.push_back(q1);
            if (between(p1, q2, p2)) R.push_back(q2);
            if (between(q1, p1, q2)) R.push_back(p1);
            if (between(q1, p2, q2)) R.push_back(p2);
            if (R.size() < 2) return polygon();
            inflag = 1; break;
        }
        else if (cross != 0 && seg_intersect(p1, p2, q1, q2)) {
            if (inflag == 0) aa = ba = 0;
            R.push_back(line_intersect(p1, p2, q1, q2));
            inflag = (hb > 0) ? 1 : -1;
        }

        if (cross == 0 && hb < 0 && ha < 0) return R;
        bool t = cross == 0 && hb == 0 && ha == 0;

        if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
            if (inflag == -1) R.push_back(q2);
            ba++; b++; b %= m;
        }
        else {
            if (inflag == 1) R.push_back(p2);
            aa++; a++; a %= n;
        }
    }

    if (inflag == 0) {
        if (in_poly(P[0], Q)) return P;
        if (in_poly(Q[0], P)) return Q;
    }
    R.erase(unique(ALL(R)), R.end());
    if (R.size() > 1 && R.front() == R.back()) R.pop_back();

    return R;
}



//	Spanning Circle
//  Menor circulo que engloba um conjunto de pontos
typedef pair<point, double> circle;

bool in_circle(circle C, point p){
	return cmp( norma(p-C.first), C.second) <= 0;
}
point circumcenter(point p, point q, point r) {
	point a = p-r, b = q-r, c = point(a*(p+r)/2, b*(q+r)/2);
	return point(c % point(a.y, b.y), point(a.x, b.x)%c) / (a%b);
}
circle spanning_circle(vector<point>& T) {
	int n = T.size();
	random_shuffle(ALL(T));
	circle C(point(), INF);

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

//	Menor distância entre dois pontos sobre uma esfera de raio r
//  Atenção: latitude e longitude devem estar em Radianos
double r;
double spherical_distance( double p_lat, double p_long, double q_lat, double q_long) {
	return r * acos( sin(p_lat) * sin(q_lat) +
					 cos(p_lat) * cos(q_lat) * cos(p_long) * cos(q_long) +
					 cos(p_lat) * cos(q_lat) * sin(p_long) * sin(q_long) );
}
typedef long long int ll;
ll readInt();

double D( point a, point b ){
	return hypot( a.x - b.x, a.y - b.y );
}

int m, l, n;

inline bool teleport( int a, int b ){
	return a >= 2*m && b >= 2*m && a < 2*m+l && b < 2*m+l;
}

typedef pair < int, int > ii;
typedef pair < int, double > id;

vector < id > adj[200];

ii pai[200][60];

void back( int i, int j ){
	while( pai[i][j] != ii(-1, -1 ) ){
		debug2( i, j );
		i = pai[i][j].F;
		j = pai[i][j].S;
	}
	debug2( i, j )
}

int N;

int dijkstra( int ini, int fim ){
	double dist[200][60];
	int vis[200][60];
	rep( i, 0, 200 ){
		rep( j, 0, 60 ){
			dist[i][j] = INF;
			vis[i][j] = 0;
			pai[i][j] = ii( -1, -1 );
		}
	}
	priority_queue < pair < double, ii > > pq;
	dist[ini][0] = 0;
	pq.push( mk( 0, ii( ini, 0 ) ) );
	while( !pq.empty() ){
		int u = pq.top().S.F;
		int d = pq.top().S.S;
		pq.pop();
		if( vis[u][d] ) continue;
		vis[u][d] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			double d_u_v = adj[u][i].S;
			if( teleport( u, v ) ){
				if( d >= n ) continue;
				if( dist[v][d+1] > dist[u][d] ){
					dist[v][d+1] = dist[u][d];
					pq.push( mk( -dist[v][d+1], ii( v, d+1 ) ) );
					pai[v][d+1] = ii( u, d );
				}
			}
			else{
				if( dist[v][d] > dist[u][d] + d_u_v ){
					dist[v][d] = dist[u][d] + d_u_v;
					pq.push( mk( -dist[v][d], ii( v, d ) ) );
					pai[v][d] = ii( u, d );
				}
			}
		}
	}
	double ans = INF;
	rep( i, 0, n+1 ){
		ans = min( ans, dist[fim][i] );
	}
	int f = ( ans - (int) ans ) * 1000;
	if( f >= 500 ) return (int) ans + 1;
	return (int) ans;
}

int main(){
//	freopen( "in.txt", "r", stdin );
//	freopen( "out.txt", "w", stdout );
	vector< wall > v;
	polygon p;
	while( 1 ){
		p.clear();
		v.clear();
		n = readInt();
		m = readInt();
		l = readInt();
		if( !n && !m && !l ) break;
		rep( i, 0, m ){
			point a, b;
			a = point( readInt(), readInt() );
			b = point( readInt(), readInt() );
			v.pb( wall( a, b ) );
			p.pb( a ); p.pb( b );
		}
		rep( i, 0, l ){
			point a = point( readInt(), readInt() );
			p.pb( a );
		}
		point origem = point( readInt(), readInt() );
		point destino = point( readInt(), readInt() );
		p.pb( origem ); p.pb( destino );
		rep( i, 0, p.size() ) adj[i].clear();
		rep( i, 0, p.size() ){
			rep( j, i+1, p.size() ){
				bool aux = 0;
				rep( k, 0, v.size() ){
					if( intersect_seg( p[i], p[j], v[k].F, v[k].S ) )
						if( p[i] != v[k].S && p[i] != v[k]. F  ) 
							if( p[j] != v[k].F && p[j] != v[k].S ){ aux = 1; break; }
				}
				if( aux ) continue;
				if( teleport( i, j ) ){
					adj[i].pb( id( j, 0 ) );
					adj[j].pb( id( i, 0 ) );
				}
				else{
					double d = D( p[i], p[j] );
					adj[i].pb( id( j, d ) );
					adj[j].pb( id( i, d ) );
				}
			}
		}
		int ans = dijkstra( p.size()-2, p.size()-1 );
		printf("%d\n", (ans) );
//		back( p.size()-1, 0 );
	}

}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}


