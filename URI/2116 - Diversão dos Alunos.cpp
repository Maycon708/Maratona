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

using namespace std;

typedef long long int ll;

int C( char c ){
	if( c >= 'a' && c <= 'z' ) return c - 'a';
	return c - 'A';
}


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

inline bool S( char c ){
	if( c >= 'a' && c <= 'z' ) return 0;
	if( c >= 'A' && c <= 'Z' ) return 0;
	return 1;
}


int main(){
	int n, m, mat[1010][26], q;
	char c; string s;
	while( cin >> n >> m ){
		cin.ignore();
		memset( mat, 0, sizeof mat );
		rep( i, 0, n ){
			adj[i].clear();
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
				if( mat[j][a] >= q )  adj[j].pb( i );
			}
		}
		printf("%d\n", fluxo_maximo( n, m ) );
	}
}
