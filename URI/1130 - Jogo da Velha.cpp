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

int g[10001];

void grundy(){
	g[0] = 0;
	int T[10001];
	rep( i, 1, 10001 ){
		rep( j, 0, i+1 ) T[j] = 0;
		rep( j, 0, (i+1)/2 ){
			int a = j-2;
			int b = i-( j+3 );
			if( a < 0 ) a = 0;
			if( b < 0 ) b = 0;
			T[ g[b] ^ g[a] ] = 1;
		}
		int I = 0;
		rep( j, 0, i+1 ){
			if( !T[j] ){
				g[i] = j;
				break;
			}
		}
	}
}

int main(){
	int v[10100];
	grundy();
	int n;
	char s[10100];
	while( 1 ){
		n = readInt();
		if( !n ) break;
		rep( i, 0, n ) v[i] = 0, s[i] = getchar();
		bool aux = 0;
		rep( i, 0, n-2 ){
			if( s[i] == 'X' ){
				if( s[i+1] == 'X' || s[i+2] == 'X' ) aux = 1;
				v[i] = 1;
				v[i+1] = 1;
				v[i+2] = 1;
			}
		}
		for( int i = n-1; i >= 2; i-- ){
			if( s[i] == 'X' ){
				if( s[i-1] == 'X' ||s[i-2] == 'X' ) aux = 1;
				v[i] = 1;
				v[i-1] = 1;
				v[i-2] = 1;
			}
		}
		rep( i, 0, n-1 ){
			if( s[i] == 'X' ){
				if( s[i+1] == 'X' ) aux = 1;
				v[i] = 1;
				v[i+1] = 1;
			}
		}
		for( int i = n-1; i >= 1; i-- ){
			if( s[i] == 'X' ){
				if( s[i-1] == 'X' ) aux = 1;
				v[i] = 1;
				v[i-1] = 1;
			}
		}
		if( aux ){
			printf("S\n");
			continue;
		}
		v[n] = 1;
		int resp = 0, cont = 0;
		rep( i, 0, n+1 ){
			if( !v[i]  ) cont++;
			else{
				resp ^= g[cont];
				cont = 0;
			}
		}
		if( resp )
			printf("S\n");
		else 
			printf("N\n");
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

