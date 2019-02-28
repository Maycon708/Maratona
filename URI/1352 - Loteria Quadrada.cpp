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

int sqr[111], resp[111];

void pre_comp(){
	rep( i, 2, 101 ){
		sqr[i] = 0;
		rep( j, 2, i+1 ){
			int u = i - j + 1;
			sqr[i] += u * u;
			rep( k, 2, i+1 ){
				int s = k + j - 1;
				if( s <= i ){
					int v = ( i - s + 1 );
					sqr[i] += v*v;
				}
			}
		}
		int u = i * i + 1;
		ll result = 1;
		rep( j, u - 4, u )
			result *= j;
		resp[i] = result/( 24 * sqr[i] );
		printf("resp[%d] = %d; ", i, resp[i] );
	}
	printf("\n");
}

int main(){
	
	freopen("out.txt", "w", stdout );
	int n;
	double p;
	pre_comp();
//	while( scanf("%d%lf", &n, &p ) && n ){
//		printf("%.2f\n", resp[n] * p/100 );
//	}

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


