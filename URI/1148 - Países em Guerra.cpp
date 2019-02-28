#include<bits/stdc++.h>
 
using namespace std;
 
const int INF = 0x3f3f3f3f;
 
typedef pair<int,int> ii;
const int MAXV = 501;
 
#define pb push_back
#define mk make_pair
 
vector<ii> adj[MAXV];
long long int dist[MAXV];
long long int pai[MAXV];
 
long long int dijkstra(int ini, int fim){
    bool vis[MAXV];
 
    priority_queue<pair<int,int> > pq;
 
    for(int i=0; i<=MAXV; i++){
        dist[i] = INF;
        vis[i] = false;
        pai[i] = -1; 
    }
 
    dist[ini] = 0;
     
    pq.push(make_pair(0,ini));
 
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

map <ii, bool> mp;

int main(){
    
    long long int n, e, x, y, h, k, aux, ini, fim;
    
    while(scanf("%lld%lld", &n, &e) && n+e){
        
        for(int i=0; i<=n; i++)adj[i].clear();
        
        while(e--){
            scanf("%lld%lld%lld", &x, &y, &h);
            adj[x].pb(ii(y,h));
            if(mp[ii(y,x)]){
                adj[x].pb(ii(y,0));
                adj[y].pb(ii(x,0));
            }
            else{
                mp[ii(x,y)] = true;
            }
        }
        scanf("%lld", &k);
        
        while(k--){
            scanf("%lld%lld", &ini, &fim);
            
            aux = dijkstra(ini,fim);
            
            if(aux==-1) printf("Nao e possivel entregar a carta\n");
            else printf("%lld\n", aux);
        }
        printf("\n");
        mp.clear();
        
    }
    
    
    
    return 0;
}
