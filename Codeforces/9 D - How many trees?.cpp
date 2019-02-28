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

int H;
ll pd[40][40][40][2];

ll solve( int i, int j, int h, int op ){
	
	if( i == j ){
		if( op ) return h >= H;
		return h < H;
	}
	
	ll &ans = pd[i][j][h][op];
	if( ans == -1 ){
		ans = solve( i+1, j, h+1, op );
		for( int k = i+1; k < j; k++ ){
			ll a = solve( i, k-1, h+1, 1 );
			ll b = solve( i, k-1, h+1, 0 );
			ll c = solve( k+1, j, h+1, 1 );
			ll d = solve( k+1, j, h+1, 0 );
			if( op ) ans += a*c + a*d + b*c;
			else ans += b*d;
		}
		ans += solve( i, j-1, h+1, op );
	}
	return ans;
}

int main(){
	int n;
	scanf("%d%d", &n, &H ); H--;
	memset( pd, -1, sizeof pd );
	cout << solve(1, n, 0, 1) << "\n";
}
