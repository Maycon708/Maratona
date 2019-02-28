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

int ans[1001010];

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		for( int i = 0; i < n-2; i+= 2 ) ans[i] = i + 3;
		for( int i = 3; i < n-1; i+= 2 ) ans[i] = i-1;
		ans[1] = 1;
		if( n&1 ) ans[n-1] = n-1;
		else ans[n-1] = n-2, ans[n-2] = n;
		rep( i, 0, n ) printf("%d%s", ans[i], i+1 == n ? "\n":" " );
	}
}

