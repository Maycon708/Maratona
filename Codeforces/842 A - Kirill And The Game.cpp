#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll l, r, x, y, k;
	while( scanf("%lld%lld%lld%lld%lld", &l, &r, &x, &y, &k ) != EOF ){
		bool aux = 0;
		for( ll i = x; i <= y; ++i ){
			if( i * k >= l && i * k <= r ){
				aux = 1;
				break;
			}
			if( i*k > r ) break;
		}	
		if( aux ) puts("YES");
		else puts("NO");
	}
}