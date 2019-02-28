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

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

vector<int> adj[1100];
int match[10000];
bool vis[10000];

int aug( int v ){
	if( vis[v] ) return 0;
	vis[v] = true;
    int tam = adj[v].size();
    rep( j, 0, tam ){
        int r = adj[v][j];
        if( match[r] == -1 || aug(match[r]) ){
            match[r] = v;
            return 1;
        }       
    }    
	return 0;
}   

int fluxo_maximo( int q1, int q2 ){
	int V = q1 + q2;
	rep( i, 0, V ) match[i] = -1;
	int mcmb = 0;
	rep( i, 0, q1 ){
        rep( j, 0, q1 ) vis[j] = false;
        mcmb += aug(i);
    }       
	return mcmb;
}


int main(){

	int n, q, u, aux;
	while( scanf("%d%d", &n, &q ) != EOF ){
		set < int > st[111];
		set < int > :: iterator it;
		bool a = 0;
		rep( i, 0, n ){
			scanf("%d", &u );
			if( u == n ) a = 1;
			rep( j, 0, u ){
				scanf("%d", &aux );
				st[i].insert( aux );
			}
		}
		while( q-- ){
			scanf("%d", &u );
			if( !u ){
				if( a ) printf("N\n");
				else printf("Y\n");	
			}
			else{
				rep( i, 0, n ) adj[i].clear();
				rep( j, 0, u ){
					scanf("%d", &aux );
					rep( i, 0, n ){
						it = st[i].find( aux );
						if( it != st[i].end() ) adj[i].pb(j);
					}
				}
				int ans = fluxo_maximo( n, u );
				if( ans == u ) printf("Y\n");
				else printf("N\n");
			}
		}
	}

}


