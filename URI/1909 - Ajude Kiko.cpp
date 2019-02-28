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

int mmc( int a, int b ){
	return a * ( b / __gcd( a, b ) );
}

int main(){
	
	int n, t, u;
	while( scanf("%d%d", &n, &t ) != EOF ){
		if( !n && !t ) break;
		int m = 1;
		map < int, int > mp;
		rep( i, 0, n ){
			scanf("%d", &u );
			m = mmc( m, u );
			mp[u] = 1;
		}
		if( t%m ){
			printf("impossivel\n");
			continue;
		}
		int resp = -1;
		rep( i, 2, t+1 ){
			if( mp.count( i ) || t%i ) continue;
			u = mmc( i, m );
			if( u == t ){ 
				resp = i;
				break;
			}
		}
		if( resp != -1 ) printf("%d\n", resp );
		else printf("impossivel\n");
	}
}

