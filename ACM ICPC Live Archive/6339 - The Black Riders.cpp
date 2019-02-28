#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define wait system("PAUSE");

using namespace std;

/*
    HOPCROFT KARP MAXIMUM BIPARTITE MATCHING
    Encontra o casamento bipartido maximo de forma eficiente
    1) Chamar a funcao init(L,R),L = #vertices da esquerda, R = #vertices da direita
    2) Usar addEdge(Li,Ri) para adicionar a aresta Li -> Ri
    3) maxMatching() retorna o casamento maximo
       matching[]: matching[Ri] -> armazena Li
    Complexidade do algoritmo:
       O(sqrt(n) * m)
    Problemas resolvidos:
       ENGENHAR (SPOJ BR)
       URI 1208, 1056, 1330, 1490
       Live Archive 6525
    Adicionado por:
       Jorge Gabriel Siqueira
*/
#define MAXN1 30010
#define MAXN2 30010
#define MAXM 60020
int n1, n2, edges, last[MAXN1], prv[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int L, int R){
    n1 = L, n2 = R;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v){
    head[edges] = v;
    prv[edges] = last[u];
    last[u] = edges++;
}

void bfs(){
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u){
        if (!used[u]){
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++){
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prv[e]){
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0){
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1){
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prv[e]){
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)){
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching(){
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;){
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}

int main() {
	int t, n, m, k, c, dist[100][100];
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d%d%d", &n, &m, &k, &c );
		int lo = 0, hi = 20000000, ans = 20000000;
		rep( i, 0, n )
			rep( j, 0, m ) 
				scanf("%d", &dist[i][j] );
		while( lo < hi ){
			int mid = ( lo + hi  )/2;
			init(n, 2*m);
			rep( i, 0, n ){
				rep( j, 0, m ){
					if( dist[i][j] <= mid ) addEdge( i, 2*j );
					if( dist[i][j] <= mid-c ) addEdge( i, 2*j+1 );
				}
			}
			int x = maxMatching();
			if( x < k ) lo = mid+1;
			else ans = min( ans, mid ), hi = mid;
		}
		printf("%d\n", ans );
	}
    return 0;
}




















