#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

int main(){
	int p[1010], c[1010];
	while( 1 ){
		int n = readInt();
		if( !n ) break;
		rep( i, 0, n ){
			p[i] = readInt();
		}
		rep( i, 0, n ){
			c[i] = readInt();
		}
		int cont, j, resp = -1, resp2 = -1;
		rep( i, 0, n ){
			cont = p[i] - c[i], j = (i+1)%n;
			while( 1 ){
				if( cont < 0 ){
					if( j > i ) i = j-1;
					break;
				}
				if( j == i ){
					resp = i+1;
					break;
				}
				cont += p[j] - c[j];
				j = ( j+1 )%n;
			}
			if( resp != -1 ) break;
		}
		for( int i = n-1; i >= 0; i-- ){
			if( i )
				cont = p[i] - c[i-1], j = i-1;
			else
				cont = p[i] - c[n-1], j = n-1;
			while( 1 ){
				if( cont < 0 ){
					if( j < i ) i = j + 1;
					break;
				}
				if( j == i ){
					resp2 = i+1;
					break;
				}
				int jj = ( j - 1 + n )%n;
				cont += p[j] - c[jj];
				j = jj;
			}
		}
		printf("%d %d\n", resp, resp2 );
	}
}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}
