#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define NMAX 5005
#define F first
#define S second
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair < ll, ll >  ii;


int cap[NMAX][NMAX], cost[NMAX][NMAX], D; //capacidades e custos: vertices de 0 a n-1
int adj[NMAX][NMAX], fnet[NMAX][NMAX], deg[NMAX], par[NMAX], d[NMAX], pi[NMAX];
int n, source, sink, cont; //numero de vertices, origem e destino do fluxo

//Dijkstra para grafos densos
bool dijkstra1 (int s, int t)
{
    for (int i = 0; i < n; ++i)
        d[i] = INF, par[i] = -1;
    d[s] = 0;
    par[s] = -n - 1;
    while (1)
    {
        int u = -1, bestD = INF;
        for (int i = 0; i < n; ++i)
            if(par[i] < 0 && d[i] < bestD)
                bestD = d[u = i];
        if (bestD == INF)
            break;
        par[u] = -par[u] - 1;
        for (int i = 0; i < deg[u]; ++i)
        {
            int v = adj[u][i];
            if (par[v] >= 0)
                continue;
            if (fnet[v][u] && d[v] > d[u] + pi[u] - pi[v] - cost[v][u])
            {
                d[v] = d[u] + pi[u] - pi[v] - cost[v][u];
                par[v] = -u - 1;
            }
            if (fnet[u][v] < cap[u][v] && d[v] > d[u] + pi[u] - pi[v] + cost[u][v])
            {
                d[v] = d[u] + pi[u] - pi[v] + cost[u][v];
                par[v] = -u - 1;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (pi[i] < INF)
            pi[i] += d[i];
    return par[t] >= 0;
}

//Dijkstra para grafos esparsos
#define BUBL { \
t = q[i]; q[i] = q[j]; q[j] = t; \
t = inq[q[i]]; inq[q[i]] = inq[q[j]]; inq[q[j]] = t; }
int q[NMAX], inq[NMAX], qs;
bool dijkstra (int s, int t)
{
    memset (d, INF, sizeof(d));
    memset (par, -1, sizeof(par));
    memset (inq, -1, sizeof(inq));
    d[s] = qs = 0;
    inq[q[qs++] = s] = 0;
    par[s] = n;
    while (qs)
    {
        int u = q[0];
        inq[u] = -1;
        q[0] = q[--qs];
        if (qs) inq[q[0]] = 0;
        for (int i = 0, j = 2*i + 1, t; j < qs; i = j, j = 2*i + 1)
        {
            if (j + 1 < qs && d[q[j + 1]] < d[q[j]])
                ++j;
            if (d[q[j]] >= d[q[i]])
                break;
            BUBL;
        }
        for (int k = 0, v = adj[u][k]; k < deg[u]; v = adj[u][++k])
        {
            if (fnet[v][u] && d[v] > d[u] + pi[u] - pi[v] - cost[v][u])
                d[v] = d[u] + pi[u] - pi[v] - cost[v][par[v] = u];
            if (fnet[u][v] < cap[u][v] && d[v] > d[u] + pi[u] - pi[v] + cost[u][v])
                d[v] = d[u] + pi[u] - pi[v] + cost[par[v] = u][v];
            if (par[v] == u)
            {
                if(inq[v] < 0)
                {
                    inq[q[qs] = v] = qs;
                    qs++;
                }
                for (int i = inq[v], j = (i - 1)/2, t;
                        d[q[i]] < d[q[j]]; i = j, j = (i - 1)/2)
                    BUBL;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (pi[i] < INF)
            pi[i] += d[i];
    return par[t] >= 0;
}

pair <long long int, long long int> mincost_maxflow()
{
    memset (deg, 0, sizeof(deg));
    memset (fnet, 0, sizeof(fnet));
    memset (pi, 0, sizeof(pi));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (cap[i][j] || cap[j][i])
                adj[i][deg[i]++] = j;
    long long int flow = 0, fcost = 0;
    
    cont = 0;
    
    while (dijkstra (source, sink)){
        
        if( D <= 0 ) break;
		
		int bot = INF;
        for (int v = sink, u = par[v]; v != source; u = par[v = u])
            bot = min (bot, fnet[v][u] ? fnet[v][u] : (cap[u][v]-fnet[u][v]));
        for (int v = sink, u = par[v]; v != source; u = par[v = u])
            if(fnet[v][u])
            {
                fnet[v][u] -= bot;
                fcost -= (long long int) ( min( D, bot ) * cost[v][u]);
            }
            else
            {
                fnet[u][v] += bot;
                fcost += (long long int) ( min( bot, D ) * cost[u][v]);
            }
        flow += (long long int) bot;
        D -= bot;
    }
    return make_pair (fcost,flow);
}


int main(){
	
	int m, x, y, c[5010], xx[5010], yy[5010];
	int test = 1;
	while( scanf("%d", &n) != EOF ){
		
		rep(i,0,n)
			rep(j,0,n){
				cap[i][j] = 0;
				cost[i][j] = 0;
			}
		
		scanf("%d", &m);
		
		rep(i,0,m)
			scanf("%d%d%d", &xx[i], &yy[i], &c[i]);
		
		int  k;
		scanf("%d%d", &D, &k);
		rep( i, 0, m ){
			x = xx[i]-1,  y = yy[i]-1;
			cap[x][y] = min( k, D );
			cap[y][x] = min( k, D );
			cost[x][y] = c[i];
			cost[y][x] = c[i];
		}
		
		source = 0; sink = n-1;
		int DD = D;
		ii aux = mincost_maxflow();
		
		printf("Instancia %d\n", test++);
		if(aux.S < DD )printf("impossivel\n\n");
		else printf("%lld\n\n", aux.F );
		
	}

	return 0;
}
