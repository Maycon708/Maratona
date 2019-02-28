#include <bits/stdc++.h>
  
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 100010
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
  
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
  
using namespace std;
  
typedef pair <int, int> ii;
typedef long long int ll;
  
int n, bit[MAXV], vet[MAXV];
  
void update(int x, int v){
    while(x <= n){
        bit[x] = bit[x] + v;
        x = x + (x&-x);
    }
}
  
int query(int x){
    int ans = 0;
    while(x > 0){
        ans = ans + bit[x];
        x = x - (x&-x);
    }
    return ans;
}
  
vector < ii > v;
vector < ii > V;
  
bool bb(int x){
      
    int ini= 0, fim = V.size()-1, mid;
      
    while(ini<=fim){
          
        mid = (ini+fim)/2;
         
        if( x >= V[mid].F && x <= V[mid].S) return true;
        if( x < V[mid].F)  fim = mid-1;
        else ini = mid+1;
          
    }
      
    return false;
      
}
  
int main(){
  
    int t, c, ini, fim, e, aux;
      
  
    scanf("%d", &t);
      
    rep(k, 1, t+1){
          
        scanf("%d%d", &n, &c);
          
        while(c--){
            scanf("%d%d", &ini, &fim);
            v.pb(ii(ini, fim));                     
        }
          
        sort(all(v));
         
        int x = v[0].F, y = v[0].S;
         
        rep(i, 1, v.size()){
            if(v[i].F<=y+1) y = max(y, v[i].S);
            else{
                V.pb(ii(x,y));
                x = v[i].F;
                y = v[i].S;
            }
        }         
        V.pb(ii(x,y));
         
//      rep(i, 0, V.size())
//          debug2(V[i].F, V[i].S)
          
        scanf("%d", &e);
          
        int cont = 0;
                     
        while(e--){
            scanf("%d", &aux);
              
            if(bb(aux)) cont++;
              
        }
          
        printf("Caso #%d: %d\n", k, cont);
        v.clear();
        V.clear();
    }
  
    return 0;
}
