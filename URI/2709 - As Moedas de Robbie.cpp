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

bool isPrime( int n ){
//	if( n < 2 ) return 0;
	int s = sqrt(n);
	rep( i, 2, s+1 ) if( n%i == 0 ) return 0;
	return 1;
}

int main(){
	
	int n, k, v[100];
	
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			scanf("%d", &v[i] );
		}
		scanf("%d", &k );
		int sum = 0;
		for( int i = n-1; i >= 0; i-=k ){
			sum += v[i];
		}
		if( isPrime(sum) ) puts("You’re a coastal aircraft, Robbie, a large silver aircraft.");
		else puts("Bad boy! I’ll hit you.");
	}
	
	return 0;
}
