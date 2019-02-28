#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

const int N = 1e5+10;
const int mod = 1e9+7;

int main(){
	
	int n, k, a, b;
	int dp[N];
	
	scanf("%d%d", &n, &k );
	
	for( int i = 0; i < k; i++ ) dp[i] = 1;
	for( int i = k; i < N; i++ ) dp[i] = ( dp[i-1] + dp[i-k] )%mod;
	dp[0] = 0;
	for( int i = 1; i < N; i++ ) dp[i] = ( dp[i] + dp[i-1] )%mod;
	
	
	while( n-- ){
		scanf("%d%d", &a, &b );
		printf("%d\n", (dp[b] - dp[a-1] +mod)%mod );
	}
}
