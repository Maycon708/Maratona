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

inline int cmp( ll x, ll y = 0 ){
	if( x < y ) return -1;
	return x != y;
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

struct point{
	ll x, y;
	point(ll x = 0, ll y = 0): x(x), y(y){}
	void read(){
		x = readInt();
		y = readInt();
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

point pivot;

point v[210];

bool radial_lt(point a, point b){
	int R = ccw(pivot, a, b);
	if (R == 0) return (pivot-a)*(pivot-a) < (pivot-b)*(pivot-b);
	else return (R == 1);
}

ll pd[210][210];
int n, B;

ll solve( int l, int a ){
	if( a == n-1 ) return 0;
	if( pd[l][a] >= -1 ) return pd[l][a];
	ll ans = 0;
	rep( i, a+1, n ){
		if( ccw( v[l], v[a], v[i] ) > 0 ){
			ll c = ( vec( pivot, v[a] )%vec( pivot, v[i] ) );
			ll b = solve( a, i );
			if( cmp( c+b, B ) <= 0 ) ans = max( ans, c+b );
		}
	}
	return pd[l][a] = ans;
}

int main(){
	
	point a;
	while( scanf("%d%d", &n, &B ) != EOF ){
		n++;
		memset( pd, -INF, sizeof pd );
		rep( i, 0, n ){
			v[i].read();
		}
		B <<= 1;
		pivot = v[n++] = v[0];
		sort( v+1, v+n-1, radial_lt );
		
		ll ans = 0;
		rep( i, 1, n-1 ){
			ans = max( ans, solve( 0, i ) );
		}
		
		cout << ans/2.0 << "\n";
	}
	
	return 0;
}

