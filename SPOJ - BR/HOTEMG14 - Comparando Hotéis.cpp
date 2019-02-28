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

struct H{
	char nome[1000];
	int d, p, e;
};

inline bool cmp( H a, H b ){
	return a.d >= b.d && a.e <= b.e && a.p >= b.p && ( a.d != b.d || a.e != b.e || a.p != b.p );
}

int main(){
	H v[1010];
	vector < H > resp;
	while( 1 ){
		resp.clear();
		int n = readInt();
		if( !n ) break;
		rep( i, 0, n ){
			scanf("%s %d %d %d", v[i].nome, &v[i].d, &v[i].p, &v[i].e );
		}
		rep( i, 0, n ){
			bool aux = 1;
			rep( j, 0, n ){
				if( i != j && cmp( v[i], v[j] ) ) aux = 0;
			}
			if( aux ) resp.pb( v[i] );
		}
		rep( i, 0, resp.size() ){
			printf("%s\n", resp[i].nome );
		}
		printf("*\n");
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



