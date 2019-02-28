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

int C( char s ){
	if( s == '<' ) return 0;
	if( s == '>' ) return 1;
	if( s == 'A' ) return 2;
	if( s == 'V' ) return 3;
}

int n, vis[505*505], ans;
vector<int> adj[505*505];

void dfs( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	ans--;
	rep( i, 0, adj[u].size() ) dfs( adj[u][i] );
}

bool fora( int x, int y ){
	return x < 0 || y < 0 || x >= n || y >= n;
}

int main(){
	char mat[505][505];
	int aux[505][505];
	int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 };
	while( cin >> n ){
		int cnt = 0;
		rep( i, 0, n ){
			rep( j, 0, n ){
				adj[cnt].clear();
				vis[cnt] = 0;
				aux[i][j] = cnt++;
				cin >> mat[i][j];
			}
		}
		stack<int> st;
		rep( i, 0, n ){
			rep( j, 0, n ){
				int u = C( mat[i][j] );
				int x = i + dx[u], y = j + dy[u];
				if( fora( x, y ) ) st.push( aux[i][j] );
				else{
					adj[ aux[x][y] ].pb( aux[i][j] );
				}
			}
		}
		ans = n * n;
		while( !st.empty() ){
			dfs( st.top() );
			st.pop();
		}
		printf("%d\n", ans );
	}
}

