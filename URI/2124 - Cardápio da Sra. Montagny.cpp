#include <bits/stdc++.h>
 
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 4005
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
int nDfs, nScc, k;

inline int neg (int x){
    return x^1; 
}

void addEdge(int a, int b){
     adj[neg(a)].pb(b);
     adj[neg(b)].pb(a);
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
		
vector <string> M;
void init(){
	
	rep(i, 0, MAXV)
    	adj[i].clear();
    mp.clear();	
    M.clear();
	memset (num, -1, sizeof num);
    memset (low, -1, sizeof low);
    memset (inSt, false, sizeof inSt);
    while(!s.empty()) s.pop();
    nDfs = nScc = 0;
        
}

int mp_(char c, string S){
	
	//debug(mp[S]);
	
	if(c == '!'){
		if(mp.find(S) == mp.end())    
            mp[S] = k++;
        
        return neg( 2*mp[S] );	
	}
	else{
				
		if(mp.find(S) == mp.end())    
            mp[S] = k++;
        
        return 2*mp[S];	
	
	}
	
}

int main(){

    int tt = 1;
    char c, c1;
    string S, S1;

    while(scanf("%d", &n) != EOF){
    	
    	init();
    	
    	k = 0;
    	
        rep(i, 0, n){
            cin >> S >> S1;
            
            int v, u;
            c = c1 = ' ';
            
            if(S[0] == '!') c = S[0], S = S.substr(1, S.size()-1);
            if(S1[0] == '!') c1 = S1[0], S1 = S1.substr(1, S1.size()-1);
            
          	u = mp_(c, S);
          	v = mp_(c1, S1);
      	    //debug2(S, S1)
      	    //debug2(u, v)
      	    
      	    addEdge(u, v);
      	            
        }
        
        rep(i, 0, 2*k)
        	if(num[i] == -1) tarjanScc(i);
        
        bool ok = true;
        
        rep(i, 0, n)
        	if(scc[i] == scc[neg(i)]){
        		ok = false;
        		break;
        	}
        	
        printf("Instancia %d\n", tt++);
        if(ok) printf("sim\n");
        else printf("nao\n");
        printf("\n");        
    }

    return 0;
}
