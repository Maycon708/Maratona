#include <bits/stdc++.h>
   
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
  
using namespace std;
  
typedef long long int ll;
typedef pair<int, int> ii;
  
map < pair<ii, int> , int > mp;
int pd[25][25][2500], ultima, m, n;
  
int solve(int x, int y, int t){
    if(t>ultima) return 0;
      
    if(pd[x][y][t] != -1) return pd[x][y][t];
      
    int ans = 0;
    int aux = 0;
      
    if(mp[mk(ii(x,y), t)]) aux = mp[mk(ii(x,y), t)];
      
    ans = solve(x,y,t+1) + aux;
    if(x+1<25) ans = max(ans, solve(x+1, y, t+1) + aux);
    if(x-1>=0) ans = max(ans, solve(x-1, y, t+1) + aux);
    if(y+1<25) ans = max(ans, solve(x, y+1, t+1) + aux);
    if(y-1>=0) ans = max(ans, solve(x, y-1, t+1) + aux);     
      
    return pd[x][y][t] = ans;
      
}
  
int main(){
      
    int x, y, t, k;
      
    scanf("%d", &k);
          
        memset(pd, -1, sizeof(pd));
        ultima = 0;
        rep(i,0,k){
            scanf("%d%d%d", &x, &y, &t);
              
            mp[ mk(ii(x,y), t) ] += 1;
              
            ultima = max(ultima, t);
        }
          
        printf("%d\n", solve(6,6,0));
        mp.clear();
          
    return 0;
}
