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

#define N 10000100

int pd[N], memo[N], test = 1, n, k;

int solve( int u ){
	if( u > n ) return 0;
	if( u == 1 ) return ( n >= 4 ) ? k: 1;
	if( memo[u] == test ) return pd[u];
	memo[u] = test;
	if( u&1 ) pd[u] = 1 + solve(3*u+1);
	else pd[u] = 1 + solve(u/2);
	return pd[u];
}

int main(){
	while( scanf("%d%d", &n, &k ) != EOF ){
		int cnt = 0;
		for( int i = n; i > 0; i-- ){
			if( solve(i) >= k ) cnt++;
		}
		printf("%d\n", cnt );
		test++;
	}
}

