#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define clr(a) memset((a),0,sizeof(a))
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

typedef unsigned long long ll;
typedef pair < int, int >  ii;
typedef vector < int >  vi;
typedef vector < ii >  vii;

int N;
vector<int> adj[222];
int cap[222][222]; 		
int q[222], previ[222];
int source, sink; 		

int dinic(){
    int flow = 0;
    while(1){
        memset( previ, -1, sizeof(previ) );
        int qf = 0, qb = 0;
        previ[q[qb++] = source] = -2;
        while( qb > qf && previ[sink] == -1 ){
            for( int u = q[qf++], m = adj[u].size(), i = 0, v; i < m; ++i )
                if( previ[v = adj[u][i]] == -1 && cap[u][v] )
                    previ[q[qb++] = v] = u;
        }
        if( previ[sink] == -1 )
            break;
        for( int z = 0; z < N; ++z )
            if( cap[z][sink] && previ[z] != -1 ){
                int bot = cap[z][sink];
                for( int v = z, u = previ[v]; u >= 0; v = u, u = previ[v] )
                    bot = min (bot, cap[u][v]);
                if(!bot)
                    continue;
                cap[z][sink] -= bot;
                cap[sink][z] += bot;
                for( int v = z, u = previ[v]; u >= 0; v = u, u = previ[v] ){
                    cap[u][v] -= bot;
                    cap[v][u] += bot;
                }
                flow += bot;
            }
    }
    return flow;
}

int maxflow(){
    for( int i = 0; i < N; ++i )
        adj[i].clear();
    for( int i = 0; i < N; ++i )
        for( int j = 0; j < N; ++j )
            if( cap[i][j] || cap[j][i] )
                adj[i].push_back (j);
    return dinic();
}


int main(){
	int n, m, k, u, v, t = 1;
	while( scanf("%d%d%d", &n, &m, &k ) != EOF ){
		source = 0, sink = n+m+1, N = sink + 1;
		memset( cap, 0, sizeof cap );
		rep( i, 1, n+1 ){
			scanf("%d", &cap[0][i] );
		}
		rep( i, 1, m+1 ){
			v = n + i;
			cap[v][sink] = 1;
		}
		while( k-- ){
			scanf("%d%d", &u, &v );
			v += n;
			cap[u][v] = 1;
		}
		printf("Instancia %d\n", t++ ); 
		printf("%d\n", maxflow() );
		printf("\n");
	}
    return 0;
}
