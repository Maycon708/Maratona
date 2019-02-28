#include<bits/stdc++.h>
 
using namespace std;
 
const double INF = 0x3f3f3f3f;
 
typedef pair<int,double> ii;
const int MAXV = 10001;
 
#define pb push_back
#define mk make_pair
 
vector<ii> adj[MAXV];
long double dist[MAXV];
long long int pai[MAXV], n;
 
long long int dijkstra(int ini, int fim){
    bool vis[MAXV];
 
    priority_queue<pair<double,int> > pq;
 
    for(int i=0; i<=n; i++){
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
            double d_u_v = adj[u][i].second;
   		  	//cout << u << " - " << v << " : " << dist[u]+ d_u_v << " d[v] = " << dist[v] << endl;
			if(dist[u] + d_u_v < dist[v]){  
                dist[v] = dist[u] + d_u_v;
                pai[v] = u;
                pq.push(make_pair(-dist[v],v));
            }
        }
 
        if(u == fim){
        	long long int asdf = dist[fim];
        	return asdf;
		} 
    }
 
    return -1;
}

int main(){
    
    int c, x[200], y[200], r[200], ini, fim;
    
    while(cin >> n && n){
    	
    	for(int i=1; i<=n; i++){
    		adj[i].clear();
    		cin >> x[i] >> y[i] >> r[i]; 
		}
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				double d = hypot(x[i]-x[j], y[i]-y[j]);
				if(d <= r[i]){
					adj[i].pb(ii(j,d));
				}
			}
		}
		
		cin >> c;
		
		while(c--){
			cin >> ini >> fim;
			
			cout << dijkstra(ini,fim) << endl;
		}
    	
	}
    
    return 0;
}
