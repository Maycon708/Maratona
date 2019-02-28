#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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

int main(){
	
	int n, t = 1, x1, x2, y1, y2, a, b, c, d;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		x1 = y2 = -INF, x2 = y1 = INF;
		rep( i, 0, n ){
			scanf("%d%d%d%d", &a, &b, &c, &d );
			x1 = max( x1, a ); y1 = min( y1, b );
			x2 = min( x2, c ); y2 = max( y2, d );
		}
		printf("Teste %d\n", t++ );
		if( x1 > x2 || y2 > y1 ) printf("nenhum\n");
		else printf("%d %d %d %d\n", x1, y1, x2, y2 );
		printf("\n");
	}
}

