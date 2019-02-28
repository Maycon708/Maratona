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

typedef pair <int, int> ii;
typedef long long int ll;

int main(){

	string s;
	while( cin >> s ){
		int a = s.size(), ans = s.size();
		for( int i = a-2; i >= 0; i-- ){
			int k = i, j = a-1;
			if( s[k] != s[j] ) continue;
			while( s[k] == s[j] && k >= 0 ) k--, j--;
			if( j <= i ) ans = min( ans, i+1 );
		}
		rep( i, 0, ans ) printf("%c", s[i] );
		printf("\n");
	}

	return 0;
}

