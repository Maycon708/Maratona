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

int n, a, bit[500050];

void update( int x ){
	for( int i = x; i <= n; i += (i&-i) ) bit[i]++;
}

int query( int x ){
	int ans = 0;
	for( int i = x; i > 0; i -= (i&-i) ) ans += bit[i];
	return ans;
}

int main(){
	scanf("%d", &n );
	rep( i, 0, n ){
		scanf("%d", &a );
		if( i ) printf(" ");
		printf("%d", a - query(a) );
		update(a);
	}
	printf("\n");
}
