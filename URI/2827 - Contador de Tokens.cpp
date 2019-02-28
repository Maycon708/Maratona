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
	string s, ans;
	int maior = 0;
	getline(cin, s);
	
	map<string, int> mp;
	rep( i, 0, s.size() ) s[i] = tolower(s[i]);
	rep( i, 0, s.size()-1 ) mp[s.substr(i, 2)]++;
	for( auto x : mp ){
		if( x.S > maior ) maior = x.S, ans = x.F;
	}	
	
	printf("%s:%d\n", ans.c_str(), maior );
	
}
