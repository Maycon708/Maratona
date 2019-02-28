#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c) { sort(all(c); (c).resize( unique(all(c))-c.begin() ); }
#define pb push_back

#define debug(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v,n) {cout<<#v<<"[] ={ "; rep(i,0,n) cout<<v[i]<<" "; cout << "}\n";}

#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 101010;

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c) { sort(all(c); (c).resize( unique(all(c))-c.begin() ); }
#define pb push_back

#define debug(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v,n) {cout<<#v<<"[] ={ "; rep(i,0,n) cout<<v[i]<<" "; cout << "}\n";}

#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> ii;
typedef long long ll;
typedef double ld;

const double EPS = 1e-11;

inline int cmp( double x, double y = 0, double tol = EPS) {
	return ( (x <= y + tol) ? (x + tol <= y) ? -1 : 0 : 1);
}
#define gc getchar_unlocked

int scan(){
    register int c = gc(), x = 0, aux = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() ) if( c == '-' ) aux = 1;
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
    if( aux ) return -x;
	return x;
}

struct point{
	double x, y;
	point(double x=0, double y=0): x(x), y(y){}
	void read(){
		x = scan();
		y = scan();
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

double norma(point u) {
	return sqrt(u*u);
}

int ccw(point p, point q, point r) {
	return cmp(vec(p,q) % (vec(q,r)));
}

vector<point> m[N];
ld pd[N][2][2];
int n;
point pivot, p2;

ld solve( int pos, int a, int l ){
	if( pos == n-1 ){
		if( ccw( m[pos-1][l], m[pos][a], pivot ) > 0 &&  ccw( m[pos][a], pivot, p2 ) > 0 ) return 0;
		else return 1LL << 62;
	}
	if( pd[pos][a][l] >= -1 ) return pd[pos][a][l];
	ld ans = 1LL << 62;
	rep( i, 0, 2 ){
		if( ccw( m[pos-1][l], m[pos][a], m[pos+1][i] ) >= 0 ){
			ld c = fabs( vec( pivot, m[pos][a] )%vec( pivot, m[pos+1][i] ) )/2;
			ld b = solve( pos+1, i, a );
			ans = min( ans, c+b );
		}
	}
	return pd[pos][a][l] = ans;
}

ld solve1( int pos, int a, int l ){
	if( pos == n-1 ){
		if( ccw( m[pos-1][l], m[pos][a], pivot ) < 0 &&  ccw( m[pos][a], pivot, p2 ) < 0 ) return 0;
		else return 1LL << 62;
	}
	if( pd[pos][a][l] >= -1 ) return pd[pos][a][l];
	ld ans = 1LL << 62;
	rep( i, 0, 2 ){
		if( ccw( m[pos-1][l], m[pos][a], m[pos+1][i] ) <= 0 ){
			ld c = fabs( vec( pivot, m[pos][a] )%vec( pivot, m[pos+1][i] ) )/2;
			ld b = solve1( pos+1, i, a );
			ans = min( ans, c+b );
		}
	}
	return pd[pos][a][l] = ans;
}


int main(){
	
	point a, b, v[N];
	while( 42 ){
		n = scan();
		if( !n ) break;
		rep( i, 0, n ){
			v[i].read();
		}
		pivot = v[0];
		a.read(), b.read();
		
		rep( i, 0, n ){
			m[i].clear();
			m[i].pb( ( a + v[i] )/2 );
			m[i].pb( ( b + v[i] )/2 );
		}
		ld ans = 1LL << 62;
		rep( i, 0, 2 ){
			pivot = m[0][i];
			rep( j, 0, 2 ){
				p2 = m[1][j];
				rep( k, 0, n ) pd[k][0][0] = pd[k][0][1] = pd[k][1][0] = pd[k][1][1] = -10;
				ans = min( ans, solve( 1, j, i ) );
				rep( k, 0, n ) pd[k][0][0] = pd[k][0][1] = pd[k][1][0] = pd[k][1][1] = -10;
				ans = min( ans, solve1( 1, j, i ) );
			}
		}
		cout << fixed << setprecision(3) << ans << "\n";
	}
	
	return 0;
}
