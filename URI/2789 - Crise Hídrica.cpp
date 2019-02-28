#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

const int MAXV = 5005;
const int LOGMAXN = 26;

int N;
vector<int> adj[MAXV]; 
int T[MAXV]; 
int P[MAXV][LOGMAXN]; 
int L[MAXV];
bool vis[MAXV];  
ll w[MAXV], p[MAXV], id[MAXV];
ll pd[MAXV][1010];

int lca(int p, int q){

    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    for (log = 1; 1 << log <= L[p]; log++);
    log--;
	   
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];
	   
    if (p == q)
       return p;
	   
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
 
    return T[p];
}

void process(){
       
    int i, j;
     
    for (i = 1; i <= N; i++)
	    for (j = 1; 1 << j <= N; j++)
    	    P[i][j] = -1;
             
    for (i = 1; i <= N; i++)
    	P[i][0] = T[i];
    for (j = 1; 1 << j <= N; j++)
        for (i = 1; i <= N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];

}
	 
void dfs(int u, int n){
   
    vis[u] = true;
    L[u] = n; 
    int tam = adj[u].size();
	    rep(i,0,tam)
        if(!vis[adj[u][i]]){
            dfs(adj[u][i], n+1);
            T[adj[u][i]] = u; 
        }  
}

void dfs2( int u, int p ){
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == p ) continue;
		dfs2(v, u);
		w[u] += w[v];
	}
}
	 
int main(){
	
	int n, d, a, b, c, m, q;
	
	scanf("%d%d", &n, &d );
	N = n;
	rep( i, 1, n ){
		scanf("%d%d", &a, &b );
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 0);
	process();
	
	scanf("%d", &m );
	rep( i, 0, m ){
		scanf("%d%d", &id[i], &p[i] );
	}
	scanf("%d", &q );
	while( q-- ){
		scanf("%d%d%d", &a, &b, &c );
		int l = lca(a, b);
		w[a] += c;
		w[b] += c;
		w[l] -= c;
		w[P[l][0]] -= c;
	}
	
	dfs2( 1, 0 );
    
    rep( i, 0, d ) pd[m][i] = 0;
    
    for( int i = m-1; i >= 0; i-- ){
    	for( int j = 0; j <= d; j++ ){
    		pd[i][j] = pd[i+1][j];
			if( j >= p[i] ) pd[i][j] = max( pd[i][j], pd[i+1][j-p[i]] + w[id[i]] ); 
		}
	}
	
	printf("%lld\n", pd[0][d] );
	   
    return 0;
}

