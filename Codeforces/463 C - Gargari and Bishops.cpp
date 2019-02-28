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

ll mat[2017][2017];
ll d1[4034], d2[4034];

int main(){
	ll n;
	while( scanf("%lld", &n ) != EOF ){
		rep( i, 0, 4034 ) d1[i] = d2[i] = 0;
		rep( i, 0, n ){
			rep( j, 0, n ){
				scanf("%lld", &mat[i][j] );
				d1[i-j+n] += mat[i][j];
				d2[i+j] += mat[i][j];
			}
		}
		ll a = -INF, b = -INF;
		ii p1, p2;
		rep( i, 0, n ){
			rep(j, 0, n ){
				if( (i+j)&1 ){
					ll t = d1[i-j+n] + d2[i+j] - mat[i][j];
					if( t > a ){
						a = t;
						p1 = ii( i+1, j+1 );
					}
				}
				else{
					ll t = d1[i-j+n] + d2[i+j] - mat[i][j];
					if( t > b ){
						b = t;
						p2 = ii( i+1, j+1 );
					}
				}
				
			}
		}
		if( p1 > p2 ) swap( p1, p2 );
		printf("%lld\n", a + b );
		printf("%d %d %d %d\n", p1.F, p1.S, p2.F, p2.S );
		
	}
}
