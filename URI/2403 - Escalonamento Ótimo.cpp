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

#define N 50005

int g[N], n;
vector<int> adj[N];

void topSort(){
	priority_queue<int> q;
	rep( i, 0, n ){
		if( !g[i] ) q.push(-i);
	}
	int cnt = 0;
	vector<int> ans;
	while( !q.empty() ){
		int u = -q.top();
		q.pop();
		ans.pb(u);
		cnt++;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			g[v]--;
			if( !g[v] ) q.push( -v );
		}
	}
	if( cnt != n ) printf("*\n");
	else{
		rep( i, 0, ans.size() ) printf("%d\n", ans[i] );
	}
}

int main(){
	int m, u, v;
	while( cin >> n >> m ){
		rep( i, 0, n ) adj[i].clear(), g[i] = 0;
		while( m-- ){
			cin >> u >> v;
			adj[u].pb(v);
			g[v]++;
		}
		topSort();
	}
}

