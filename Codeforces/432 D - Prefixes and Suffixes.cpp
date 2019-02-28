#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

char s[100100];
int t, P[100100], cnt[100100];
int a[100100], b[100100];

void kmp(){
	t = strlen(s);
	P[0] = -1;
	rep( i, 1, t ){
		P[i] = P[i-1];
		while( P[i] >= 0 && s[P[i]+1] != s[i] ) P[i] = P[P[i]];
		if( s[P[i]+1] == s[i] ) P[i]++;
	}
	for( int i = t-1; i >= 0; i-- ){
		cnt[i]++;
		if( P[i] != -1 ) cnt[P[i]] += cnt[i];
	}
	int k;
	for( k = 0, t = t-1; t >= 0; k++, t = P[t] ){
		a[k] = t+1;
		b[k] = cnt[t];
	}
	printf("%d\n", k );
	for( int i = k; i > 0; i-- ){
		printf("%d %d\n", a[i-1], b[i-1] );
	}
}

int main(){
	scanf("%s", s );
	kmp();
}

