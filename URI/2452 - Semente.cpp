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
	int m, n, v;
	while( cin >> m >> n ){
		int ans = 0, last = 0;
		rep( i, 0, n ){
			cin >> v;
			if( i ) ans = max( ans, ( v-last ) >> 1 );
			else ans = v-1;
			last = v;
		}
		ans = max( ans, m - last );
		printf("%d\n", ans );
	}
}

