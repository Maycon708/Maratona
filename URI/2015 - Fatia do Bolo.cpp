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

#define vec(a,b) (b-a)

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const double EPS = 1e-11;

inline int cmp( double x, double y = 0, double tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

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
	
	int cmp(point q) const{
		if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y,q.y);
	}
	bool operator == (point q) const { return cmp(q) == 0; };
	bool operator != (point q) const { return cmp(q) != 0; };
	bool operator < (point q) const { return cmp(q) < 0; };
};
typedef vector<point> polygon;

ll poly_area( polygon& T ) {
	if( T.size() < 3 ) return 0;
	ll s = 0;   
	int n = T.size();
	rep( i, 0, n )	s += T[i]%T[(i + 1)%n];
	return s;
}

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		polygon v(n);
		rep( i, 0, n ) v[i].read();
		ll at = poly_area( v );
		ll ans = -1, area = 0, a, b;
		rep( i, 0, n ) v.pb( v[i] );
		int j = 3;
		point v1 = vec( v[0], v[1] );
		point v2 = vec( v[0], v[2] );
		area = v1%v2;
		ll last = abs( at - 2*area );
		
		for( int i = 0; i < n; i++ ){
			for( ; j < v.size(); j++ ){
				v1 = vec( v[i], v[j-1] );
				v2 = vec( v[i], v[j] );
				area += abs( v1%v2 );
				if( abs( at - 2*area ) > last ) break;
				last = abs( at - 2*area );
			}
			j--; area -= abs( v1%v2 );
			if( abs( at - 2*area ) > ans ){
				ans = abs( at - 2*area );
				a = max( at-area, area );
				b = min( at-area, area );
			}
			v1 = vec( v[i], v[i+1] );
			v2 = vec( v[i], v[j] );
			area -= abs( v1%v2 );
			last = abs( at - 2*area );
			j++;
		}
		
		printf("%lld %lld\n", a, b );
	}	
	return 0;
}

