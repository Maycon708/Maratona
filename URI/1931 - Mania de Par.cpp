#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 21005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

vector<ii> adj[MAXV];
long long int dist[MAXV];
long long int pai[MAXV];

int n;

int dijkstra(int ini, int fim){
    bool vis[MAXV];
    
    priority_queue< ii > pq;
    
    for(int i=0; i<2*n+10; i++){
        dist[i] = INF;
        vis[i] = false;
        pai[i] = -1; 
    }
    
    dist[ini] = 0;
        
    pq.push(mp(0,ini));
    
    while(!pq.empty()){
    
        int u = pq.top().second;
        pq.pop();
    
        if(vis[u]) continue;
        vis[u] = true;
    
        for(int i=0; i<adj[u].size(); i++){ 
            int v = adj[u][i].first;        
            int d_u_v = adj[u][i].second;
            //cout << u << " - " << v << " : " << dist[u]+ d_u_v << " d[v] = " << dist[v] << endl;
            if(dist[u] + d_u_v < dist[v]){  
                dist[v] = dist[u] + d_u_v;
                pai[v] = u;
                pq.push(make_pair(-dist[v],v));
            }
        }
    
        if(u == fim)return dist[fim]; 
    }
    
    return -1;
}

int main(){
//	freopen("code.in", "r", stdin);
// 	freopen("out_maycon.txt", "w", stdout);

	int m, u, w, c;
	
	while(scanf("%d%d", &n, &m) != EOF){
		
		rep(i, 0, 2*n+10) adj[i].clear();
		
		rep(i,0,m){
			
			scanf("%d%d%d", &u, &w, &c);
			
			adj[2*u].pb(ii(2*w+1, c));
			
			adj[2*u+1].pb(ii(2*w, c));
			
			adj[2*w].pb(ii(2*u+1, c));
			
			adj[2*w+1].pb(ii(2*u, c));
			
		}
		
		printf("%d\n", dijkstra(2,2*n));
		
	}

	return 0;
}


