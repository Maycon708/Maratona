#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

struct use{
    ll from, to, cost, cap, flow;
    use() {};
    use(int _from, int _to, int _cost, int _cap, int _flow){
        from = _from;
        to = _to;
        cost = _cost;
        cap = _cap;
        flow = _flow;
    }
};

int source, sink;
ll tempo;
vector <int> adj[3000];
vector <use> edg;

void add_edge(int u, int v, int c, int f){
    adj[u].pb(edg.size());
    edg.pb(use(u, v, c, f, 0));
    adj[v].pb(edg.size());
    edg.pb(use(v, u, c, 0, 0));
}

int dst[3000];
bool bfs(){
    memset(dst, -1, sizeof dst);
    queue <ii> q; q.push(ii(source, 0));
    dst[source] = 0;
    while(!q.empty()){
        int u = q.front().F, d = q.front().S; q.pop();
        if(u==sink) return true;
        rep(i, 0, adj[u].size()){
            int id = adj[u][i];
            use aux = edg[id];
            if(dst[aux.to]!=-1) continue;
            if(aux.cap-aux.flow>0 && aux.cost <= tempo){
                dst[aux.to] = d+1;
                q.push(ii(aux.to, d+1));
            }
        }
    }
    return false;
}

int ptr[3000];
ll dfs(int u, ll c){
    if(u==sink) return c;
    ll ret = 0;
    for(; ptr[u]<adj[u].size(); ptr[u]++){
        int id = adj[u][ptr[u]];
        use aux = edg[id];
        if(dst[aux.to]!=dst[u]+1) continue;
        if(aux.cap-aux.flow>0 && aux.cost <= tempo){
            ret = dfs(aux.to, min(c, aux.cap-aux.flow));
            if(ret>0){
                edg[id].flow+=ret;
                edg[id^1].flow-=ret;
                return ret;
            }
        }
    }
    return ret;
}

ll maxFlow(){
    ll ret = 0;
    rep( i, 0, edg.size() ) edg[i].flow = 0;
	while(bfs()){
        memset(ptr, 0, sizeof ptr);
        while(1){
            ll push = dfs(source, 1LL<<56);
            if(!push) break;
            ret+=push;
        }
    }
    return ret;
}

int main(){
	int p, r, m, a, b, c, x;
	scanf("%d%d%d", &p, &r, &m );
	source = 0;
	sink = p+r+1;
	ll sum = 0;
	rep( i, 1, p+1 ){
		scanf("%d", &x );
		sum += x;
		add_edge(r+i, sink, 0, x );
	}
	rep( i, 1, r+1 ){
		scanf("%d", &x );
		add_edge(source, i, 0, x );
	}
	while( m-- ){
		scanf("%d%d%d", &a, &b, &c );
		add_edge(b, r+a, c, 0x3f3f3f3f );
	}
	
	ll lo = 0, hi = 100000000000LL, ans = -1;
	
	while( lo <= hi ){
		tempo = lo+(hi-lo)/2;
		ll aux = maxFlow();
		if( aux >= sum ){
			ans = tempo;
			hi = tempo-1;
		}
		else lo = tempo+1;
	}
	cout << ans << "\n";
}
