#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	int n, s, f, a;
	while( scanf("%d", &n ) != EOF ){
		deque<int> d;
		rep( i, 0, n ){
			scanf("%d", &a );
			d.pb(a);
		}
		scanf("%d%d", &s, &f );
		
		ll sum = 0, best;
		int id;
		rep( i, s-1, f-1 ){
			sum += d[i];
			id = 0;
		}
		best = sum;
		rep( i, 0, 2*n ){
			d.push_front(d[n-1]);
			sum += d[s-1];
			sum -= d[f-1];
			d.pop_back();
			if( sum > best || ( sum == best && (i+1)%n < id ) ){
				best = sum;
				id = (i+1)%n;
			}
		}
		printf("%d\n", id%n+1 );
	}	
}
