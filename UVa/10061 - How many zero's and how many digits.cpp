	#include <bits/stdc++.h>
	
	#define INF 0x3F3F3F3F
	#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
	#define pb push_back
	#define debug(x) cout << #x << " = " << x << endl;
	#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
	#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
	#define all(S) (S).begin(), (S).end()
	#define F first
	#define S second
	#define mk make_pair
	
	using namespace std;
	
	typedef pair <int, int> ii;
	typedef long long int ll;
	
	int main(){
	
		ll a, b, mod;
		while( scanf("%lld%lld", &a, &b ) != EOF ){
			mod = b * b * b * b * b;
			ll cnt = 0, fat = 1;
			long double ans = 0;
			if( a == 0 ){
				printf("0 1\n");
				continue;
			}
			for( int i = 1; i <= a; i++ ){
				fat *= i;
				while( fat%b == 0 ) fat /= b, cnt++;
				fat %= mod;
				ans += ( log10(i)/log10(b) );
			}
			printf("%lld %lld\n", cnt, ll(ans)+1 );
		}
		
	}

