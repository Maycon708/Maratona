#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int r[1912], c[2018];

int main(){
	int n, m, a, b;
	
	scanf("%d%d", &n, &m );
	while( m-- ){
		scanf("%d%d", &a, &b );
		r[a] = 1;
		c[b] = 1;
	}	
	
	int cnt = 0;
	rep( i, 2, n ){
		if( !r[i] ) cnt++;
		if( (r[i] || i != n-i+1) && !c[i] ) cnt++;
	}
	cout << cnt << "\n";
}

