#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

string good;
int sig[3000010][26];
int cnt[3000010], k, ans, top;


void add( string s ){
	int x = 0;
	for( auto c : s ){
		if( !sig[x][c-'a']){
			cnt[top] = cnt[x] + (good[c-'a'] == '0');
			if( cnt[top] <= k ) ans++; 
			sig[x][c-'a'] = top++;
		}
		x = sig[x][c-'a'];
	}
}

int main(){
	
	string s;
	cin >> s >> good >> k;
	top = 1;
	rep( i, 0, s.size() ) add( s.substr( i, s.size()-i ) );
	cout << ans << endl;
}

