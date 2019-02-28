#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
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

int n, c[700], p[700], pd[700][700];

int solve( int pos, int cap ){
	if( pos == n  || !cap ) return 0;
	if( pd[pos][cap] != -1 ) return pd[pos][cap];
	int ans = 0;
	if( cap >= c[pos] ) ans = max( ans, solve( pos, cap - c[pos] ) + p[pos] );
	ans = max( ans, solve( pos+1, cap ) );
	return pd[pos][cap] = ans;
} 

int main(){
	int k = 1;
	while( 1 ){
		n = readInt();
		int t = readInt();
		if( !n && !t ) break;
		rep( i, 0, n ){
			c[i] = readInt(), p[i] = readInt();
			rep( j, 0, t+1 ) pd[i][j] = -1;
		}
		printf("Instancia %d\n", k++ );
		printf("%d\n\n", solve( 0, t) );
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

