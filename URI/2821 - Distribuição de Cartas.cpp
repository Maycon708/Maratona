#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int C( char *c ){
	if( c[0] == 'A' ) return 1;
	if( c[0] == 'J' ) return 11;
	if( c[0] == 'Q' ) return 12;
	if( c[0] == 'K' ) return 13;
	return atoi(c);
}

int main(){
	int n, m, v[100];
	char c[4];
	scanf("%d%d", &n, &m );
	rep( i, 0, n ){
		scanf("%s", c );
		v[i] = C(c);
	}
	int lo = 0, hi = 1300, mid;
	while( lo < hi ){
		mid = (lo+hi)/2;
		int sum = 0, cnt = 1;
		rep( i, 0, n ){
			if( sum + v[i] > mid ){
				sum = 0;
				cnt++;
			}
			sum += v[i];
		}
		if( cnt > m ) lo = mid+1;
		else hi = mid;
	}
	int mx = 0, sum = 0, cnt = 0;
	rep( i, 0, n ){
		if( sum + v[i] > hi ){
			mx = max( mx, cnt );
			cnt = sum = 0;
		}
		sum += v[i];
		cnt++;
	}
	mx = max( mx, cnt );
	printf("%d %d\n", mx, hi );
}
