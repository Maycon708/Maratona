#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugP(a) cout << "F" << " = " << a.first << " --- " << "S" << " = " << a.second << "\n";
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int MAXV = 1111;
vector <int> adj[MAXV];
int cor[MAXV];

bool ehbipartido( int ini ){
    queue < int > q;
    q.push(ini);
    cor[ini] = 0;
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        int tam = adj[u].size();
        rep( i, 0, tam ){
            int v = adj[u][i];
            if( cor[v] == -1 ){
                cor[v] = 1  - cor[u];
                q.push(v);
            }
            else if( cor[v] == cor[u] )
                return false;
        }
    }
    return true;        
}
 
int main(){
	
	int n, aux, t = 1, m, u, v;
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		
		rep( i, 0, n+1 ){
            adj[i].clear();
            cor[i] = -1;
        }
        while( m-- ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		bool aux = 1;
		rep( i, 1, n+1 ){
			if( cor[i] == -1 ) aux *= ehbipartido( i );
		}
		
		printf("Instancia %d\n", t++ );
		if( aux ) printf("sim\n");
        else printf("nao\n");
        printf("\n");
	}	
	
	return 0;
}

