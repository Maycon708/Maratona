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
	int k, v[20];
	
	while( scanf("%d", &k ) != EOF ){
		rep( i, 0, 12 ) scanf("%d", &v[i] );
		sort( v, v+12 );
		int aux = 0, cnt = 0;
		for( int i = 11; i >= 0 && aux < k; i--, cnt++ ) aux += v[i];
		if( aux < k ) cnt = -1;
		printf("%d\n", cnt );
	}
	
}

