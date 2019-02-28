#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

bool cmp( int a, int b ){
	return a > b;
}

int main(){
	int n, k;
	ll b, a[100100], aux[100100];
	scanf("%d%d", &n, &k );
	scanf("%I64d", &b );
	rep( i, 0, n ) scanf("%d", &a[i] ), aux[i] = a[i];
	sort( aux, aux+n-1, cmp );
	map<int, int> mp;
	rep( i, 0, n ) if( !mp.count(aux[i]) ) mp[aux[i]] = i;
	ll sum = 0;
	rep( i, 0, k-1 ) sum += aux[i];
	rep( i, 0, n-1 ){
		ll aa;
		if( mp[a[i]] < k-1 ) aa = sum + aux[k-1];
		else aa = sum + a[i];
		if( aa > b ){
			printf("%d\n", i+1 );
			return 0;
		}
	}
	
	printf("%d\n", n );
}	

