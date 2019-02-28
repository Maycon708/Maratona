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

double pd[20][1<<18], dist[20][20];
int n;

double solve( int pos, int mask ){
	if( mask == ( 1 << n ) - 1 ) return dist[pos][0];
	if( pd[pos][mask] > -10 ) return pd[pos][mask];
	double ans = INF;
	rep( i, 1, n ){
		if( mask & ( 1 << i ) ) continue;
		ans = min( ans, solve( i, mask | ( 1 << i ) ) + dist[pos][i] );
	}
	return pd[pos][mask] = ans;
}

int main(){

	while( 1 ){
		n = readInt();
		if( !n ) break;
		n++;
		int x[20], y[20];
		rep( i, 0, n ) x[i] = readInt(), y[i] = readInt();
		rep( i, 0, n ){
			rep( j, i, n ){
				dist[i][j] = dist[j][i] = hypot( x[i] - x[j], y[i] - y[j] );
			}
		}
		memset( pd, -INF, sizeof pd );
		printf("%.2f\n", solve( 0, 1 ) );
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



