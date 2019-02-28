#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 401
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

int res[MAXV][MAXV], maxflow, f, s, t;  // s = inicio , t = fim 
vector<int> adj[MAXV]; int p[MAXV], V; // V = num de vertices   
void aug(int v, int minEdge) {         
	if( v == s ){                 
		f = minEdge;                 
		return;         
	} 
	else if( p[v] != -1 ){                 
		aug(p[v], min(minEdge, res[p[v]][v]));                 
		res[p[v]][v] -= f;                 
		res[v][p[v]] += f;         
	} 
}   
void EdmondsKarp(){         
	maxflow = 0;         
	while (1){
		f = 0;
		bitset<MAXV> vis;
		vis.set(s);
		queue<int>q;
		q.push(s);
		rep(i,0,V) p[i] = -1;
		while (!q.empty()){
			int u = q.front();
			q.pop();
			if (u == t) break;
			int tam = adj[u].size();
			rep(i,0,tam){
				int v = adj[u][i];
				if (res[u][v] > 0 && !vis.test(v)){
					vis.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		aug(t, INF);
		if (f == 0) break;
		maxflow += f;
	}
}

int main(){
	int T = 1;
	map < string , int > mp;
	while( 1 ){
		string nome, nome2, dest;
		int n = readInt()+1;
		mp.clear();
		if( n == 1 ) break;
		memset( res, 0, sizeof res );
		rep( i, 0, MAXV ) adj[i].clear();
		int sum = 0;
		rep( i, 1, n ){
			cin >> nome;
			mp[nome] = i;
			int kk = readInt();
			res[0][i] = kk;
			res[i][0] = kk;
			sum += kk;
			adj[0].pb(i);
			adj[i].pb(0);	
		}
		int m = readInt();
		cin >> dest;
		mp[dest] = n++;
		while( m-- ){
			cin >> nome >> nome2;
			if( !mp.count( nome ) ) mp[nome] = n++;
			if( !mp.count( nome2 ) ) mp[nome2] = n++;
			int k = readInt();
			int u = mp[nome], v = mp[nome2];
			res[u][v] = k;
			res[v][u] = k;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		s = 0, t = mp[dest], V = n;
		EdmondsKarp();

		printf("Instancia %d\n", T++);
		if( maxflow >= sum ) printf("viavel\n");
		else printf("inviavel\n" );
		printf("\n");
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
