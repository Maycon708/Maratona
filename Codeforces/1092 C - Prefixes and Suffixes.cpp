#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	int n;
	string s[1111];
	vector<string> aux;
	char ans[1111];
	cin >> n;
	rep( i, 0, n*2-2 ){
		cin >> s[i];
	}
	rep( i, 0, 2*n-2 ){
		if( s[i].size() != 1 ) continue;
		rep( j, 0, 2*n-2 ){
			if( s[j].size() != n-1 ) continue;
			aux.pb( s[i]+s[j] );
			aux.pb( s[j]+s[i] );
		}
	}
	
	for( auto x : aux ){
		bool check = 1;
		int pref[110];
		rep( i, 1, n ) pref[i] = 0;
		rep( i, 0, 2*n-2 ){
			if( x.substr(0, s[i].size() ) == s[i] && !pref[s[i].size()] ) ans[i] = 'P', pref[s[i].size()] = 1; 
			else if( x.substr( n-s[i].size(), s[i].size() )== s[i] ) ans[i] = 'S';
			else{
				check = 0;
				break;
			}
		}
		ans[2*n-2] = '\0';
		if( check ){
			puts(ans);
			break;
		}
	}
}

