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

#define N 505

ll bit[N][N];

void update( int x, int y, int v ){
	for( int i = x; i < N; i += ( i&-i ))
		for( int j = y; j < N; j += (j&-j )) 
			bit[i][j] += v;
}

ll query( int x, int y ){
	ll sum = 0;
	for( int i = x; i > 0; i -= ( i&-i ))
		for( int j = y; j > 0; j -= (j&-j )) 
			sum += bit[i][j];
	return sum;
}

int main(){
	int t, x, y, z, w, v;
	char op;
	while( scanf("%d", &t ) != EOF ){
		memset( bit, 0, sizeof bit );
		while( t-- ){
			scanf(" %c", &op );
			if( op == 'U' ){
				scanf("%d%d%d%d%d", &x, &y, &z, &w, &v );
				update( x, y, v );
				update( z+1, y, -v );
				update( x, w+1, -v );
				update( z+1, w+1, v );
			}
			else{
				scanf("%d%d", &x, &y );
				printf("%lld\n", query( x, y ) );
			}
		}
	}
}
