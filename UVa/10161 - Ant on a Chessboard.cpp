#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	int n;
	while( scanf("%d", &n ) != EOF && n){
		int aux = sqrt(n);
		int x = aux, y = 1;
		int c = aux*aux;
		int d = ((aux+1)*(aux+1) - (aux*aux) -1 )/2;
		x += min( 1, n - c );
		c += min( 1, n - c );
		y += min( d, n - c );
		c += min( d, n - c );
		x -= min( d, n - c );
		c += min( d, n - c );
		if( aux&1 ) swap( x, y );
		printf("%d %d\n", x, y );
	}
}

