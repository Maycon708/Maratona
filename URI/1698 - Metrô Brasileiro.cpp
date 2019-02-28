#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

double matrix[20][20];

double mat_det(int n){
	int i, j, k;
	double ret = 1;
	for(i = 0 ; i < n ; i++){
		if( fabs(matrix[i][i]) < 1e-5 ){
			for( j = i + 1 ; j < n ; j++ ){
				if( !(fabs(matrix[j][i])<1e-5) ){
					swap( matrix[i], matrix[j] );
					ret *= -1;
					break;
				}
			}
		if( j == n )
			return 0;
		}
		double tmp = matrix[i][i];
		for( k = 0 ; k < n ; k++ )
			matrix[i][k] /= tmp;
		ret *= tmp;
		for( j = 0 ; j < n ; j++ ){
			if( j == i ) continue;
			tmp = matrix[j][i];
			for( k = 0 ; k < n ; k++ )
				matrix[j][k] -= matrix[i][k] * tmp;
		}
	}
	return ret;
}
ll count_spantree(vector<int> graph[], int size){
	int i, j;
	for( i = 0 ; i < size-1; i++ ){
		for( j = 0 ; j < size - 1 ; j++ ) 
			matrix[i][j] = 0;
		matrix[i][i] = graph[i].size();
		for( j = 0 ; j < graph[i].size() ; j++ ){
			if( graph[i][j] < size - 1 ){
				matrix[i][graph[i][j]]--;
			}
		}
	}
	return ll(round(mat_det(size - 1)));
}

int main(){
	
	int n, m, a, b;
	
	while( scanf("%d%d", &n, &m ) != EOF ){
		vector<int> adj[20], aux[20];
		rep( i, 0, m ){
			scanf("%d%d", &a, &b );
			adj[a].pb(b);
			adj[b].pb(a);
		}
		int g[20]; a = 0, b = 1;
		ll best = 0;
		rep( i, 0, n ){
			rep( j, i+1, n ){
				rep( k, 0, n ) g[k] = k, aux[k].clear();
				g[n-1] = j;
				g[j] = i;
				rep( k, 0, n ){
					rep( l, 0, adj[k].size() ){
						int v = adj[k][l];
						if( g[k] != g[v] ) 
							aux[g[k]].pb(g[v]);
					}
				}
				ll at = count_spantree(aux, n-1);
				if( at > best ){
					best = at;
					a = i, b = j;
				}
			}
		}
		printf("%d %d\n", a, b );
	}
	
	return 0;
}

