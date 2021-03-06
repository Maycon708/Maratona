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

#define MAXN1 50000
#define MAXN2 50000
#define MAXM 1500000

using namespace std;

typedef long long int ll;

int C( char c ){
	if( c >= 'a' && c <= 'z' ) return c - 'a';
	return c - 'A';
}

int n1, n2, edges, last[MAXN1], PREV[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init( int _n1, int _n2 ){
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge( int u, int v ){
    head[edges] = v;
    PREV[edges] = last[u];
    last[u] = edges++;
}

void bfs(){
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for( int u = 0; u < n1; ++u ){
        if (!used[u])
        {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for( int i = 0; i < sizeQ; i++ ){
        int u1 = Q[i];
        for( int e = last[u1]; e >= 0; e = PREV[e] ){
            int u2 = matching[head[e]];
            if( u2 >= 0 && dist[u2] < 0 ){
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs( int u1 ){
    vis[u1] = true;
    for( int e = last[u1]; e >= 0; e = PREV[e] ){
        int v = head[e];
        int u2 = matching[v];
        if( u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2) ){
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
    for( int res = 0;;){
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for(int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if(!f)
            return res;
        res += f;
    }
}

inline bool S( char c ){
	if( c >= 'a' && c <= 'z' ) return 0;
	if( c >= 'A' && c <= 'Z' ) return 0;
	return 1;
}


int main(){
	int n, m, mat[1010][26], q;
	char c; string s;
	while( scanf("%d %d ", &n, &m ) != EOF ){
		memset( mat, 0, sizeof mat );
		init( n, m );
		rep( i, 0, n ){
			getline( cin, s );
			rep( j, 0, s.size() ){
				if( S( s[j] ) ) continue;
				int a = C( s[j] );
				mat[i][a]++;
			} 
		}
		rep( i, 0, m ){
			cin >> c >> q;
			int a = C( c );
			rep( j, 0, n ){
				if( mat[j][a] >= q )  addEdge( j, i );
			}
		}
		printf("%d\n", maxMatching() );
	}
}
