#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

char mat[2002][2002];
int N[1002][1002];
int S[1002][1002];
int E[1002][1002];
int W[1002][1002];
char d[200002];
int v[100102];

int main(){
	int n, m, q;
	vector<ii> origins;
	
	scanf("%d%d", &n, &m );
	rep( i, 0, n ){
		scanf("%s", mat[i] );
		rep( j, 0, m ){
			if( mat[i][j] >= 'A' && mat[i][j] <= 'Z' ) origins.pb( ii(i, j) );
		}
	}
	
	rep( i, 0, n ){
		int last = -1;
		for( int j = 0; j < m; j++ ){
			if( mat[i][j] == '#' ) last = j;
			W[i][j] = last;
		}
		last = m;
		for( int j = m-1; j >= 0; j-- ){
			if( mat[i][j] == '#' ) last = j;
			E[i][j] = last;
		}
	}
	
	rep( j, 0, m ){
		int last = -1;
		for( int i = 0; i < n; i++ ){
			if( mat[i][j] == '#' ) last = i;
			N[i][j] = last;
		}
		last = n;
		for( int i = n-1; i >= 0; i-- ){
			if( mat[i][j] == '#' ) last = i;
			S[i][j] = last;
		}
	}
	
	scanf("%d", &q );
	rep( i, 0, q ) scanf(" %c%d", &d[i], &v[i] );
	
	set<char> st;
	for( auto x : origins ){
		int i = x.F, j = x.S;
		char aux = mat[i][j];
		bool check = 1;
		rep( k, 0, q ){
			if( d[k] == 'W' ){
				if( W[i][j] >= j-v[k] ){
					check = 0;
					break;
				}
				j -= v[k];
			}
			if( d[k] == 'E' ){
				if( E[i][j] <= j+v[k] ){
					check = 0;
					break;
				}
				j += v[k];
			}
			if( d[k] == 'S' ){
				if( S[i][j] <= i+v[k] ){
					check = 0;
					break;
				}
				i += v[k];
			}
			if( d[k] == 'N' ){
				if( N[i][j] >= i-v[k] ){
					check = 0;
					break;
				}
				i -= v[k];
			}
			if( i < 0 || i >= n || j < 0 || j >= m ) debug2( i, j )
		}
		if( check ) st.insert(aux); 
	}
	for( auto x : st ) printf("%c", x );
	if( st.empty() ) puts("no solution");
}

