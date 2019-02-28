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
	while( scanf("%d%d", &n, &c ) != EOF ){
		if( !n && !c ) break;
		rep( i, 0, c ){
			scanf("%d", &k );
			rep( j, 0, k ){
				scanf("%d", &u );
				city[u].pb(j);
			}
		}
		rep( i, 0, n ){
			if( city[i].size() == 1 ) g[ city[i] ]++;
			else{
				int u = city[0], v = city[1];
				adj[u].pb(v);
				adj[v].pb(u);
				g[u]++, g[v]++;
			}
		}
		int cnt = 0;
		rep( i, 0, c ) if( g[i]&1 ) cnt++;
		if( cnt > 2 || !conexo() ) puts("-1"), continue;
	}
}

