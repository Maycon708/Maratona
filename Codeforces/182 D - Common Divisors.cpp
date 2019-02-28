#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

int main(){
	string a, b;
	
	cin >> a >> b;
	int t1 = a.size(), t2 = b.size();
	vector<int> div;
	rep( i, 1, min(t1, t2)+1 ){
		if( t1%i == 0 && t2%i == 0 ) div.pb(i);
	}
	int cnt = 0;
	for( auto x : div ){
		if( a.substr(0, x) != b.substr(0, x) ) continue;
		bool check = 1;
		for( int i = x; check && i < t1; i+= x ) check = a.substr(i, x) == b.substr(0, x);
		for( int i = x; check && i < t2; i+= x ) check = b.substr(i, x) == a.substr(0, x);
		cnt += check;
	}
	cout << cnt << "\n";
	
}
