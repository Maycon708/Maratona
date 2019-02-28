#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	string s;
	cin >> s;
	int l = 0, r = s.size() -1, a = 0;
	for( ; l < s.size(); l++ ){
		if( !a && s[l] == '[' ) a++;
		if( a && s[l] == ':' ){
			a++;
			break;
		}
	}
	for( ; r > l; r-- ){
		if( a == 2 && s[r] == ']' ) a++;
		else if( a == 3 && s[r] == ':') a++;
		if( a > 3 && s[r] == '|' ) a++;
	}
	if( a < 4 ) puts("-1");
	else printf("%d\n", a );
}
