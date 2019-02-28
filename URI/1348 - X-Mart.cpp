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

int readInt () {
    bool minus = false;
    int result = 0; char ch;
    
    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}
 
 
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
 
void addEdge(int a, int b, int flag){
     
    if(!a && !b) return;
     
    if( a > b ) swap(a, b);
     
    b--;
     
    if(!a){
        if( flag ) adj[ 2*b ].pb( neg( 2*b ));
        else adj[ neg( 2*b ) ].pb( 2*b );
        return;
    }
     
    a--; 
     
    if( flag ){
        adj[2*b].pb( neg( 2*a ));
        adj[2*a].pb( neg( 2*b ));
    }
    else {
        adj[neg( 2*a )].pb( 2*b );
        adj[neg( 2*b )].pb( 2*a );
    }
     
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
 
    while( 1 ){
        
        c = readInt();
        n = readInt();
        if( !c && !n ) break;
        
        init(n);
         
        rep(i, 0, c){
             
            x = readInt();
            y = readInt();
            ss = readInt();
            t = readInt();
             
            addEdge(x, y, 0);
            addEdge(ss, t, 1);          
        }       
     
        rep(i, 0, 2*n)
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
