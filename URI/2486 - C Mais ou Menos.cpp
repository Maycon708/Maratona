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
	map<string, int> mp;
	mp["suco de laranja"] = 120;
	mp["morango fresco"] = 85;
	mp["mamao"] = 85;
	mp["goiaba vermelha"] = 70;
	mp["manga"] = 56;
	mp["laranja"] = 50;
	mp["brocolis"] = 34;
	int t, q;
	string s;
	while( cin >> t && t ){
		int ans = 0;
		rep( i, 0, t ){
			scanf("%d ", &q );
			getline( cin, s );
			ans += q * mp[s];
		}
		if( ans < 110 ) printf("Mais %d mg\n", 110 - ans );
		else if( ans > 130 ) printf("Menos %d mg\n", ans - 130 );
		else printf("%d mg\n", ans );
	}
}

