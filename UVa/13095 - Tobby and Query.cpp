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

int sum[10][100010];

int main(){
	
	int n, u, q, a, b;
	
	while( scanf("%d", &n ) != EOF ){
		for( int i = 1; i <= n; i++ ){
			for( int j = 0; j < 10; j++ ) sum[j][i] = sum[j][i-1];
			scanf("%d", &u );
			sum[u][i]++;
		}
		scanf("%d", &q );
		while( q-- ){
			scanf("%d%d", &a, &b );
			int ans = 0;
			rep( i, 0, 10 ) if( sum[i][b] != sum[i][a-1] ) ans++;
			printf("%d\n", ans );
		}
	}
	
}

