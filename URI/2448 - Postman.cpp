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
	int n, m, v[100010];
	while( cin >> n >> m ){
		rep( i, 0, n ) cin >> v[i];
		int ans = 0, last = 0, u;
		while( m-- ){
			cin >> u;
			int p = lower_bound( v, v+n, u ) - v;
			ans += abs( last - p );
			last = p;
		}
		printf("%d\n", ans );
	}
}

