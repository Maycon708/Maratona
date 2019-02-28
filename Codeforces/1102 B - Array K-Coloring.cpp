#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int cnt[5005], found[5005];

int main(){
	int n, k, a[5005];
	scanf("%d%d", &n, &k );
	int aux = 0;
	rep( i, 0, n ){
		scanf("%d", &a[i] );
		cnt[a[i]]++;
		aux = max( aux, cnt[a[i]] );
		a[i] = cnt[a[i]];
	}
	if( aux > k ) puts("NO");
	else{
		puts("YES");
		for( int i = aux+1; i <= k; i++ ){
			rep( j, 0, n ){
				if( found[a[j]] == i ){
					a[j] = i;
					break;
				}
				found[a[j]] = i;
			}
		}
		rep( i, 0, n ) printf("%d ", a[i] );
	}
}

