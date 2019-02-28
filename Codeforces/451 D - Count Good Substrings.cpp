#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

ll gt( ll n ){
	return n*(n-1)/2;
}

int main(){
	
	char s[100100];
	ll a[] = { 0, 0 }, b[] = { 0, 0 };
	
	scanf("%s", s );

	int t = strlen(s);
	
	rep( i, 0, t ){
		if( s[i] == 'a' ) a[i&1]++;
		else b[i&1]++;
	}
	
	printf("%I64d %I64d\n", a[0]*a[1] + b[0]*b[1], t + gt(a[0]) + gt(a[1]) + gt(b[0]) + gt(b[1]));
	
}
