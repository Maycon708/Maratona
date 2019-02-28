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
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;


int vis[MAXV], adj[MAXV];

int bfs( int ini ){
	queue < int > q;
	int cont = 0;
	q.push( ini );
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		cont++;
		q.push( adj[u] );
	}
	return cont;
}

int main(){
	
	int n, m, aux;
	char s[100];
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		rep( i, 0, n ){
			int u;
			scanf("%d", &u ); u--;
			adj[u] = i;
		}
		gets( s );
		gets( s );
		
		char resp[1000];
		strcpy( resp, s );
		
		rep( i, 0, n ){
			if( adj[i] == i ) continue;
			vector<int> aux;
			while( i != adj[i] ){
				aux.pb( adj[i] );
				swap( adj[i], adj[adj[i]]);
			}
			aux.pb(i);
			int k = m % aux.size();
			rep( j, 0, aux.size() ){
				resp[aux[j]] = s[aux[(j+k)%aux.size()]];
			}
		}
		printf("%s\n", resp );
	}
}
