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

int n, k, v[10100];

int bb(){
	int ini = 1, fim = 10000;
	while( ini < fim ){
		int mid = ( ini + fim + 1 ) >> 1;
		int ans = 0;
		rep( i, 0, n ){
			ans += ( v[i]/mid );
		}
		if( ans < k ) fim = mid-1;
		else ini = mid;
	}
	return ini;
}

int main(){
	while( scanf("%d", &k ) != EOF ){
		scanf("%d", &n );
		rep( i, 0, n ) scanf("%d", &v[i] );
		printf("%d\n", bb() );
	}
}

