#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

const int mod = 1e9+7;
int pd[2002][2002], n;

int solve( int i, int k ){
	if( !k ) return 1;
	int &ans = pd[i][k];
	if( ans == -1 ){
		ans = 0;
		for( int j = i; j <= n; j += i ){
			ans = ( ans + solve(j, k-1) )%mod;
		}
	}
	return ans;
}

int main(){
	int k;
	cin >> n >> k;
	memset( pd, -1, sizeof pd );
	int ans = 0;
	rep( i, 1, n+1 ){
		ans = ( ans + solve( i, k-1 ) )%mod;
	}
	cout << ans << "\n";
}
