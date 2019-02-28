#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

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

double norma(point u){
	return sqrt(u*u);
}

int ccw(point p, point q, point r){
	return cmp((q-p)%(r-q));
}

point project(point a, point b){
	return b * ((a*b) / (b*b));
}

bool between(point p, point q, point r){
	return ccw(p, q, r) == 0 && cmp((p - q)*(r - q)) <= 0;
}

double angle(point p, point q, point r){
	point u = p-q, v = r-q;
	return atan2((u%v),(u*v));
}

int in_poly(point p, polygon& T) {
    double a = 0; int N = T.size();

    for (int i = 0; i < N; i++) {
        if( between(T[i], p, T[(i+1) % N])) return -1;
        a += angle(T[i], p, T[(i+1) % N]);
    }
    return cmp(a) != 0;
}

int main(){
	int test = 1;
//	freopen( "out.txt", "w+", stdout );
	while( 1 ){
		int n = readInt();
		if( !n ) break;
//		if( test != 1 ) printf("\n");
		polygon T;
		point p, f;
		rep( i, 0, n ){
			p.x = readInt();
			p.y = readInt();
			T.pb( p );
		}
		f.x = readInt();
		f.y = readInt();
		bool aux = in_poly( f, T );
		int m = readInt();
		printf("Instancia %d\n", test++ );
		rep( i, 1, m+1 ){
			p.x = readInt();
			p.y = readInt();
			int k = in_poly( p, T ); 
			if( k == -1 || ( k == aux ) ) printf("soldado %d defender\n", i );
			else printf("soldado %d espanhol\n", i );
		}
		printf("\n");
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


