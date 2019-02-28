#include <bits/stdc++.h>
  
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 10015
#define F first
#define S second
#define EPS 1e-9
  
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
  
using namespace std;
  
typedef pair <int, int> ii;
typedef long long int ll;
 
int c, n;
vector <int> adj[2*MAXV];
int num[2*MAXV];
int low[2*MAXV];
int scc[2*MAXV];
stack <int> s;
map <string, int > mp;
 
int inSt[2*MAXV];
int nDfs, nScc, k, x, y, ss, t;
 
inline int neg (int x){
    return x^1; 
}
 
void addEdge(int a, int b ){
    
  	int u = abs( a ), v = abs( b );
  	u--, v--;
    u <<= 1, v <<= 1;
    if( a < 0 ) u = neg( u );
   	if( b < 0 ) v = neg( v );
   	
   	adj[neg(u)].pb(v);
   	adj[neg(v)].pb(u);
     
    return;
}
 
void tarjanScc(int v) {
 
    num[v] = low[v] = nDfs++;
    s.push(v), inSt[v] = true;
     
    rep(i, 0, adj[v].size()){
         
        int w = adj[v][i];
         
        if( num[w] == -1 ){
            tarjanScc(w);
            low[v] = min ( low[v], low[w] );
        }
        else
            if( inSt[w] )
                low[v] = min ( low[v], low[w] );
    }
     
    if( low[v] == num[v]){
        int t;
        do {
            t = s.top();
            inSt[t] = false;
            scc[t] = nScc;
            s.pop();
        }while( t != v );
         
        nScc++;
    }
}
         
void init( int n ){
     
    rep(i, 0, 2*n){
        adj[i].clear();
        num[i] = -1;
        low[i] = -1;
        inSt[i] = false;
    }
    while(!s.empty()) s.pop();
    nDfs = nScc = 0;
         
}
 
int main(){
 	
 	int m;
    while( scanf("%d%d", &n, &m ) != EOF ){
        
        init(n);
         
        while( m-- ){
        	int u, v;
        	scanf("%d%d", &u, &v );
        	addEdge( u, v );

        }
        adj[neg(0)].pb(0);
        rep( i, 0, 2*n )
            if(num[i] == -1) tarjanScc(i);
             
        bool ok = true;
             
        rep(i, 0, 2*n)
            if(scc[i] == scc[neg(i)]){
                ok = false;
                break;
            }
         
        if(ok) printf("yes\n");
        else printf("no\n");        
         
    }
    return 0;
}
