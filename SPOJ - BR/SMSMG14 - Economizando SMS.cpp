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

int main(){
	char s[10000];
	int G[5000], L[5000];
	while( 1 ){
		int n = readInt();
		int l = readInt();
		int g = readInt();
		if( !n && !l && !g ) break;
		int ll = 0, gg = 0;
		rep( i, 0, n ){
			gets( s );
			if( s[0] == 'L' ){
				G[i] = INF;
				L[i] = strlen( s ) - 7;
			}
			else{
				L[i] = INF;
				G[i] = strlen( s ) - 8;
			}
		}
		rep( i, 1, n ){
			if( G[i] + G[i-1] + 1 <= 160 ){
				gg++;
				G[i] += G[i-1] + 1;
			}
			if( L[i] + L[i-1] + 1 <= 160 ){
				ll++;
				L[i] += L[i-1] + 1;
			}
		}
		printf("%d %d\n", ll * l, gg * g );
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



