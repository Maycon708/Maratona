#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int cnt[100];

int main(){	
	int n; string s;
	cin >> n >> s;
	rep( i, 0, n ) cnt[s[i]-'0']++;
	if( cnt[0] > n/3 ){
		for( int i = n-1; i >= 0; i-- ){
			if( cnt[2] < n/3 && s[i] == '0' && cnt[0] > n/3 ){
				cnt[2]++;
				cnt[0]--;
				s[i] = '2';
			} 
			if( cnt[1] < n/3 && s[i] == '0' && cnt[0] > n/3 ){
				cnt[1]++;
				cnt[0]--;
				s[i] = '1';
			} 	
		}
	}
	if( cnt[1] > n/3 ){
		for( int i = n-1; i >= 0; i-- ){
			if( cnt[2] < n/3 && s[i] == '1' && cnt[1] > n/3 ){
				cnt[2]++;
				cnt[1]--;
				s[i] = '2';
			} 
		}
		for( int i = 0; i < n; i++ ){
			if( cnt[0] < n/3 && s[i] == '1' && cnt[1] > n/3 ){
				cnt[0]++;
				cnt[1]--;
				s[i] = '0';
			} 
		}
	}
	
	if( cnt[2] > n/3 ){
		for( int i = 0; i < n; i++ ){
			if( cnt[0] < n/3 && s[i] == '2' && cnt[2] > n/3 ){
				cnt[0]++;
				cnt[2]--;
				s[i] = '0';
			} 
		
			if( cnt[1] < n/3 && s[i] == '2' && cnt[2] > n/3 ){
				cnt[1]++;
				cnt[2]--;
				s[i] = '1';
			} 
		}
	}
	
	cout << s << "\n";
}

