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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

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

inline bool C( ponto a, ponto b, ponto c, ponto d, ponto e ){
	ponto A = cross( b - c, d - c );
	ponto B = a - c;
	ponto C = e - c;
	double Aa = dot( A, B );
	double Bb = dot( A, C );
	
	if( cmp( Aa ) && Aa*Bb < 0 ) return 1;
	return 0;
}

int main(){
	ponto v[10], a;
	double dist[10], x, y, z;
	while( cin >> x >> y >> z ){
		v[0] = ponto( x, y, z );
		rep( i, 1, 4 ){
			cin >> x >> y >> z;
			v[i] = ponto( x, y, z );
		}
		cin >> x >> y >> z;
 		a = ponto( x, y, z );
 		if( C( a, v[3], v[1], v[2], v[0] )) printf("S");
		else printf("N");
		if( C( a, v[2], v[3], v[0], v[1] )) printf("S");
		else printf("N");
		if( C( a, v[0], v[1], v[3], v[2] )) printf("S");
		else printf("N");
		if( C( a, v[0], v[1], v[2], v[3] )) printf("S");
		else printf("N");
		
		printf("\n");
	}
}
