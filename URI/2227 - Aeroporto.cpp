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


#define gc getchar_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int main(){

	int a, v, g[110], t = 1;
	while( 42 ){
		scan(a), scan(v);
		if( !a && !v ) break;
		for( register int i = a; i > 0; i-- ) g[i] = 0;
		int ans = 0;
		for( register int i = v; i > 0; i-- ){
			int x, y;
			scan(x), scan(y);
			g[x]++, g[y]++;
			ans = max( ans, max( g[x], g[y] ) );
		}
		bool aux = 0;
		printf("Teste %d\n", t++ );
		for( register int i = a; i > 0; i-- ){
			if( g[a-i+1] == ans ){
				printf("%d ", a-i+1 );
			}
		}
		printf("\n\n");
	}
	

}
