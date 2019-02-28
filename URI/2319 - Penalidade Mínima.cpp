#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i <= int(b); i++)
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

int C( int n, int k ){
	int cnt = 0;
	for( ; n%k == 0; n /= k ) cnt++;
	return cnt;
}

int ans[2][1010][1010];

void D( int n ){
	
	rep( i, 1, n ){
		rep( j, 1, n ){
			printf("%2d%s", ans[0][i][j] >= INF ? -1 : ans[0][i][j], j == n ? "\n" : " " );
		}
	}
	
	printf("\n\n\n");
	
	rep( i, 1, n ){
		rep( j, 1, n ){
			printf("%2d%s", ans[1][i][j] >= INF ? -1 : ans[1][i][j], j == n ? "\n": " ");
		}
	}
	
}

int main(){
	int n, u;
	while( scanf("%d", &n ) != EOF ){
		memset( ans, INF, sizeof ans );
		ans[0][0][1] = ans[0][1][0] = ans[1][0][1] = ans[1][1][0] = 0;

		rep( i, 1, n ){
			rep( j, 1, n ){
				scanf("%d", &u );
				if( !u ) ans[0][i][j] = ans[1][i][j] = INF;
				else{
					ans[0][i][j] = min( ans[0][i-1][j], ans[0][i][j-1] ) + C( u, 2 );
					ans[1][i][j] = min( ans[1][i-1][j], ans[1][i][j-1] ) + C( u, 5 );
				}
			}
		}
		printf("%d\n", min( ans[0][n][n], ans[1][n][n] )); 
		break;
	}
}

