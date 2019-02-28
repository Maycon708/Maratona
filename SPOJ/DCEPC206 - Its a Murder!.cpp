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

const int N = 1e6+2;
ll bit[N];

void update(int x, int v){
    while(x <= N){
        bit[x] = bit[x] + v;
        x = x + (x&-x);
    }
}
ll query(int x){
    ll ans = 0;
    while(x > 0){
        ans = ans + bit[x];
        x = x - (x&-x);
    }
    return ans;
}

int main(){

	int t = readInt();
	while( t-- ){
		memset( bit, 0, sizeof bit );
		int n = readInt();
		ll ans = 0;
		rep( i, 0, n ){
			int u = readInt();
			if( !u ) continue;
			ans += query( u-1 );
			update( u, u );
		}
		printf("%lld\n", ans );
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


