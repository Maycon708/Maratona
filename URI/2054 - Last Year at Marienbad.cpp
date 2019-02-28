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
	int t, test = 1, u, sim = 0, nao = 0;
//	freopen("marienbad.in", "r", stdin );
//	freopen("marienbad2.sol", "w", stdout );
	scanf("%d", &t );
	while( t-- ){
		if( test != 1 ) printf("\n");
		int ans = 0, cnt = 0, aux = 0;
		rep( i, 0, 6 ){
			scanf("%d", &u );
			if( u > 1 ) aux = 1;
			ans ^= u;
		}
		if( !aux ) ans ^= 1;
		printf("Instancia %d\n", test++ );
		if( ans ) puts("sim");
		else puts("nao");
	}
}

