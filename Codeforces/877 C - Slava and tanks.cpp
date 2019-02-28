#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	
	int n;
	while( cin >> n ){
		if( n == 2 ){
			printf("3\n2 1 2\n");
		}
		else{
			printf("%d\n", 3*(n/2) + (n&1) );
			for( int i = 2; i <= n; i += 2 ) printf("%d ", i );
			for( int i = 1; i <= n; i += 2 ) printf("%d ", i );
			for( int i = 2; i <= n; i += 2 ) printf("%d ", i );
			printf("\n");
		}		
	}
	
	
}
