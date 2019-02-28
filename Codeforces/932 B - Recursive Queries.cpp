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
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;


int f( int n ){
	int ans = 1;
	while( n ){
		int x = n%10;
		if( x ) ans *= x;
		n /= 10;
	}
	return ans;
}

int pre[1000010];
vector<int> cnt[10];

int main(){
	
	for( int i = 0; i < 1000010; i++ ){
		if( i < 10 ) pre[i] = i;
		else pre[i] = pre[f(i)];
		cnt[pre[i]].pb(i);
	}
	
	int q, r, l, k;
	scanf("%d", &q );
	while( q-- ){
		scanf("%d%d%d", &l, &r, &k );
		printf("%d\n", upper_bound(all(cnt[k]),r) - lower_bound(all(cnt[k]),l) );
	}
}
