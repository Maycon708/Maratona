#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	ll t, op;
	scanf("%lld", &t );
	while( t-- ){
		string s; 
		cin >> s >> op;
		int n = s.size();
		ll ans = 0;
		reverse( all(s) );
		rep( i, 0, n ){
			ans <<= 1;
			if( s[i] == 'O' ) ans |= 1;
		}
		ans += op;
		rep( i, 0, n ){
			if( ans&1 ) putchar('O');
			else putchar('X');
			ans >>= 1;
		}
		putchar('\n');
	}
}

