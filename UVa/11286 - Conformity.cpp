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
	int n;
	while( scanf("%d", &n ) != EOF && n){
		map<vector<int>, int> mp;
		int ans = 0;
		vector<int> cont(n+1, 0);
		rep( i, 0, n ){
			vector<int> v(5);
			rep( j, 0, 5 ){
				scanf("%d", &v[j] );
			}
			sort( all(v));
			mp[v]++;
			ans = max( ans, mp[v] );
			cont[mp[v]]++;
		}
		printf("%d\n", cont[ans] * ans );
	}
}
