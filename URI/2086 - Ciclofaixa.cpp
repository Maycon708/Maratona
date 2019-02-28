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

int mat[110][110], n;

void floyd(){
    rep( k, 0, n )
        rep( i, 0, n )
            rep( j, 0, n )
                mat[i][j] = min( mat[i][j], max( mat[i][k], mat[k][j] ) ); 
}

int main(){

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
	while( 1 ){
		n = readInt();
		int m = readInt();
		if( !n && !m ) break;
		memset( mat, INF, sizeof mat );
		while( m-- ){
			int u = readInt()-1;
			int v = readInt()-1;
			int w = readInt();
			mat[u][v] = mat[v][u] = w;
		}
		floyd();
		int q = readInt();
		while( q-- ){
			int u = readInt()-1;
			int v = readInt()-1;
			if( u == v ) printf("0\n");
			else
			printf("%d\n", mat[u][v] );
		}
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



