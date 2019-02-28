#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	int t, n, m, k;
	ii v[1111], w[1111];
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d%d", &n, &m, &k );
		rep( i, 0, n ) scanf("%d%d", &v[i].F, &v[i].S ); 
		rep( i, 0, m ) scanf("%d%d", &w[i].F, &w[i].S ); 
		multiset<int> dist;
		multiset<int> :: iterator it;
		rep( i, 0, n ){
			rep( j, 0, m ){
				int aux = ( abs( v[i].F - w[j].F ) + abs( v[i].S - w[j].S ) );
				dist.insert(aux);
				if( dist.size() <= k ) continue;	
				dist.erase( --dist.end() );
			}
		}
		int ans = 0;
		for( it = dist.begin(); it != dist.end(); it++ ){
			ans += *it;
		}
		printf("%d\n", ans );
	}
	
}

