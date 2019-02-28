#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define EPS 1e-9
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;
typedef long double ld;
/*
struct comp{
    ld re, im;
    comp(){}
    comp( ld re, ld im ): re(re), im(im){}
    ld slen() const{ return re*re + im*im; };
    ld real(){ return re; }
    
	inline comp conj(){ return comp( re, -im ); }
	inline comp operator +  ( const comp& b ){ return comp( re + b.re, im + b.im ); }
	inline comp operator -  ( const comp& b ){ return comp( re - b.re, im - b.im); }
	inline comp operator *  ( const comp& b ){ return comp( re * b.re - im * b.im, re * b.im + im * b.re); }
	inline comp operator /  ( const ld&   b ){ return comp( re / b, im / b); }
	inline comp operator /  ( const comp& b ){ return comp( re * b.re + im * b.im, im * b.re - re * b.im)/b.slen(); }
	inline comp operator /= ( const ld&   b ){ return comp( re /= b, im /= b ); }
};
 */
typedef complex<double> comp;

void fft(vector<comp>& a, bool op ){
    int n = a.size();
	if( n == 1 ) return;
	
    vector<comp> q, r;
    rep( i, 0, n>>1 ){
        q.pb( a[2*i] );
        r.pb( a[2*i+1] );
    }
    
    fft( q, op );
    fft( r, op );
    
	comp w;
	if( op ) w = comp( cos(2*M_PI/n), sin(2*M_PI/n) );
    else w = comp( cos(2*M_PI/n), -sin(2*M_PI/n) );
	
	comp atual = comp( 1, 0 );
    rep( i, 0, n>>1 ){
        a[i] = q[i] + atual * r[i];
        a[i+n/2] = q[i] - atual * r[i];
        atual *= w;
    }
}

int cmp( int a ){
	rep( i, 0, 16 ){
		if( a == 1 << i ) return 1;
	}
	return 0;
}

void C( vector<comp>& v ){
	int n = v.size();
	n = ( n << 1 ) ^1;
	reverse( all(v) );
	while( v.size() < n || !cmp( v.size() ) ) v.pb( comp( 0, 0 ) );
	return;
}

int main(){
	
	int t, n, u;
	scanf("%d", &t );
	
	while( t-- ){
		scanf("%d", &n );
		vector<comp> a, b, c;
		
		rep( i, 0, n+1 ){
			scanf("%d", &u );
			a.pb( comp( u, 0 ) );
		}
		C(a);
		fft( a, 1 );
		
		rep( i, 0, n+1 ){
			scanf("%d", &u );
			b.pb( comp( u, 0 ) );
		}
		C(b);
		fft( b, 1 );
		
		rep( i, 0, a.size() ){
			c.pb( a[i] * b[i] );
		}
		fft( c, 0 );
		for( int i = 2*n; i >= 0; i-- ){
            if( i != 2*n ) printf(" ");
            printf("%.0f", real( c[i] )/c.size() );
        }
        printf("\n");
	}
}

