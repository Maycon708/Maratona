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

int age[600], mp[600], mp2[600];
vector < int > adj[600];

void init( int n ){
	rep( i, 0, n ){
		adj[i].clear();
		mp[i] = i;
		mp2[i] = i;
	}
}

int bfs( int ini, int n ){
	int ans = INF;
	queue < int > q;
	bool vis[600];
	rep( i, 0, n ){
		vis[i] = 0;
	}
	q.push( ini );
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		if( u != ini ) ans = min( ans, age[mp2[u]] );
		rep( i, 0, adj[u].size() ){
			q.push( adj[u][i] );
		}
	}
	return ans;
}

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		int m = readInt();
		int c = readInt();
		init( n );
		rep( i, 0, n ) age[i] = readInt(), mp[i] = i;
		while( m-- ){
			int x = readInt()-1;
			int y = readInt()-1;
			adj[y].pb(x);
		}
		while( c-- ){
			char op;
			scanf(" %c", &op );
			switch (op){
				case 'T':{
					int u = readInt()-1;
					int v = readInt()-1;
					swap( mp[u], mp[v] );
					mp2[ mp[u] ] = u;
					mp2[ mp[v] ] = v;
					break;
				}
				case 'P':{
					int u = readInt()-1;
					int v = bfs( mp[u], n );
					if( v == INF ) printf("*\n");
					else printf("%d\n", v );
					break;
				}
			}
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

