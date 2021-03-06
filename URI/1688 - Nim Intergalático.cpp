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
typedef unsigned long long int ll;

ll readInt();

ll C( ll a ){
	if( a % 4 == 0 ) return a;
	if( a % 4 == 1 ) return 1;
	if( a % 4 == 2 ) return a+1;
	if( a % 4 == 3 ) return 0;
	
}

int main(){
	ll n, q, a, b, k;
	while( cin >> n >> q ){
		while( q-- ){
			a = readInt();
			b = readInt();
			k = readInt();
			ll resp = C( a-1 );
			resp ^= ( C( b+k ) ^ C( a+k-1 ) );
			ll aux = ( C( n ) ^ C( b ) );
			resp ^= aux;
			if( resp ) printf("JABBA\n");
			else printf("HAN\n");
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

