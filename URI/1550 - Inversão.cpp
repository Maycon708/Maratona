#include<bits/stdc++.h>
     
using namespace std;
     
int r;
 
bool vis[11115];
     
int invers ( int a){
    int aux = 0;
    while(a){
        aux*=10;
        aux += a%10;
        a/=10;
    }
    return aux;
}
     
int solve(int a){
     
    queue < pair < int, int > > q;
     
    //vis[a] = true;
    q.push(make_pair(a,0));
     
    while(!q.empty()){
     
            int b = q.front().first;
        int c = q.front().second;
        q.pop();
        if(b == r) return c;
        if(b > 11111 || vis[b]) continue;
         
        vis[b] = true;
        q.push(make_pair(b+1, c+1));
        q.push(make_pair(invers(b), c+1));
     
    }
     
}
     
int main(){
    int t, a;
    cin >> t;
    while(t--){
        memset(vis, false, sizeof(vis));
        cin >> a >> r;
        cout << solve(a) << endl;
    }
}   
