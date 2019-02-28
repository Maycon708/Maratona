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

int main(){

	int a, v, g[110], t = 1;
	while( cin >> a >> v ){
		if( !a && !v ) break;
		rep( i, 0, a+1 ) g[i] = 0;
		int ans = 0;
		rep( i, 0, v ){
			int x, y;
			cin >> x >> y;
			g[x]++, g[y]++;
			ans = max( ans, max( g[x], g[y] ) );
		}
		bool aux = 0;
		printf("Teste %d\n", t++ );
		rep( i, 1, a+1 ){
			if( g[i] == ans ){
				if( aux ) printf(" ");
				aux = 1;
				printf("%d", i );
			}
		}
		printf("\n\n");
	}
	

}
