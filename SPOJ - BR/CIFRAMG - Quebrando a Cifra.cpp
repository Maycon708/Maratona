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

const int MAX = 1e6+10;

ll dif[MAX];

int main(){
	char alpha[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	while( 1 ){
		int n = readInt();
		if( !n ) break;
		memset( dif, 0, sizeof dif );
		printf("MENSAGEM: [");
		bool aux = 1;
		rep( i, 0, n ){
			int v = readInt();
			if( !v ){
				if( aux ) printf("]");
				aux = 0;
			}
			if( aux ){
				if( v == 18 ){
					ll x = readInt();
					ll y = readInt();
					ll k = readInt();
					if( x < MAX ) dif[x] += k;
					if( y+1 < MAX ) dif[y+1] -= k;
					i += 3;
				}
				if( v == 42 ){
					ll x = readInt();
					ll u = dif[x];
					if( u < 0 ) printf(" ");
					else
						printf("%c", alpha[u%26] );
					i++;
				}
				
			}
		}
		printf("\n");
	}

}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}



