#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();
int k, V;
vector<ii> adj[1005];
bool vis[1005][1005];
int dist[1005][1005];

void dijkstra(){
	rep( i, 0, V )
		rep( j, 0, k+1 ){
			vis[i][j] = 0;
			dist[i][j] = INF;
		}
	priority_queue < pair < int, ii > > pq;
	pq.push( mk( 0, ii( 1, 0 ) ) );
	dist[0][1] = 0;
    while(!pq.empty()){
        int u = pq.top().S.S;
        int q = pq.top().S.F;
        pq.pop();
        if(q+1 > k) continue;
        if(!vis[u][q]){
            vis[u][q] = true;
            rep(i,0,adj[u].size()){
                int v = adj[u][i].F;
                int duv = adj[u][i].S;
                if(dist[u][q] + duv < dist[v][q+1]){
                    dist[v][q+1] = dist[u][q] + duv;
                    if(dist[v][q+1] >= dist[v][q]) continue;
                    pq.push(mk(-dist[v][q+1],ii(q+1,v)));
                }
            }
        }
    }
    int ans = INF;
    rep(i,0,k+1)
        ans = min(ans,dist[V-1][i]);
    printf("%d\n",ans == INF ? -1 : ans);
}
int main(){
    int tc, e, x, y, c;	
    tc = readInt();
    while(tc--){
        V = readInt();
		e = readInt();
		k = readInt();
        rep( i, 0, e ){
			x = readInt();
			y = readInt();
			c = readInt();
            adj[x].pb(ii(y,c));
        }
        dijkstra();
        rep(i,0,V+1)
        adj[i].clear();
    }
    return 0;
}

ll readInt () {
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

