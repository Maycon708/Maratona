#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	int n, x, y, a[111], cnt = 0;
	scanf("%d%d%d", &n, &x, &y );
	rep( i, 0, n ){
		scanf("%d", &a[i] );
		if( a[i] <= x ) cnt++;
	}
	if( x > y ) printf("%d\n", n );
	else printf("%d\n", (cnt+1)/2 );
}

