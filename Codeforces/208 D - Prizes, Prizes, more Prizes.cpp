#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	
	ll n, a[50], v[5], cnt[5];
	
	scanf("%I64d", &n );
	rep( i, 0, n ) scanf("%I64d", &a[i] );
	rep( i, 0, 5 ) scanf("%I64d", &v[4-i] ), cnt[i] = 0;
	ll x = 0;
	rep( i, 0, n ){
		x += a[i];
		rep( i, 0, 5 ) cnt[4-i] += x/v[i], x %= v[i];
	}
	rep( i, 0, 5 ) printf("%I64d ", cnt[i] );
	printf("\n%I64d\n", x );
}
