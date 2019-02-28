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

	int p, k, n, c[1010], g[1010];
	
	while( scanf("%d%d", &p, &k ) != EOF ){
		int ans = 0;
		
		while(p--){
			scanf("%d", &n );
			g[0] = 0;
			rep( i, 1, n+1 ){
				vector<bool> aux(1000, 0);
				scanf("%d", &c[i] );
				for( int j = i; j >= max( 1, i-k ); j-- ) if( j - c[j] >= 0 ) aux[g[j-c[j]]] = 1;
				for( int j = 0; j < 1000; j++ ) if( !aux[j] ){ g[i] = j; break; } 				
			}
			ans ^= g[n];
		}
		
		if( ans ) puts("Alice can win.");
		else puts("Bob will win.");	
	}
}
