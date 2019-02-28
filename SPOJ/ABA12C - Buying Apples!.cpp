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
	int t, n, m, p[200], ans[200];
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &m, &n );
		for( int i = 1; i <= n; i++ ){
			scanf("%d", &p[i] );
			ans[i] = INF;
		}
		ans[0] = 0;
		for( int i = 1; i <= n; i++ ){
			for( int j = 1; j <= i; j++ ){
				if( p[j] == -1 || ans[i-j-1] == INF ) continue;
				ans[i] = min( ans[i], ans[i-j] + p[j] ); 
			}
		}
		printf("%d\n", ans[n] == INF ? -1 : ans[n] );
	}
}

