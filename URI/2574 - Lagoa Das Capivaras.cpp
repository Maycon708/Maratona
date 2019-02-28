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

#define N 3000

int n, c, sum[N][N];

int main(){

	while( scanf("%d%d", &n, &c ) != EOF ){
		rep( i, 1, n+1 ){
			rep( j, 1, n+1 ){
				scanf("%d", &sum[i][j] );
				sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
			}
		}
		for( int k = 1; k <= n; k <<= 1 ){
			bool aux = 1;
			for( int i = 1; i <= n; i += k ){
				for( int j = 1; j <= n; j += k ){
					if( sum[i+k-1][j+k-1] - sum[i-1][j+k-1] - sum[i+k-1][j-1] + sum[i-1][j-1] < c ) aux = 0;
				}
			}
			if( aux ){
				printf("%d\n", (n*n)/(k*k) );
				break;
			}
		}		
	}	
}
