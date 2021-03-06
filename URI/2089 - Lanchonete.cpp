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

int c[10010], v, n;
bool aux[100010];

inline bool solve(){
	vector < int > V;
	rep( i, 0, v+1 ) aux[i] = 0;
	V.pb( 0 ); aux[0] = 1;
	rep( i, 0, n ){
		if( c[i] > v ) continue;
		for( int j = V.size()-1; j >= 0; j-- ){
			int w = V[j] + c[i];
			if( w == v ) return 1;
			if( w > v ) continue;
			if( aux[w] ) continue;
			aux[w] = 1;
			V.pb( w );
		}
	}
	return 0;
}

int main(){

	while( 1 ){
		v = readInt();
		n = readInt();
		if( !n && !v ) break;
		rep( i, 0, n ) c[i] = readInt();
		if( solve() ) puts("sim");
		else puts("nao");
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



