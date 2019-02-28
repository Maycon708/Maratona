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

int n, k, dist[30][30], cost[440][440], pd[440][440];
char s[440];

int solve( int p, int k ){
	if( !k ) return cost[p][n-1];
	if( p == n ) return 0;
	int &ans = pd[p][k];
	if( ans == -1 ){
		ans = INF;
		rep( i, p, n ){
			ans = min( ans, solve(i+1, k-1) + cost[p][i] );
		}
	}
	return ans;
}

int main(){
	
	scanf("%d%d", &n, &k );
	scanf("%s", s );
	
	rep( i, 0, 26 )
		rep( j, 0, 26 )
			dist[i][j] = min( abs(j-i), 26-abs(j-i) );
	
	rep( i, 0, n ){
		cost[i][i] = 0;
		rep( j, i+1, n ){
			int cnt = 0;
			rep( l, i, j+1 ){
				cnt += dist[s[l]-'a'][s[j-l+i]-'a'];
			}
			cost[i][j] = cost[j][i] = cnt >> 1;
		}
	}
	memset( pd, -1, sizeof pd );
	printf("%d\n", solve(0, k-1) );
}
