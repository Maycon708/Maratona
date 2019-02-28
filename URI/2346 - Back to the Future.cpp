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

const int N = 100010;

int g[N];

void D( set<ii> st ){
	set<ii> :: iterator it;
	cout << "------\n"; 
	for( it = st.begin(); it != st.end(); it++ ){
		int u = it -> S;
		debug2( u, g[u] )
	}
}

int main(){
	int n, m, a, b, u, v;
	while( scanf("%d%d%d%d", &n, &m, &a, &b ) != EOF ){
		set<ii> st;
		set<ii> :: iterator it;
		vector<int> adj[N];
		memset( g, 0, sizeof g );
		while( m-- ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
			g[u]++, g[v]++;
		}
		rep( i, 1, n+1 ){
			st.insert( ii( g[i], i ) );
		}
		while( 42 ){
			if( st.empty() ) break;
			u = (st.begin()) -> S;
			v = (--st.end() ) -> S;
			if( g[u] < a ){
				rep( i, 0, adj[u].size() ){
					int w = adj[u][i];
					it =  st.find( ii( g[w], w ) );
					if( it == st.end() ) continue;
					st.erase(it);
					g[w]--;
					st.insert( ii( g[w], w ) );
				}
				st.erase( st.find( ii( g[u], u ) ) );
			}
			else if( st.size() - g[v] - 1 < b ){
				rep( i, 0, adj[v].size() ){
					int w = adj[v][i];
					it =  st.find( ii( g[w], w ) );
					if( it == st.end() ) continue;
					st.erase(it);
					g[w]--;
					st.insert( ii( g[w], w ) );
				}
				st.erase( st.find( ii( g[v], v ) ) );
			}
			else break;
		}
		cout << st.size() << "\n";
	}
}

