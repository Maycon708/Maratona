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
	int t, n, k, u[1<<16];
	scanf("%d", &t );
	while( t-- ){
		vector<ii> aux[16];
		vector<int> v[1<<16];
		scanf("%d%d", &n, &k );
		rep( i, 0, 1 << n ){
			scanf("%d", &u[i] );
			aux[0].pb( ii( i+1, u[i] ) );
		}
		rep( i, 0, n ){
			rep( j, 0, aux[i].size() ){
				if( j&1 ) continue;
				if( aux[i][j].S >= aux[i][j+1].S ){
					aux[i][j].S = min( aux[i][j].S + ( k - aux[i][j+1].S ), u[ aux[i][j].F-1 ] );
					aux[i+1].pb( aux[i][j] );
					v[ aux[i][j].F ].pb( aux[i][j+1].F );
				}
				else{
					aux[i][j+1].S = min( aux[i][j+1].S + ( k - aux[i][j].S ), u[ aux[i][j+1].F-1 ] );
					aux[i+1].pb( aux[i][j+1] );
					v[ aux[i][j+1].F ].pb( aux[i][j].F );
				}
			}
		}
		int w = aux[n][0].F;
		printf("%d\n", w );
		rep( i, 0, v[w].size() ){
			if( i ) printf(" ");
			printf("%d", v[w][i] );
		}
		printf("\n");
	}

}

