#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;

#define EPS 1e-3

inline int cmp(ld a, ld b = 0.0, ld tol=EPS) { return a+tol < b ? -1 : a-tol > b ? 1 : 0; }

bool check;

ld C( ld a, ld b ){
	return sqrt(a*a + b*b - 2*a*b );
}


ld C2( ld a, ld b ){
	return sqrt(a*a + b*b + 2*a*b );
}

ld angle( ld a, ld b, ld l ){
	// l² = a² + b² - 2*a*b*cos(ab)   cos(ab) = (-l² + a² + b² )/(2*a*b)
	ld aa = ( l*l - a*a - b*b )/(-2*a*b);
	if( cmp( aa, -1 ) == -1 || cmp( aa, 1 ) == 1 ){ check = 0; return 0; }
	aa = 180/M_PI * acos( aa );
	return aa;
}

int main(){
	ld a, b, c;
	while( scanf("%LF%LF%LF", &a, &b, &c ) != EOF ){
		ld i = max( C(a,b), max( C(a,c), C(b,c) ) ), j = min( C2(a,b), min( C2(a,c), C2(b,c) ) ), l;
		check = 1;
		rep( k, 0, 200 ){
			l = ( i + j )/2;
			ld sum = angle( a, b, l ) + angle( a, c, l ) + angle( b, c, l );
			if( !check ) break;
			if( sum > 360 ) j = l;
			else i = l;
		}
		ld sum = angle( a, b, l ) + angle( a, c, l ) + angle( b, c, l );
		ld ans =  l * l * sqrt(3)/4;
		if( !check || cmp(sum,360) ) ans = -1;
		printf("%.3LF\n", ans );
	}
}
