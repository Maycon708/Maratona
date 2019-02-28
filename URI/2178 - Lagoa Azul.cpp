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

int main(){
	int n, m, u, q;
	while( scanf("%d%d", &n, &m ) != EOF ){
		int ans = 0;
		rep( i, 0, n ){
			scanf("%d", &q );
			int cnt = 0, last = 0;
			rep( j, 0, q ){
				scanf("%d", &u );
				if( u < last ) cnt++;
				last = u;
			}
			if( last == 0 ) cnt--;
			ans = max( ans, cnt );
		}
		printf("%d\n", ans+1 );
	}
}

