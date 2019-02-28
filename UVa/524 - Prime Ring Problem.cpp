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

int prime[] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 };
int ans[20], n;

void back( int p, int mask, int at ){
	if( p == n ){
		if( prime[at+1] ) rep( i, 0, n ) printf("%d%s", ans[i], (i+1==n)? "\n":" ");
		return;
	}
	for( int i = 1; i <= n; i++ ){
		if( !(mask&(1<<i)) && prime[i+at] ) ans[p] = i, back(p+1, mask|(1<<i), i );
	}
} 
	
int main(){

	int test = 1;
	while( scanf("%d", &n ) != EOF ){
		ans[0] = 1;
		if( test != 1 ) printf("\n");
		printf("Case %d:\n", test++ );
		back(1, 2, 1);
	}
	
	 	
	return 0;
}
