#include <bits/stdc++.h>
 
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugP(a) cout << "F" << " = " << a.first << " --- " << "S" << " = " << a.second << "\n";
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
 
using namespace std;
 
typedef pair <int, int> ii;
typedef long long int ll;
 
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

const int MAXN = 105, mod = 303700049;

ll mat[MAXN][MAXN];
ll ans[MAXN][MAXN];
ll tmp[MAXN][MAXN];
ll M[MAXN][MAXN][MAXN];
ll N;

const ll modulo( ll a ){
	if( a < mod ) return a;
	if( a == mod ) return 0;
	ll u = a/mod;
	return a - u * mod;
}

void multiply(long long m1[][MAXN], long long m2[][MAXN]) {
	memset( tmp, 0, sizeof(tmp) );
	for( int a = 0; a <= N; ++a ){
    	for( int b = 0; b <= N; ++b ){
    		for( int c = 0; c <= N; ++c ){
    			tmp[a][b] += ( m1[a][c] * m2[c][b] );
    		}
    		tmp[a][b] = ( tmp[a][b] )%mod;
		}
	}
	memcpy( m1, tmp, sizeof tmp );
}    

int main(){
 
    ll a, b, c, d, k, v[110];
    memset( M, 0, sizeof M );
    for( N = 2; N <= 100; N++ ){
    	rep( i, 0, N-1 ){
			M[N][i][i+1] = 1;
		}
		rep( i, 0, N )
			M[N][N-1][i] = M[N][N][i] = N-i;
		M[N][N][N] = 1;

	}
	     
    while( scanf("%lld%lld", &N, &k ) != EOF ){
		memset( ans, 0, sizeof ans );
		memcpy( mat, M[N], sizeof mat );
		
        v[N] = 0;
        rep( i, 0, N ){
            v[i] = readInt()%mod;
        	v[N] = ( v[N] + v[i] )%mod;
        }
        ll p = k-N;
        
        for(int i = 0; i <= N; i++ ){
	        ans[i][i] = 1;
	    }
	    while( p ){
	    	if( p&1 ) multiply( ans, mat );
	    	p >>= 1;
			multiply( mat, mat );
	    }

		ll resp = 0, resp2 = 0;
        rep( i, 0, N+1 ){
            resp = ( resp + ( ans[N-1][i] * v[i] )%mod )%mod;
            resp2 = ( resp2 + ( ans[N][i] * v[i] )%mod )%mod; 
        }
        printf("%lld %lld\n", resp, resp2 );   
    }   
     
    return 0;
}

