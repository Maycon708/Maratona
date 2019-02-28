#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	int t, a, b;
	while( scanf("%d%d%d", &t, &a, &b ) != EOF && t ){
		int l = sqrt(t);
		int mmc = a/__gcd(a, b)*b;
		set<int> st;
		for( int i = 1; i <= t; i++ ){
			if( t%i ) continue;
			int x = t/i;
			if( mmc/__gcd(mmc, i) * i  == t ) st.insert(i);
			if( mmc/__gcd(mmc, x) * x  == t ) st.insert(x);
		}
		for( auto x : st ){
			if( x != *st.begin() ) printf(" ");
			printf("%d", x );
		}
		printf("\n");
	}
}

