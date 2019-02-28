#include <bits/stdc++.h>
        
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debug3(x,y,z) cout << #x << " = " << x << " --- " << #y << " " << y << " --- " << #z << " " << z << "\n";
#define debugV(a, b) { for( int i = 0; i < b; i ++ ) cout << a[i] << " "; cout << endl; }
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
        
using namespace std;
        
typedef long long ll;
typedef pair < int, int >  ii;

inline bool cmp ( ii a, ii b ){
	if( a.F > b.F ) return 1;
	if( a.F < b.F ) return 0;
	return a.S < b.S;
}

int main(){
	int g, p, m[111][111], s, k, v[111], aux, t[111];
	vector < ii > V;
	while( scanf("%d%d", &g, &p) != EOF ){
		if( !g && !p ) break;
		rep( i, 0, g ){
			rep( j, 0, p ){
				scanf("%d", &m[i][j] );
			}
		}
		scanf("%d", &s );
		while( s-- ){
			V.clear();		
			aux = 0;
			rep( i, 0, p )
				t[i] = 0;
			scanf("%d", &k );
			rep( i, 0, k ){
				scanf("%d", &v[i] );
			}
			rep( i, 0, g ){
				rep( j, 0, p ){
					if( m[i][j] <= k ) t[j] += v[ m[i][j] -1 ];
				}
			}
			rep( j, 0, p ){
				V.pb( ii( t[j], j+1 ) );
			}
			sort( all(V), cmp );
			rep( i	, 0, V.size() ){
				if( aux ){
					if( V[i] < V[i-1] ) break;
					printf(" ");
				}
				else aux = 1;
				printf("%d", V[i].S );
			}
			printf("\n");
		}
		
	}
}
