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

int mat[1010][1010];

int mod( int a, int b ){
	while( a < 0 ) a += b;
	return a%b; 
}

int main(){
	int t = 1, n, m;
	while( 42 ){
		int x = 0, y = 0, q, a, b;
		scanf("%d%d", &n, &m );
		if( !n && !m ) break;
		rep( i, 0, n ){
			rep( j, 0, m ){
				scanf("%d", &mat[i][j] );
			}
		}
		while( 42 ){
			scanf("%d%d", &a, &b );
			if( !a && !b ) break;
			x += a, y += b;
		}
		printf("Teste %d\n", t++ );
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( j ) printf(" ");
				a = ( n + ( i + y )%n )%n, b = ( m + ( j - x )%m )%m;
				printf("%d", mat[a][b] );
			}
			printf("\n");
		}
		printf("\n");
	}
	
	
	
}

