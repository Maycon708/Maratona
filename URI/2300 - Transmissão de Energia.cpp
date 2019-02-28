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
    int t, n, m, a, b, v, k=1;
     
     
    while(scanf("%d %d", &v, &m) && v && m){
    	bool aux2=true;
        while(m--){
            scanf("%d %d", &a, &b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        dfs(1);
        for(int i=1; i<=v; i++)
        	if(!aux[i]) {
				aux2=false;
        	}
        printf("Teste %d\n", k);
        if(aux2)printf("normal\n\n");
        else printf("falha\n\n");
        
        for(int i=1; i<=v; i++){
        	vec[i].clear();
        	aux[i]=false;
        } 
        k++;
    }
    return 0;
}
