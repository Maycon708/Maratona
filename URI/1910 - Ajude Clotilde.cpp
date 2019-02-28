#include <bits/stdc++.h>
 
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define D(x) cout << #x << " = " << x << endl;
#define D2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
 
 
using namespace std;
 
typedef long long ll;
typedef pair < int, int >  ii;
 
inline bool valido(int x){
    if (x > 0 && x <= 100000) return true;
    return false;
}
vector<int> proibido;
int dist[100000+10];
 
int bfs(int o, int d, int k)
{
    memset(dist, -1, sizeof dist);
 
    if(!valido(o) || !valido(d)) return -1;
 
    dist[o] = 0;
 
    rep(i,0,k) dist[ proibido[i] ] = -2;
 
    queue<int> q;
    q.push(o);
 
    while (!q.empty()){
 
        int v = q.front();  q.pop();
 
        if (v == d) break;
        int w;
 
        w = v-1;    if(valido(w) && dist[w] == -1){
                        q.push(w);
                        dist[w] = dist[v] + 1;                    
                    }
 
        w = v+1;    if(valido(w) && dist[w] == -1){
                        q.push(w);
                        dist[w] = dist[v] + 1;                    
                    }
 
        w = v*2;    if(valido(w) && dist[w] == -1){
                        q.push(w);
                        dist[w] = dist[v] + 1;                    
                    }
 
        w = v*3;    if(valido(w) && dist[w] == -1){
                        q.push(w);
                        dist[w] = dist[v] + 1;                    
                    }
 
        if (v%2 == 0){
            w = v/2;    if(valido(w) && dist[w] == -1){
                            q.push(w);
                            dist[w] = dist[v] + 1;                    
                        }
        }
    
    }
    return dist[d];
}
 
int main(){
    int o, d, k, x;
 
 
    while (cin >> o >> d >> k){
        if(o == 0 && d == 0 && k == 0) break;
     
        proibido.clear();
        rep(i,0,k) {
            cin >> x;   
            proibido.pb(x);
        }
        int dist = bfs(o,d,k);
        cout << dist << "\n";
    }   
  return 0;
}
