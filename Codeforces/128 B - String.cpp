#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int ll;

int main(){
	string s;
	int k, n;
	set< pair<string, int> > pq;
	cin >> s >> k;
	n = s.size();
	rep( i, 0, n ) pq.insert( mp( s.substr(i, 1), i) );
	rep( i, 1, k ){
		if( pq.size() == 0 ){
			puts("No such line.");
			return 0;
		}
		string aux = pq.begin()->first;
		int t = pq.begin()->second;
		pq.erase( pq.begin() );
		if( t+1 < n ) pq.insert( mp( aux + s[t+1], t+1 ) )				;
	}
	cout << pq.begin()->first << "\n";
}

