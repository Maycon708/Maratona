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

double dist[1010][1010];

inline bool cmp ( double a, double b ){
	return abs( a - b ) < EPS;
}

int main(){
	int x[1010], y[1010];
	while( 1 ){
		int n = readInt();
		if( !n ) break;
		rep( i, 0, n ){
			x[i] = readInt();
			y[i] = readInt();
		}
		rep( i, 0, n ){
			dist[i][i] = 0;
			rep( j, i+1, n ){
				dist[i][j] = dist[j][i] = hypot( x[i] - x[j], y[i] - y[j] );
			}
			sort( dist[i], dist[i] + n);
		}
		int resp = 0, cont = 0;
		rep( i, 0, n ){
			rep( j, 1, n ){
				if( cmp( dist[i][j], dist[i][j-1]) )cont++;
				else{
					resp += ( cont * (cont+1) )/2;
					cont = 0;
				}
			}
		}
		resp += ( cont * cont+1 )/2;
		printf("%d\n", resp);
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

