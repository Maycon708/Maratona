#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int n, l, a[202];
double p[202], pd[202][202][404];

double solve( int i, int w, int k ){
	k = max(  0, min( k, 400) );
	if( i == n ) return ( w >= l && k >= 200 );
	double &ans = pd[i][w][k];
	if( ans < -1 ){
		ans = solve( i+1, w, k ) * (1-p[i]) + solve( i+1, w+1, k + a[i] ) * p[i];
	}
	return ans;
}

int main(){
	int k;
	scanf("%d%d%d", &n, &l, &k );
	rep( i, 0, n ) scanf("%lf", &p[i] ), p[i]/= 100.0;
	rep( i, 0, n ) scanf("%d", &a[i] );
	memset( pd, -10, sizeof pd );
	printf("%.10f\n", solve(0, 0, 200+k) );
}

