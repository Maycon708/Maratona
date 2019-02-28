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
#define mp make_pair
 
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
 
using namespace std;
 
typedef pair <int, int> ii;
typedef long long int ll;

inline ll readInt();

vector<int> adj[MAXV];
int dfs_num[MAXV], dfs_low[MAXV], dfs_parent[MAXV];
int dfscounter, V, dfsRoot, rootChildren, ans;

void pontes(int u){

	dfs_low[u]= dfs_num[u]= dfscounter++;
	int tam = adj[u].size();
	rep(j,0,tam){
		int v = adj[u][j];
		if(dfs_num[v]==-1){
			dfs_parent[v]= u;
			pontes(v);
			if(dfs_low[v]> dfs_num[u]){
				ans++;
				//cout<<"Ponte entre "<<v<<" - "<<u<<endl;
			}
			dfs_low[u]= min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u])
			dfs_low[u]= min(dfs_low[u], dfs_num[v]);
	}
}
int main(){
	while( scanf("%d", &V ) != EOF ){
		int m = readInt();
		rep( i, 0, V+1 ) adj[i].clear();
		rep( i, 0, m ){
			int u = readInt()-1;
			int v = readInt()-1;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		rep(i,0,V+1){
			dfs_low[i]= dfs_parent[i] = 0;
			dfs_num[i]=-1;
		}
		ans = 0;
		rep(i,0,V)
			if(dfs_num[i]==-1){
				dfsRoot = i;
				pontes(i);
			}
		printf("%d\n",ans);
	}
}

inline ll readInt () {
    bool minus = false;
    ll result = 0; char ch;
  
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
