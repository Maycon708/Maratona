#include<bits/stdc++.h>
  
using namespace std;
  
const int INF = 0x3f3f3f3f;
  
typedef pair<int,int> ii;
const long long int MAXV = 1000000;
  
#define pb push_back
#define mk make_pair
#define rep(i,a,b) for(int i=a; i<b; i++)
  
vector<ii> adj[MAXV];
long long int dist[MAXV];
long long int pai[MAXV];
  
long long int dijkstra(int ini, int fim){
    bool vis[MAXV];
  
    priority_queue<pair<int,int> > pq;
  
    for(int i=0; i<MAXV; i++){
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

map<string, int> mp;

int main(){
      
    int m;
    string s1, s2, o, d, c;
     
    while(cin >> m && m){
         
        for(int i=0; i<MAXV; i++) adj[i].clear();
         
        cin >> o >> d;
         
    //  cout << o << "  " << d << endl;
         
        mp[o] = 1;
        mp[d] = 2;
        
		for(int i=0; i<26; i++){
			adj[0].pb(ii(26+i, 0));
			adj[26+i].pb(ii(0,0));
			adj[1].pb(ii(52+i,0));
			adj[52+i].pb(ii(1,0));
		}
		 
        int k = 3;
         
        for(int y=0; y<m; y++){
             
            cin >> s1 >> s2 >> c;
             
    //      cout << s1 << " " << s2 << endl;
             
            if(!mp[s1]){
                mp[s1] = k;
                k++;
            }
            if(!mp[s2]){
                mp[s2] = k;
                k++;
            }
            
            int li = c[0] - 'a';
			
			for(int i=0; i<26; i++){ 
			
				if(i!=li){
	            	adj[26*mp[s1]+li].pb(ii(26*mp[s2]+i, c.size()));
	             
	            	adj[26*mp[s2]+li].pb(ii(26*mp[s1]+i, c.size()));
	            }
        	}
        }
         
 /*    
    	 rep(i,0,k*26){
            if(adj[i].size()!=0)cout << i << " = { ";
            for(int j=0; j<adj[i].size(); j++){
                cout << adj[i][j].first << ", ";
	           }
            if(adj[i].size()!=0)cout << "}" << endl;
        }
   */
        long long int aux = dijkstra(0,1);
         
        if(aux==-1) cout << "impossivel" << endl;
        else cout << aux << endl;
        mp.clear();
    }
     
    return 0;
}
