#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

double pd[1100][60];

vector<int> adj[1100];
vector<ii> op[1100];

double solve( int u, int id, int last ){
	if( pd[u][id] > -1 ) return pd[u][id];
	double aux, ans = 0; 
	rep( i, 0, adj[u].size() ){
		aux = INF;
		aux *= aux;
		int v = adj[u][i];
		if( v == last ) continue;
		rep( j, 0, op[v].size() ){
			ii a = op[v][j];
			ii b = op[u][id];
			aux = min( aux, solve( v, j, u ) + hypot( a.F - b.F, a.S - b.S ) );
		}
		ans += aux;
	}
	return pd[u][id] = ans;
}

int main(){
	int n, c, x, y;
	char name[100], n1[100], n2[100];
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		
		map<string,int> mp;
		memset( pd, -INF, sizeof pd );
		
		rep( i, 0, n ){
			adj[i].clear();
			op[i].clear();
			
			scanf("%s%d", name, &c );
			mp[name] = i;
			
			while( c-- ){
				scanf("%d%d", &x, &y );
				op[i].pb( ii( x, y ) );
			}
		}
		rep( i, 1, n ){
			scanf("%s %s", n1, n2 );
			int u = mp[n1], v = mp[n2];
			adj[u].pb(v); adj[v].pb(u);
		}
		
		double ans = INF;
		rep( i, 0, op[0].size() ){
			ans = min( ans, solve( 0, i, -1 ) );
		}
		printf("%.1f\n", ans );
	}
}

