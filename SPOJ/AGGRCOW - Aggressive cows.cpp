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
	int t, n, k, v[100010];
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &k );
		rep( i, 0, n ) scanf("%d", &v[i] );
		sort( v, v+n );
		int i = 1, j = v[n-1] - v[0];
		while( i < j ){
			int mid = ( i + j +1 ) >> 1;
			int cnt = 0, last = -INF;
			rep( t, 0, n )
				if( v[t] >= last + mid ) cnt++, last = v[t];
			if( cnt < k ) j = mid-1;
			else i = mid;
		}
		printf("%d\n", i );
	}
}

