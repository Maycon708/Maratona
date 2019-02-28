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

ll v[1000100];

int main(){
	
	ll n, k, s, t;
	scanf("%lld", &t );
	while( t-- ){
		scanf("%lld%lld%lld", &n, &k, &s );
		v[0] = s;
		rep( i, 1, n ){
			v[i] = (1LL * v[i-1] * 1103515245 + 12345) % (2147483648LL);
		}
		deque<ll> d;
		rep( i, 0, k ){
			while( !d.empty() && v[i] >= v[d.back()] ) d.pop_back();
			d.push_back(i); 
		}
		ll sum = 0;
		rep( i, k, n ){
			sum += v[ d.front() ];
			while( !d.empty() && i-k >= d.front() ) d.pop_front();
			while( !d.empty() && v[i] >= v[d.back()] ) d.pop_back();
			d.push_back(i); 
		}
		sum += v[ d.front() ];
		printf("%lld\n", sum );
	}

}

