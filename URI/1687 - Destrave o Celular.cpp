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
 
int readInt () {
    bool minus = false;
    int result = 0; char ch;
  
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

const int MAXN = 15, mod = 1300031;

ll mat[MAXN*MAXN][MAXN*MAXN];
ll ans[MAXN*MAXN][MAXN*MAXN];
ll tmp[MAXN*MAXN][MAXN*MAXN];

int N;

void multiply(long long m1[][MAXN*MAXN], long long m2[][MAXN*MAXN]) {
	memset(tmp,0,sizeof(tmp));
	for( int a = 0; a < N*N; ++a) {
    	for(int b = 0; b < N*N; ++b) {
    		for (int c = 0; c < N*N; ++c) {
    			tmp[a][b] += m1[a][c]*m2[c][b];
    		}
    		tmp[a][b] %= mod;
		}
	}
	memcpy( m1, tmp, sizeof tmp );
}    


  
int main(){
    int n, m;
    while( scanf("%d%d", &n, &m) != EOF ){
		if( !n && !m ) break;
		N = n;
		int p = m-1;
		memset( mat, 0, sizeof mat );
    	memset( ans, 0, sizeof ans );
    
		rep( i, 0, n ){
        	rep( j, 0, n ){
        		rep( k, 0, n ){
        			rep( l, 0, n ){
						int u = n*i+j, v = n*k+l, w = abs( k-i ), x = abs( l-j );
						if( __gcd( w, x ) == 1 ){
							mat[u][v] = 1;
						}
					}
        		}
        	}
        }
		for(int i = 0; i < n*n; i++ ){
	        ans[i][i] = 1;
	    }
	    while (p) {
	    	if(p&1) multiply(ans,mat);
	    	p >>= 1;
			multiply(mat,mat);
	    }
		ll sum = 0;
		rep( i, 0, n*n ){
			rep( j, 0, n*n ){
				sum =  sum + ans[i][j];
			}
		}
		printf("%lld\n", sum%mod );
    }   
     
    return 0;
}
