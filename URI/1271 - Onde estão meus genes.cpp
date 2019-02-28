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

	int k = 1, g[50050], mp[50050], x[1111], y[1111];
	while( 1 ){
		int n = readInt();
		if( !n ) break;
		rep( i, 1, n+1 ) g[i] = i, mp[i] = i;
		int r = readInt();
		rep( i, 0, r){
			x[i] = readInt();
			y[i] = readInt();
		}
		for( int i = r-1; i>=0; i-- ){
			int ini = x[i];
			int fim = y[i];
			while( ini < fim ){
				swap( g[ini], g[fim] );
				ini++;
				fim--;
			}
		}
		int q = readInt();
		printf("Genome %d\n", k++);
		while( q-- ){
			int x = readInt();
			printf("%d\n", g[x] );
		}
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

