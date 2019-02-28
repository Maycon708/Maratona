#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int MAXN = 200, MAXM = 1000000;

int last_edge[MAXN], cur_edge[MAXN], dist[MAXN];
int prev_edge[MAXM], cap[MAXM], flow[MAXM], adj[MAXM];
int up[MAXN], val[MAXN];
bool cut[MAXN];
int nedges;
int ans[MAXN][MAXN];
int n;

void d_init(){
	nedges = 0;
	memset(last_edge, -1, sizeof last_edge);
}

void d_edge( int v, int w, int capacity, bool r = false ){
	prev_edge[nedges] = last_edge[v];
	cap[nedges] = capacity;
	adj[nedges] = w;
	flow[nedges] = 0;
	last_edge[v] = nedges++;
	if(!r) d_edge(w, v, 0, true);
}

bool d_auxflow( int source, int sink ){
	queue<int> q;
	q.push(source);
	memcpy(cur_edge, last_edge, sizeof last_edge);
	memset(dist, -1, sizeof dist);
	dist[source] = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for( int i = last_edge[v]; i != -1; i = prev_edge[i] ){
			if( cap[i] - flow[i] == 0 )
				continue;
			if( dist[adj[i]] == -1 ){
				dist[adj[i]] = dist[v] + 1;
				q.push(adj[i]);
				if( adj[i] == sink )
					return true;
			}
		}
	}
	return false;
}

int d_augmenting( int v, int sink, int c ){
	if( v == sink )
		return c;
	for( int& i = cur_edge[v]; i != -1; i = prev_edge[i] ){
		if( cap[i] - flow[i] == 0 || dist[adj[i]] != dist[v] + 1 )
			continue;
		int val;
		if( val = d_augmenting( adj[i], sink, min( c, cap[i] - flow[i] ))){
			flow[i] += val;
			flow[i^1] -= val;
			return val;
		}
	}
	return 0;
}

int dinic( int source, int sink ){
	int ret = 0;
	while( d_auxflow(source, sink)){
		int flow;
		while( flow = d_augmenting(source, sink, 0x3f3f3f3f))
			ret += flow;
	}
	return ret;
}

int mincut( int s, int t ){
	memset(flow, 0, sizeof flow);
	memset(cut, 0, sizeof cut);
	int ret = dinic(s, t);
	queue<int> q;
	q.push(s);
	cut[s] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for( int i = last_edge[v]; i != -1; i = prev_edge[i] ){
			int w = adj[i];
			if( cap[i] - flow[i] && !cut[w] )
				cut[w] = true, q.push(w);
		}
	}
	return ret;
}

int gomory_hu(){
	int resp = INF;
	memset(up, 0, sizeof up);
	memset(ans, INF, sizeof ans);
	for( int i = 1; i < n; ++i ){
		val[i] = mincut(i, up[i]);
		for( int j = i+1; j < n; ++j )
			if( cut[j] && up[j] == up[i])
				up[j] = i;
		ans[i][up[i]] = ans[up[i]][i] = val[i];
		for( int j = 0; j < i; ++j ){
			ans[i][j] = ans[j][i] = min(val[i], ans[up[i]][j]);
			resp = min( resp, ans[i][j] );
		}
	}
	return resp;
}

int main(){
	
	int t, m, u, v, c;
	scanf("%d", &t );
	rep( test, 0, t ){
		scanf("%d%d", &n, &m );
		d_init();
		map < ii, int > mp;
		map < ii, int > :: iterator it;
		rep( i, 0, m ){ 	
			scanf("%d%d%d", &u, &v, &c );
			u--, v--;
			mp[ ii( u, v ) ] = mp[ ii( v, u ) ] = c;
		}
		for( it = mp.begin(); it != mp.end(); it++ ){
			ii a = it -> F;
			d_edge( a.F, a.S, it -> S );
		}
		printf("%d\n", gomory_hu() );
	}
}
