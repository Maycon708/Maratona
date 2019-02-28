#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

const int mod = 1e9+7;
const int N = 112345;

ll bit[N], C[N];
int n;

void update( int x, ll v ){
    while( x <= n ){
        bit[x] = ( bit[x] * v )%mod;
			x = x + ( x & -x );
    }
}
ll query( int x ){
    ll ans = 1;
    while( x > 0 ){
        ans = ( ans * bit[x] )%mod;
        x = x - ( x & -x );
    }
    return ans;
}

ll fastExp( ll b, ll e ){
	ll resp = 1;
	while( e ){
		if( e&1 ) resp = ( resp * b )%mod;
		b = ( b*b )%mod;
		e >>= 1;
	}
	return resp;
}

ii fib( ll x ){
	
	if( !x ) return ii(0, 0); 
	if( x == 1 ) return ii(1, 1);  
	if( x == 2 ) return ii(1, 2);
	    
	ii ret, aux = fib( x/2 );  
	ret.F = ( aux.F * ( aux.S*2 + mod - aux.F ))%mod;  
	ret.S = ( aux.F * aux.F + aux.S * aux.S )%mod;    
	
	if( !(x&1) ) return ret;  
	else return ii( ret.S, ( ret.F + ret.S )%mod ); 
}

int main(){
	
	int  m, a, b;
	ll u, c;
	char s[10];
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		
		rep( i, 0, N ) bit[i] = 1;
		
		rep( i, 1, n+1 ){
			scanf("%lld", &u );
			C[i] = fib( u-1 ).F;
			update( i, C[i] );
		}
			
		while( m-- ){
			scanf("%s", s );
			if( s[0] == '<' ){
				scanf("%d%lld", &a, &c );
				ll aux = fib( c-1 ).F;
				update( a, ( aux * fastExp( C[a], mod-2 ) )%mod );
				C[a] = aux;
			}
			else{
				scanf("%d%d", &a, &b );
				ll bb = query( b );
				ll aa = ( a != 1 ) ? query( a-1 ) : 1;
				aa = fastExp( aa, mod-2 );
				printf("%lld\n", ( aa * bb )%mod );
			}
		}
		printf("%lld\n", query( n ) );
	}
}

