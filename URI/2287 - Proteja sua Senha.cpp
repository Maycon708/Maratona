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

inline int C( int a ){
	rep( i, 0, 10 ) if( a & (1<<i) ) return i;
}

int main(){
	int t = 1, n, x, y, mask[10];
	char u;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		vector<int> v( 10, ( 1 << 10 ) -1 );
		rep( i, 0, n ){
			rep( j, 0, 5 ){
				scanf("%d%d", &x, &y );
				mask[j] = ( 1 << x ) | ( 1 << y ); 
			}
			rep( i, 0, 6 ){
				scanf(" %c", &u );
				v[i] &= ( mask[u-'A'] );
			}
		}
		printf("Teste %d\n", t++ );
		rep( i, 0, 6 ){
			printf("%d ", C(v[i]) );
		}
		printf("\n\n");
	}
}

