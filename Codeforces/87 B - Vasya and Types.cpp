#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	int n;
	string op, a, b;
	
	map<string, int> mp;
	cin >> n;
	mp["void"] = 0;
	while( n-- ){
		cin >> op >> a;
		if( op == "typedef" ){
			cin >> b;
			int p = 0, e = 0;
			for( auto x : a ) p += (x == '*'), e += (x == '&');
			a = a.substr(e, a.size()-p-e );
			if( !mp.count(a) || mp[a] == -1 ) mp[b] = -1;
			else mp[b] = max( -1, mp[a] + p - e );
		}
		else{
			int p = 0, e = 0;
			for( auto x : a ) p += (x == '*'), e += (x == '&');
			a = a.substr(e, a.size()-p-e );
			if( !mp.count(a) || mp[a] == -1 || mp[a]+p-e < 0 ) puts("errtype");
			else{
				printf("void");
				rep( i, 0, mp[a]+p-e ) printf("*");
				printf("\n"); 
			}
		}
	}
}

