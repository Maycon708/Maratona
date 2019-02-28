#include <bits/stdc++.h>
      
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 2110
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

int n, m, vis[MAXV], s[MAXV], ans;;
vector < int > adj[MAXV];
char c;

void dfs( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	ans += s[u];
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		dfs( v );
	}
	return;
}

int main() {
	while( scanf("%d%d", &n, &m ) != EOF ){
		ans = 0, n++;
		int aux = 0;
		rep( i, 0, n ){
			adj[i].clear();
			vis[i] = 0;
		}
		rep( i, 1, n ){
			scanf(" %c", &c );
			s[i] = ( c == 'B' );
			//debug( s[i] )
		}
		rep( i, 0, m ){
			int u = readInt();
			int v = readInt();
			adj[u].pb( v );
			adj[v].pb( u );
		}
		rep( i, 1, n ){
			if( !vis[i] ){
				dfs( i );
				if( ans&1 ){
					printf("N\n");
					aux = 1;
					break;
				}
			}
		}
		if( !aux ) printf("Y\n");
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
