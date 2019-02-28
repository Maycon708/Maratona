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

int g[101][101];

int grundy( int n, int m ){
	if( !n || !m ) return 1;
	int V[10000];
	memset( V, 0, sizeof V );
	rep( i, 0, n+1 ){
		rep( j, 0, m+1 ){
			int k = 0;
			int u = i-1, v = j-1;
			if( u >= 0 && v >= 0 ) k ^= g[u][v];
			u = i - 1; v = m - j - 1;
			if( u >= 0 && v >= 0 ) k ^= g[u][v];
			u = n - i - 1; v = m - j - 1;
			if( u >= 0 && v >= 0 ) k ^= g[u][v];
			u = n - i - 1, v = j - 1;
			if( u >= 0 && v >= 0 ) k ^= g[u][v];
			V[k] = 1;
		}
	}
	rep( i, 0, 10000 ){
		if( !V[i] ) return i;
	}
	printf("aumentar o vetor\n");
}

void pre_comp(){
	rep( i, 0, 101 ){
		rep( j, 0, 101 ){
			g[i][j] = grundy( i, j );
		}
	}
}

int main(){

	pre_comp();
	int t = readInt();
	while( t-- ){
		int n = readInt() -1;
		int m = readInt() -1;
		if( g[n][m] ) printf("1\n");
		else printf("2\n");
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

