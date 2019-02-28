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
#define maxn 100000
#define maxl 20
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

vector<int> E[maxn];
vector<int> W[maxn];
int prof[maxn];
int dist[maxn][maxl];
int pai[maxn][maxl];
int n, m;

void dfs( int v, int p, int depth, int d ){
    prof[v] = depth;
    dist[v][0] = d;
    pai[v][0] = p;
    for( int i = 1; i < maxl; i++ ){
        pai[v][i] = pai[ pai[v][i-1] ][i-1];
        dist[v][i] = min( dist[v][i-1], dist[pai[v][i-1]][i-1] );
    }
    for (int i = 0; i < E[v].size(); i++ ){
        int viz = E[v][i];
        if( viz == p ) continue;
        dfs( viz, v, depth+1, W[v][i] );
    }
}

void calc(){
    for( int i = 0; i < maxl; i++ ){
        pai[0][i] = 0; dist[0][i] = INF;
    }
    for( int i = 0; i < E[0].size(); i++ ){
        dfs( E[0][i], 0, 1, W[0][i] );
    }
}

int solve( int a, int b ){
    int pa = a, pb = b, resp = INF;
    if( prof[pb] > prof[pa] ) swap(pa,pb);
    /*sobe na arvore para igualar a profundidade*/
    while( prof[pa] > prof[pb] ){
        int j = 0;
        for( int i = 0; i < maxl; i++ ){
            if( prof[pai[pa][i]] < prof[pb] ) break;
            j = i;
        }
        resp = min( resp, dist[pa][j] ); pa = pai[pa][j];
    }
    /*acha o lca*/
    while( pa != pb ){
        int j = 0;
        for( int i = 0; i < maxl; i++ ){
            if( pai[pa][i] == pai[pb][i] ) break;
            j = i;
        }
        resp = min( resp, dist[pa][j] ); resp = min( resp, dist[pb][j] );
        pa = pai[pa][j]; pb = pai[pb][j];
    }
    return resp;
}

int P[maxn];

void init(int v){
    for (int i=0; i <= v; i++)
        P[i] = i, E[i].clear(), W[i].clear(); // inicialmente cada vertice esta no seu proprio conjunto
}

int findset(int i){ // retorna o conjunto que o elemento i pertence
    if (i != P[i]) 
        P[i] = findset(P[i]); // i esta no mesmo conjunto de pai[i]
    return P[i];
}
 
void unionset(int a, int b){
    int aa = findset(a); 
    int bb = findset(b);
    P[bb] = aa; // aa se torna o pai do conjunto bb
}

bool sameset(int a, int b){
    return findset(a) == findset(b); // retorna true se os conjuntos que contem os elementos A e B é o mesmo
}

void Kruskal( int m ){
	priority_queue < pair < int, ii > > pq;
	while( m-- ){
		int u = readInt()-1;
		int v = readInt()-1;
		int w = readInt();
		pq.push( mk( w, ii( u, v ) ) );
	}
	while( !pq.empty() ){
		int u = pq.top().S.F, v = pq.top().S.S, w = pq.top().F;
		if( !sameset( u, v ) ){
			E[u].push_back(v); E[v].push_back(u);
            W[u].push_back(w); W[v].push_back(w);
	        unionset( u, v );  
	    }
	    pq.pop();
	}
}

int main(){
	
	while( scanf("%d", &n ) != EOF ){
		init( n );
		int m = readInt();
		int q = readInt();
		Kruskal( m );
		calc();
		while( q-- ){
			int u = readInt()-1;
			int v = readInt()-1;
			printf("%d\n", solve( u, v ) );
		} 
	}
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

