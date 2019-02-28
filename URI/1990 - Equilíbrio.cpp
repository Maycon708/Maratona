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

int main(){
	vector< ll > v;
	while( 1 ){
		v.clear();
		ll n = readInt();
		if( n == -1 ) break;
		ll sum = 0;
		rep( i, 0, n-1 ){
			ll V;
			sum += V = readInt();
			v.pb( V );
		}
		sort( all(v) );
		ll cont = 0;
		int k = ( n-1)/2;
		ll u = v[k], w = v[k-1];
		ll u2 = n * u - sum, w2 = n * w - sum;
		double v2 = double( sum )/double( n-1 );
		if( u2 > u && !binary_search( all(v), u2 ) ) cont++;
		if( w2 < w && !binary_search( all(v), w2 ) ) cont++;
		if( v2 > w && v2 < u && v2 == ll(v2) ) cont++;
		printf("%lld\n", cont );
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

