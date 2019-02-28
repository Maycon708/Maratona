#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	int n, k, t;
	cin >> t;
	while( t-- ){
		cin >> n >> k;
		rep( i, 0, n ) printf("%c", char('a'+i%k) );
		printf("\n");
	}
}

