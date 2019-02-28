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
#define MAXN 100010
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

int n, s[MAXN], pd[2][MAXN], sum, pos;

int solve(){
	memset( pd, -1, sizeof pd );
	pd[0][0] = 0;
	rep( i, 0, n ){
		int pos = i&1, ps = !( i&1 );
		rep( dif, 0, sum ){
			if( pd[pos][dif] != -1 ){
				int u = abs( dif - s[i] );
				int v = dif + s[i];
				pd[ps][u] = max( pd[ps][u], pd[pos][dif] + s[i] );
				pd[ps][v] = max( pd[ps][v], pd[pos][dif] + s[i] );
				pd[ps][dif] = max( pd[ps][dif], pd[pos][dif] );
			}
		}
	}
	return pd[n&1][0];
}

int main(){

	while( 1 ){
		sum = 0;
		n = readInt();
		if( !n ) break;
		rep( i, 0, n )
			sum += s[i] = readInt();
		printf("%d\n", solve()/2 );
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


