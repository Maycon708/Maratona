#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		vector<int> v(n), sum(n, 0), ans(n, 0);
		rep( i, 0, n ) debug( v[i] )
		int S = 0;
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			S += v[i];
		}
		sum[0] = v[0], ans[0] = max( 0, v[0] );
		int resp = ans[0], aux = ans[0];
		rep( i, 1, n ){
			sum[i] = sum[i-1] + v[i];
			ans[i] = max( ans[i-1], sum[i] );
			resp = max( resp, ans[i] + S - sum[i] );
			aux = max( aux + v[i], 0 );
			resp = max( resp, aux );
		}
		printf("%d\n", resp );
	}
}

