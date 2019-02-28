#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 200010

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int solve( int *v, int k, int ini, int fim ){
	int ans = fim-ini, sum = 0;
	rep( i, ini, fim ){
		sum += v[i];
		if( sum == k ) ans--, sum = 0;
		else if( sum > k ) return INF;
	}
	if( fim - ans  <= ini+2 ) return INF;
	return ans;
}

int main(){

	int n, v[20000];
	while( scanf("%d", &n ) != EOF && n ){
		int sum = 0;
		vector<int> div;
		rep( i, 0, n ) scanf("%d", &v[i] ), sum += v[i], v[n+i] = v[i];
		int l = sqrt(sum);
		rep( i, 2, l+1 ){
			if( sum%i == 0 ){
				div.pb(i);
				div.pb(sum/i);
			}
		}
		int ans = INF;
		rep( i, 0, div.size() ){
			int aux = 0;
			if( sum/div[i] > n || sum/div[i] < 3 ) continue;
			rep( j, 0, n ){
				ans = min( ans, solve( v, div[i], j, j+n ) );
				aux += v[j];
				if( aux >= div[i] ) break;
			}
		}
		if( ans > n ) puts("-1");
		else printf("%d\n", ans );
	}

}
