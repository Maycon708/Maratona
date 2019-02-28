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

int n;
vector < int > v[10010];

int C ( int a ){
	int total = 0;
	rep( i, 0, n ){
		int pos = upper_bound( all( v[i] ), a ) - v[i].begin();
		total += abs( 2 * pos - (int)v[i].size() );
	}
	return total;
}

int main(){

	while( 1 ){
		n = readInt();
		if( !n ) break;
		int maior = 0;
		rep( i, 0, n ){
			v[i].clear();
			int k = readInt();
			rep( j, 0, k ){
				int nota = readInt();
				v[i].pb( nota );
				if( nota > maior ) maior = nota;
			}
			sort( all(v[i]) );
		}
		int ans = INF;
		rep( i, 0, maior+1 ){
			ans = min( ans, C(i) );
		}
		printf("%d\n", ans );
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


