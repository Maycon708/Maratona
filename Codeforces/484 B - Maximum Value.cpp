#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int maior[2000020], v[200010];

int main(){
	int n;
	scanf("%d", &n);
	rep( i, 0, n ) scanf("%d", &v[i] );
	sort( v, v+n );
	int j = 0, last = 0, lim = 2*(v[n-1]+1);
	rep( i, 0, lim ){
		while( j < n && i > v[j] ) 
			last = v[j++];
		maior[i] = last;
	}
	int ans = 0; last = 1;
	rep( i, 0, n-1 ){
		int x = v[i];
		if( x == last ) continue;
		for( j = x+x; j < lim; j += x ){
			ans = max( ans, maior[j]%x );
		}
		last = x;
	}
	cout << ans << endl;
}

