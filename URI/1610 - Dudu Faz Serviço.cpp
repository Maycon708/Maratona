#include<bits/stdc++.h>
 
using namespace std;
 
vector<int> v[10001];
 
int aux[10001];
 
bool dfs(int l){
    aux[l]=1;
    bool aux2=true;
    for(int i=0; i<v[l].size(); i++){
        int w=v[l][i];
        if(aux[w]==0 && aux2){
            dfs(w);
        }
        if(aux[w]==1){
            aux2=false;
            return true;
        }
    }
    aux[l]=2;
    return false;
}
 
int main(){
    int t, n, m, a, b;
     
    cin>>t;
     
    while(t--){
        cin >> n >> m;
        while(m--){
            cin >> a >> b;
            v[a].push_back(b);
        }
        for(int i=1; i<=n; i++)aux[i]=0;
        bool aux2=true;
        for(int i=1; i<=n; i++)
        if(!aux[i])
            if(dfs(i)) {
            cout <<"SIM" << endl;
            aux2=false;
            break;
        }
        if(aux2)cout<< "NAO" << endl;
        for(int i=1; i<=n; i++)v[i].clear();
    }
    return 0;
}
