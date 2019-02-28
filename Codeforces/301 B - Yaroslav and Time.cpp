#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int n, d, a[100], x[100], y[100], mx[100];

bool check( int kk ){
	memset( mx, -1, sizeof mx );
	mx[0] = kk;
	
	rep( i, 0, n ){
		rep( j, 0, n ){
			rep( k, 0, n ){
				int aux = mx[k] - ( abs(x[j]-x[k]) + abs(y[j]-y[k]) )*d;
				if( aux < 0 || j == k ) continue;
				mx[j] = max( mx[j], a[j] + aux );
			}
		}
	}
	return mx[n-1] >= 0;
}

int main(){
	
	scanf("%d%d", &n, &d );
	rep( i, 1, n-1 ) scanf("%d", &a[i] );
	rep( i, 0, n ) scanf("%d%d", &x[i], &y[i] );
	int lo = d, hi = 50000000, mid, ans;
	while( lo <= hi ){
		mid = (lo+hi)/2;
		if( check(mid) ){
			ans = mid, hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
	cout << ans << "\n";
	
}

