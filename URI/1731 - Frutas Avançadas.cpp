#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

int main(){

	string a, b;
	while( cin >> a >> b ){
		int c = a.size();
		int d = b.size();
		int resp, j = 0;
		rep( i, 0, c ){
			if( a[i] == b[j] ) j++;
			if( j == d ) break;
		}
		resp = d - j;
		int k = 0;
		rep( i, 0, d ){
			if( b[i] == a[k] ) k++;
			if( k == c ) break;
		}
		if( c - k <= resp ) cout << b << a.substr( k, c - k );
		else cout << a << b.substr( j, d - j );
		printf("\n");
	}

}

