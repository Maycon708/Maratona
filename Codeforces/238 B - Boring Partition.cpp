#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	ll n, m, a[100100], v[100100];
	
	scanf("%I64d%I64d", &n, &m );
	rep( i, 0, n ) scanf("%I64d", &a[i] );
	if( n == 2 ){
		puts("0");
		puts("1 1");
		return 0;
	}
	rep( i, 0, n ) v[i] = a[i];
	sort( a, a+n );
	ll aa = abs( ( a[0]+a[1] ) - ( a[n-1] + a[n-2] ) );
	ll bb = abs( min( ( a[0]+a[1]+m ), ( a[1]+a[2] ) ) - max( (a[0]+a[n-1]+m), (a[n-1]+a[n-2]) ) );
	if( aa > bb ){
		printf("%I64d\n", bb );
		rep( i, 0, n ){
			if( v[i] == a[0] ) a[0] = -1, printf("2 ");
			else printf("1 ");
		}
	}
	else{
		printf("%I64d\n", aa );
		rep( i, 0, n ){
	 		printf("1 ");
		}
	}
	printf("\n");
}

