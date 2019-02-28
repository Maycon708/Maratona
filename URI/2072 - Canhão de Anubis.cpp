#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef pair <int, int> ii;

inline int cmp( double a, double b = 0.0, double tol = EPS ){ return a+tol < b ? -1 : a-tol > b ? 1 : 0; }

struct ponto{
	double x, y, z;
	ponto( double x = 0, double y = 0, double z = 0 ) : x(x), y(y), z(z) {}
	ponto operator + ( ponto  q ){ return ponto( x+q.x, y+q.y, z+q.z ); }
	ponto operator - ( ponto  q ){ return ponto( x-q.x, y-q.y, z-q.z ); }
	ponto operator * ( double d ){ return ponto( x*d, y*d, z*d ); }
	ponto operator / ( double d ){ return ponto( x/d, y/d, z/d ); }
	bool operator == ( ponto a ) const{
		return a.x == x && a.y == y && a.z == z;
	}
};

typedef ponto vec;

double dot( vec A, vec B ){
	return A.x*B.x + A.y*B.y + A.z*B.z;
}

ponto cross( vec A, vec B ){
	return ponto( A.y*B.z - A.z*B.y , A.z*B.x - A.x*B.z , A.x*B.y - A.y*B.x );
}

double norma( vec A ){
	return sqrt( dot( A, A ));
}

ponto projecao( ponto A, ponto B ){ return B * dot(A,B) / dot(B,B); }

inline bool C( ponto a, ponto b, ponto c, ponto d ){
	ponto A = cross( b - c, d - c );
	ponto B = a - c;
	double Aa = dot( A, B );
	if( !cmp( Aa ) ) return 1;
	return 0;
}

inline bool NC( ponto a, ponto b, ponto c ){
	ponto f = ( cross( a - b, c - b ) );
	return !cmp(f.x) && !cmp(f.y) && !cmp(f.z);
}

inline bool D( int a, int b, int c, int d ){
	return a == b || a == c || a == d;
}

int main(){
	int n, t;
	double x, y, z;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		vector < ponto > v;
		rep( i, 0, n ){
			scanf("%lf%lf%lf", &x, &y, &z );
			v.pb( ponto( x, y, z ) );
		}
		bool aux = 1;
		int resp = 0;
		rep( i, 0, n ){
			rep( j, i+1, n ){
				rep( k, j+1, n ){
					if( NC( v[i], v[j], v[k] ) )  continue;
					aux = 0;
					int cnt = 3;
					rep( l, 0, n ){
						if( D( l, k, j, i ) ) continue;
						if( C( v[l], v[i], v[j], v[k] ) ) cnt++;
						else if( v[i] == v[l] || v[j] == v[l] || v[k] == v[l] ) cnt++;
					}
					resp = max( resp, cnt );
					if( resp == n ) break;
				}
				if( resp == n ) break;
			}
			if( resp == n ) break;
		}
		if( aux ) resp = n;
		printf("%d\n", resp );
	}
}
