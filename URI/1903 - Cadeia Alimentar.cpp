#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int N = 100010, M = N * 10;

vector<int> adj[N], adj2[N];
int u[M], v[M], g[N], cnt;
int num[N], low[N], scc[N];
stack<int> s;
int inSt[N];
int nDfs, nScc, k, x, y, ss, t;

void tarjanScc( int v ){
 
    num[v] = low[v] = nDfs++;
    s.push(v), inSt[v] = true;
     
    rep( i, 0, adj[v].size() ){
        int w = adj[v][i];
        if( num[w] == -1 ){
            tarjanScc(w);
            low[v] = min ( low[v], low[w] );
        }
        else if( inSt[w] )
			low[v] = min ( low[v], low[w] );
    }
    if( low[v] == num[v]){
        int t;
        do{
            t = s.top();
            inSt[t] = false;
            scc[t] = nScc;
            s.pop();
        }while( t != v );
         
        nScc++;
    }
}
         
void init( int n ){
     
    rep( i, 0, n ){
        adj[i].clear();
        adj2[i].clear();
        g[i] = 0;
        num[i] = -1;
        low[i] = -1;
        inSt[i] = false;
    }
    while(!s.empty()) s.pop();
    nDfs = nScc = 0;
}
 
inline bool top_sort(){
	queue<int> q;
	rep( i, 0, nScc ){
		if( g[i] ) continue;
		q.push(i);
	}
	while( !q.empty() ){
		if( q.size() > 1 ) return 0;
		int u = q.front();
		q.pop();
		rep( i, 0, adj2[u].size() ){
			int v = adj2[u][i];
			g[v]--;
			if( !g[v] ) q.push(v);
		}
	}
	return 1;
}

int main(){
	int n, m;
	while( scanf("%d%d", &n, &m ) != EOF ){
		init(n);
		rep( i, 0, m ){
			scanf("%d%d", &u[i], &v[i] );
			u[i]--, v[i]--;
			adj[ u[i] ].pb( v[i] );
		}
		rep( i, 0, n ){
			if( num[i] == -1 ) tarjanScc(i);
		}
		rep( i, 0, m ){
			int w = scc[ u[i] ], x = scc[ v[i] ];
			if( w != x ){
				adj2[w].pb(x);
				g[x]++;
			}
		}
		if( top_sort() ) printf("Bolada\n");
		else printf("Nao Bolada\n");
	}
}

