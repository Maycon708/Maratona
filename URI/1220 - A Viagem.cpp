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


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

int main(){

	int n;
	ll resp, v[10000], V[10000], t, m, ans;
	
//	freopen("out.txt", "w", stdout);
	while( 1 ){
		n = readInt();
		if( !n ) break;
		m = 1;
		rep( i, 0, n ){
			int r = readInt() * 100 + readInt();
			v[i] = V[i] =  r;
			m += r;
		}
//		debug( m )
//		int a = m%10;
		m /= n;
//		debug( a )
//		if( a > 6 ) m++;
//		debug( m )
		resp = ans = 0;
		
		rep( i, 0, n ){
			if( m < v[i] ) ans += abs( m - v[i] );
			if( m > V[i] ) resp += abs( V[i] - m );
		}
		int t1 = ans, t2 = resp;
		rep( i, 0, n ){
			if( m-1 > v[i] ) t1 -= ( m - 1 - v[i] );
			if( m+1 < V[i] ) t2 -= ( V[i] - ( m + 1 ));
		}
		if( t1 < 0 ) ans += abs( t1 );
		if( t2 < 0 ) resp += abs( t2 );
		printf("$%.2f\n", min(ans, resp)/100.0 );
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

