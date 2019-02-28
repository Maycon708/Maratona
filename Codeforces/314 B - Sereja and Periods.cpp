#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

ll cnt[50], cnt2[50];
ll mat[111][111], tempo[111][111];

int main(){
	int n, k;
	string a, b;
	
	cin >> n >> k;
	cin >> a >> b;
	
	for( auto x : a ) cnt[x-'a']++; 
	for( auto x : b ) cnt2[x-'a']++; 
	
	rep( i, 0, 26 ){
		if( cnt2[i]*k > cnt[i]*n  ){
			puts("0");
			return 0;
		}
	}
	ll cnt = 0, found = 0, aux = 0, ans = 0, j = 0, cycle, i;
	while( !found && cnt < n ){
		cnt++;
		for( i = 0; i < a.size(); i++ ){
			if( a[i] == b[j] ){
				if( tempo[i][j] ){
					found = j+1;
					cycle = cnt - tempo[i][j];
					aux = ans - mat[i][j];
					cnt = tempo[i][j];
					ans = mat[i][j];
					break;
				}
				tempo[i][j] = cnt;
				mat[i][j] = ans;
				j++;
				if( j == b.size() ) ans++, j = 0;
			}
		}
	}
	ans += ( n-cnt )/cycle * aux;
	
	
	n = ( n-cnt )%cycle;
	j = found-1;
	for( ; i < a.size(); i++ ){
		if( b[j] == a[i] ) j++;
		if( j == b.size() ) ans++, j = 0;
	}
	while( n-- ){
		for( int i = 0; i < a.size(); i++ ){
			if( b[j] == a[i] ) j++;
			if( j == b.size() ) ans++, j = 0;
		}
	}
	
	cout << ans/k << "\n";
}

