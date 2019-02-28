#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	int n;
	double p[111];
	cin >> n;
	rep( i, 0, n ) cin >> p[i];
	sort( p, p+n );
	double ans = p[n-1], a = p[n-1], b = 1-p[n-1];
	for( int i = n-2; i >= 0; i-- ){
		a *= (1-p[i]);
		b *= p[i];
		a = a+b;
		b = b/p[i]*(1-p[i]);
		ans = max( ans, a );
	}
	printf("%.10f\n", ans );
}

