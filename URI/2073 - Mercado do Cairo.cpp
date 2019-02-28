#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-2
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll bit[1100][1100], n = 1001, m = 1001;

void update( int x , int y , ll val ){
    int y1;
    while( x <= n ){
        y1 = y;
        while( y1 <= m ){
            bit[x][y1] = max( bit[x][y1], val );
            y1 += ( y1 & -y1 ); 
        }
        x += ( x & -x ); 
    }
}

ll query( int x,int y ){
	ll sum = 0;         
	while( x ){
        int y1 = y;
        while( y1 ){
	        sum = max( sum, bit[x][y1] );
	        y1 -= ( y1 & -y1 );
        }
        x -= ( x & -x );
    }
    return sum;
}


int main(){

	int t, n, x, y;
	ll resp;
	
	scanf("%d", &t );
	while( t-- ){
		memset( bit, 0, sizeof bit );
		resp = 0;
		scanf("%d", &n );
		rep( i, 0, n ){
			scanf("%d%d", &x, &y );
			ll a = 0, b = 0;
			a = query( x, y )+1;
			update( x, y, a );			
			resp = max( resp, a );
		}
		printf("%lld\n", resp );		
	}		
	return 0;
}
