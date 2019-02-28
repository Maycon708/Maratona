#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int tempo[100100], n, x, y;

int main(){
	scanf("%d", &n );
	rep( i, 1, n+1 ){
		scanf("%d%d", &x, &y );
		int l = sqrt(x), cnt = 0;
		rep( d1, 1, l+1 ){
			if( x%d1 ) continue;
			int d2 = x/d1;
			if( tempo[d1] < i-y ) cnt++;
			if( d2 != d1 && tempo[d2] < i-y ) cnt++;
			tempo[d1] = tempo[d2] = i;
		}
		printf("%d\n", cnt );
	}
}

