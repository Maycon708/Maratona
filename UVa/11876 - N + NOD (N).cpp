#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 450

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int div( int n ){
	int t = sqrt(n);
	int ans = 0;
	rep( i, 1, t+1 ){
		if( n%i == 0 ) ans += 2;
	}
	if( t*t == n ) ans--;
	return ans;
}

int main(){
	int n = 1, t, a, b, test = 1;
	vector<int> v;
	while(n <= 1000000){
		v.pb(n);
		n += div(n);
	}
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &a, &b );
		printf("Case %d: %ld\n", test++, upper_bound( all(v), b ) - lower_bound( all(v), a ) ); 
	}
}
