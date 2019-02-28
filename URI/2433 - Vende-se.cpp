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
	int n, k, aux;
	while( cin >> n >> k ){
		deque<int> d;
		rep( i, 0, n ){
			cin >> aux;
			d.pb(aux);
		}
		sort( all(d) );
		int u = n-k-1;
		int ans = 1 << 30;
		rep( i, 0, d.size() - u ){
			ans = min( ans, d[i+u] - d[i] );
		}
		printf("%d\n", ans );
	}
}

