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

int main(){
	ll n, v;
	while( cin >> n && n){
		priority_queue<int> pq;
		rep( i, 0, n ){
			cin >> v;
			pq.push( -v );
		}
		ll ans = 0;
		while( pq. size() > 1 ){
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			ans += ( a + b );
			pq.push( a+b );
		}
		printf("%lld\n", -ans );
	}
}
