#include<bits/stdc++.h>
   
using namespace std;
   
vector<char> vec[10001];
vector<char> resp;   
bool aux[10001];
int cont;
 
void dfs(char l){
    aux[l-'a']=true;
    
    resp.push_back(l);
    
    for(int i=0; i<vec[l].size(); i++){
        char w=vec[l][i];
        if(!aux[w-'a']){
            dfs(w);
        }
    }
}
   
int main(){
    int t, n, m, v, k=1;
    char a, b;
       
    scanf("%d", &t);
    while(t--){
        cont=0;
        scanf("%d", &n);
        scanf("%d", &m);
        while(m--){
            cin>> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        printf("Case #%d:\n", k);
         
        for(int i=0; i<n; i++)
            if(!aux[i]){
                 cont++;
                 dfs(i+'a');
                 sort(resp.begin(), resp.end());
                 
                 for(int i=0; i<resp.size(); i++){
                 	cout<<resp[i]<<",";
				 }
				 resp.clear();
				 printf("\n");
            }
         
     
        printf("%d connected components\n\n", cont);
        k++;
        for(int i='a'; i<='z'; i++){
            aux[i-'a']=false;
            vec[i].clear();
        }
    }
    return 0;
}
