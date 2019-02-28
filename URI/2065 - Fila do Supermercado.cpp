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

int main(){
	
	int n, m, t[11111], p[11111];
	set < ii > s;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ){
			scanf("%d", &t[i] );
			s.insert( ii( 0, i ) );		
		}
		rep( i, 0, m ){
			scanf("%d", &p[i] );
			ii a = *s.begin();
			s.erase( s.begin() );
			s.insert( ii( a.F + p[i] * t[a.S], a.S ) );
		}
		int resp = 0;
		while( !s.empty() ){
			ii a = *s.begin();
			resp = max( resp, a.F );
			s.erase( s.begin() );
		}
		printf("%d\n", resp );
	}
}
