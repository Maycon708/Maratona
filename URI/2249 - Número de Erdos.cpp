#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define INF 0x3f3f3f3f
#define pb push_back

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int N = 1100;

int dist[N];
vector<int> adj[N];

int bfs( int u ){
	queue<ii> q;
	q.push( ii( u, 0 ) );
	while( !q.empty() ){
		u = q.front().F;
		int c = q.front().S;
		q.pop();
		if( dist[u] != INF ) continue;
		dist[u] = c;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			q.push( ii( v, c+1 ) );
		} 
	}
}

int main(){
	int n, t = 1;
	string s, a, b;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		map< pair<string, string>, int > mp;
		map< pair<string, string>, int > :: iterator it;
		rep( i, 0, N ) dist[i] = INF, adj[i].clear();
		int k = 0;
		getline( cin, s );
		rep( i, 0, n ){
			getline( cin, s );
			stringstream ss;
			ss << s;
			vector<int> v;
			while( ss >> a >> b ){
				b[b.size()-1] = ':';
				if( !mp.count(mk(b,a)) ) mp[mk(b,a)] = k++;
				v.pb( mp[mk(b,a)] );
			}
			rep( i, 0, v.size() ){
				rep( j, i+1, v.size() ){
					adj[v[i]].pb(v[j]);
					adj[v[j]].pb(v[i]);
				}
			}
		}
		if( mp.count(mk( "Erdos:", "P." )) )bfs( mp[mk( "Erdos:", "P." )] );
		printf("Teste %d\n", t++ );
		for( it = mp.begin(); it != mp.end(); it++ ){
			if( it -> F.F == "Erdos:" && it -> F.S == "P." ) continue;
			int a = dist[ it -> S ];
			printf("%s %s ", it -> F.S.c_str(), it -> F.F.c_str() );
			if( a != INF ) printf("%d\n", a );
			else printf("infinito\n");
		}
		printf("\n");
	}
}

