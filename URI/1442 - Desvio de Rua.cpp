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
 
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
 
using namespace std;
 
typedef pair <int, int> ii;
typedef long long int ll;

inline ll readInt();

vector<int> adj[MAXV], adj2[MAXV];

int dfs_num[MAXV], dfs_low[MAXV], dfs_parent[MAXV], cnt;
int dfscounter, V, P, mat[MAXV][MAXV];
bool vis2[MAXV];

void pontes(int u){
	dfs_low[u] = dfs_num[u]= dfscounter++;
	int tam = adj2[u].size();
	rep( j, 0, tam ){
		int v = adj2[u][j];
		if( dfs_num[v] == -1 ){
			dfs_parent[v]= u;
			pontes(v);
			if( dfs_low[v] > dfs_num[u] ){
				if( !mat[v][u] ) P++;
			}
			dfs_low[u]= min( dfs_low[u], dfs_low[v] );
		}
		else if( v != dfs_parent[u] )
			dfs_low[u]= min( dfs_low[u], dfs_num[v] );
	}
}

int dfs_Num[MAXV], dfs_Low[MAXV], vis[MAXV], dfsNumber, numSCC;
vector<int> S;

void tarjan( int u ){

    dfs_Low[u] = dfs_Num[u] = dfsNumber++;
    S.pb(u);
    vis[u] = 1;
    int tam = adj[u].size();
    rep( j, 0, tam ){
        int v = adj[u][j];
        if( dfs_Num[v] == -1 )
            tarjan( v );
        if( vis[v] )
            dfs_Low[u] = min( dfs_Low[u], dfs_Low[v] );
    }
    if( dfs_Low[u] == dfs_Num[u] ){
        ++numSCC;
        while(1){
            int v = S.back(); S.pop_back(); vis[v] = 0;
            if( u == v ) break;
        }
    }
}

void init(){
    numSCC = 0, P = 0, cnt = 0;
    rep( i, 0, V+1 ){
    	rep( j, 0, V+1 ) mat[i][j] = 0;
        adj[i].clear(), adj2[i].clear();
        dfs_low[i] = dfs_parent[i] = dfs_Low[i] = vis[i] = vis2[i] = 0;
        dfs_num[i] = dfs_Num[i] = -1;
    }
}

void dfs( int u ){
    if( vis2[u] ) return;
    vis2[u] = 1;
    cnt++;
    rep( i, 0, adj2[u].size() ){
        dfs( adj2[u][i] );
    }
}

int main(){

    int m, u1, v1, c1;
    while( scanf("%d%d", &V, &m ) != EOF ){
        
        init();
        
        scanf("%d%d%d", &u1, &v1, &c1 );
        u1--, v1--;
        
        rep( i, 1, m ){
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c );
            u--, v--, c--;
			adj[u].pb(v);
            if( c ) adj[v].pb(u), mat[u][v] = mat[v][u] = 1;
			adj2[u].pb(v);
            adj2[v].pb(u);
        }

        rep( i, 0, V ){
            if( dfs_Num[i] == -1 ){
                tarjan(i);
            }
        }
        dfs( 0 );
        if( numSCC == 1 ) printf("-\n");
        else if( cnt != V ) printf("*\n");
        else{
            rep( i, 0, V ){
                if( dfs_num[i] == -1 ){
                    pontes(i);
                }
            }
            if( P ) printf("2\n");
            else printf("1\n");
        }
        
    }
}

