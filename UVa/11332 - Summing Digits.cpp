#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 450

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

string C( string s ){
	int ans = 0;
	rep( i, 0, s.size() ){
		ans += ( s[i] - '0' );
	}
	stringstream ss;
	ss << ans;
	ss >> s;
	return s;
}

int main(){
	
	string s;
	while( cin >> s && s != "0" ){
		while( s.size() != 1 ){
			s = C(s);
		}
		cout << s << endl;
	}
}
