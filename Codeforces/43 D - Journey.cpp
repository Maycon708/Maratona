#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	int n, m;
	cin >> n >> m;
	if( n%2 == 0 && m > 1 || m == 1 && n <= 2 ){
		printf("0\n");
		rep( i, 0, n ) printf("%d %d\n", i+1, 1 );
		for( int i = n; i > 0; i-- ){
			if( i&1 ) for( int j = m; j > 1; j-- ) printf("%d %d\n", i, j );
			else for( int j = 2; j <= m; j++ ) printf("%d %d\n", i, j );
		}
		printf("1 1\n");
	}
	else if( m%2 == 0 && n > 1 || n == 1 && m <= 2 ){
		printf("0\n");
		rep( i, 0, m ) printf("%d %d\n", 1, i+1 );
		for( int i = m; i > 0; i-- ){
			if( i&1 ) for( int j = n; j > 1; j-- ) printf("%d %d\n", j, i );
			else for( int j = 2; j <= n; j++ ) printf("%d %d\n", j, i );
		}
		printf("1 1\n");
	}
	else{
		printf("1\n%d %d 1 1\n", n, m );
		for( int i = 1; i <= n; i++ ){
			if( i&1 ) for( int j = 1; j <= m; j++ ) printf("%d %d\n", i, j );
			else for( int j = m; j >= 1; j-- ) printf("%d %d\n", i, j );
		}
		printf("1 1\n");
	}
}

