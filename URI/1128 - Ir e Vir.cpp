#include<bits/stdc++.h>
  
using namespace std;
  
vector<int> vec[10001];
  
bool aux[10001];
int cont;
 
void dfs(int l){
    aux[l]=true;
    for(int i=0; i<vec[l].size(); i++){
        int w=vec[l][i];
        if(!aux[w]){
            dfs(w);
        }
    }
}
  
int main(){
    int t, n, m, a, b, c, k=1;
      
    
    while(scanf("%d %d", &n, &m) && n && m){
    	int cont=1;
        while(m--){
        	scanf("%d %d %d", &a, &b, &c);
        	vec[a].push_back(b);
        	if(c==2)vec[b].push_back(a);
        }
        for(int j=1; j<=n; j++){
        	for(int i=0; i<=n; i++) aux[i]=false;
        	dfs(j);
        	for(int i=1; i<=n; i++) if(!aux[i]) cont=0;
        	if(cont==0)break;
        }
        printf("%d\n", cont);
       	for(int i=0; i<=n; i++) vec[i].clear();
    }
    return 0;
}
