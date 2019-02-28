#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	string s;
	cin >> s;
	s.pb('X');
	int ini = 0, ans = 0;
	while( s[ini] == 'F' ) ini++;
	rep( i, ini, s.size() ){
		if( s[i] == 'F' ) ans = max( ans+1, i-ini ), ini++; 
	}
	cout << ans << "\n";
}

