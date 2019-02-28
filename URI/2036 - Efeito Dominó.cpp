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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

int n, H, pd[2010][510][2], v[10100];

int solve( int pos, int h, int c ){
	if( pos == n-2 ){
		int u = v[pos];
		if( c ) u += h;
		if( u <= H ) return c;
		else if( u - h <= H && !c ) return 1;
		else return INF;
	}
	if( pd[pos][h][c] != -1 ) return pd[pos][h][c];
	int ans = INF;
	if( c ){
		int u = v[pos] + h;
		if( u <= H ) ans = min( ans, solve( pos+1, H - u, 0 ) +1 );
		else ans = min( ans, solve( pos+1, u - H, 1 ) +1 );
	}
	else{
		int u = v[pos] - h;
		if( v[pos] <= H ) ans = min( ans, solve( pos+1, H - v[pos], 0 ) );
		else ans = min( ans, solve( pos+1, v[pos] - H, 1 ));
		if( u <= H ) ans = min( ans, solve( pos+1, H - u, 0 ) +1);
		else ans = min( ans, solve( pos+1, u - H, 1 ) +1);
	}
	return pd[pos][h][c] = ans;
}

int main(){

	while( 1 ){
		n = readInt();
		H = readInt();

		if( n == -1 ) break;
		
		memset( pd, -1, sizeof pd );
				
		rep( i, 0, n-1 ){
			v[i] = readInt();
		}
		
		int resp = solve( 0, 0, 0 );
		
		if( resp == INF ) printf("-1\n");
		else
			printf("%d\n", resp );
	}

}

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


