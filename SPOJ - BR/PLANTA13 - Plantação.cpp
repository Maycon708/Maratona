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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	int k, n, u;
	char C;
	vector < ll > v;
	while( scanf("%d%d", &k, &n ) != EOF ){
		v.clear();
		ll sum = 0, resp = 0;
		rep( i, 0, n ){
			scanf("%d", &u );
			v.pb( u );
			sum += u;
		}
		sort( all( v ) );
		int it = 0, c = 0, e = 0;
		rep( i, 0, k ){
			scanf(" %c", &C );
			if( C == 'E' ){
				if( c ) c--;
				else e++;
			}
			else c++;
			while( v[it] <= e && it < n ){
				it++; sum--;
			}
			if( C == 'C' ) sum += ( n - it );
			else sum -= ( n - it );
			resp += sum;
		}
		printf("%lld\n", resp );
	}

}

