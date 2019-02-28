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
	int a, b, c, ans;
	while( cin >> a >> b >> c ){
		ans = 0;
		int aa = min( a, min( b, c ) );
		int cc = max( a, max( b, c ) );
		int bb = a + b + c - aa - cc;
		if( aa + 200 > bb ) ans += ( aa + 200 - bb ) * 100;
		if( bb + 200 > cc ) ans += ( bb + 200 - cc ) * 100;
		printf("%d\n", ans );
	}
}

