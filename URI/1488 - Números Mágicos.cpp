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
	
	int n, t = 1;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		int x = 0, m;
		rep( i, 1, n+1 ){
			int num = n * i;
			int dem = 2 * i + i*i + 1;
			if( num % dem ) continue;
			x = num/dem, m = i;
		}
		printf("Instancia %d\n", t++ );
		if( x ){
			printf("%d %d %d %d %d\n", m, x - m, x + m, x / m, x * m );
		}
		else printf("%d nao e quadripartido\n", n );
		printf("\n");
	}
	
}

