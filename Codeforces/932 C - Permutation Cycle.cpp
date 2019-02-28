#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

bool check( int n, int a, int b, int &aa, int &bb ){
	aa = 0;
	for( int i = 0; i <= n; i += a, aa++ ){
		if( (n-i)%b == 0 ){
			bb = (n-i)/b;
			return 1;
		}
	}
	return 0;
}

int main(){
	
	int n, a, b, aa, bb;
	
	while( scanf("%d%d%d", &n, &a, &b ) != EOF ){
		if( check( n, a, b, aa, bb ) ){
			int id = 1;
			while( aa-- ){
				rep( i, id+1, id+a ){
					printf("%d ", i );
				}
				printf("%d ", id );
				id += a;
			}
			while( bb-- ){
				rep( i, id+1, id+b ){
					printf("%d ", i );
				}
				printf("%d ", id );
				id += b;
			}
			printf("\n");
		}
		else puts("-1");
	}
	
}

