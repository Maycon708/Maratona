#include<stdlib.h>
#include<stdio.h>
 
#define INF 0x3F3F3F3F
#define rep(i, a, b) for ( i = (a); i < (b); i++)
#define EPS 1e-9

typedef long long int ll;

struct par{
	ll F, S;
};

typedef struct par ii;
 
ll readInt () {
    int minus = 0;
    ll result = 0; char ch;
  
    ch = getchar();
    while (1) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = 1;
    else result = ch-'0';
    while (1) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

const ll MAXN = 10, mod = 1000000007;

void multiply( ll m1[][MAXN], ll m2[][MAXN], int N ) {
	ll tmp[MAXN][MAXN];
	int a, b, c, i, j;
	rep( i, 0, N )
		rep( j, 0, N)
			tmp[i][j] = 0;
	for( a = 0; a < N; ++a ){
    	for( b = 0; b < N; ++b ){
    		for( c = 0; c < N; ++c ){
    			tmp[a][b] += ( m1[a][c] * m2[c][b] )%mod;
    		}
    		tmp[a][b] = ( tmp[a][b] )%mod;
		}
	}
	rep( i, 0, N )
		rep( j, 0, N )
			m1[i][j] = tmp[i][j];
}    

ii fib( ll a ){
	ll mat[MAXN][MAXN];
	ll ans[MAXN][MAXN];
	mat[1][1] = 0;
	mat[1][0] = mat[0][0] = mat[0][1] = 1;
	ans[0][0] = 1, ans[1][1] = 1, ans[0][1] = 0, ans[1][0] = 0;
	while( a ){
    	if( a&1 ) multiply( ans, mat, 2 );
    	a >>= 1;
		multiply( mat, mat, 2 );
    }
    ii k;
    k.F = ans[0][1], k.S = ans[1][1];
    return k;
}

int main(){
	int i, j;
	ll mat[MAXN][MAXN];
	ll ans[MAXN][MAXN];
        
    while( 1 ){
    	
    	ll a = readInt(); ll b = readInt(); ll n = readInt();
    	
		if( !a && !b && !n ) break;
		
		ii fa = fib( a );
		ii fb = fib( b );
		ll p = n-1;

		rep( i, 0, MAXN )
			rep( j, 0, MAXN )
				mat[i][j] = 0, ans[i][j] = 0;
		
		rep( i, 0, 4 ){
			mat[3][i] = 1, mat[4][i] = 1;
		}
		
		mat[4][4] = mat[1][3] = mat[1][2] = mat[0][3] = mat[2][1] = mat[2][3]= 1;
		
		rep( i, 0, 5 )
			ans[i][i] = 1;
		
		while( p ){
	    	if( p&1 ) multiply( ans, mat, 5 );
	    	p >>= 1;
			multiply( mat, mat, 5 );
	    }
	    
		ll resp = 0;
		resp =	( ans[4][0] * ( ( fa.S * fb.S )%mod ) )%mod  +
				( ans[4][1] * ( ( fa.F * fb.S )%mod ) )%mod  +
				( ans[4][2] * ( ( fa.S * fb.F )%mod ) )%mod  +
				( ans[4][3] * ( ( fa.F * fb.F )%mod ) )%mod  +
				( ans[4][4] * ( ( fa.F * fb.F )%mod ) )%mod;
		resp %= mod;
		printf("%lld\n", resp );    
	}   
     
    return 0;
}
