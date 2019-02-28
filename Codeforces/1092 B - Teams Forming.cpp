#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	int n, v[111];
	cin >> n;
	rep( i, 0, n ) cin >> v[i];
	sort( v, v+n );
	int ans = 0;
	for( int i = 0; i < n; i+= 2 ){
		ans += (v[i+1]-v[i]);
	}
	cout << ans << endl;
}

