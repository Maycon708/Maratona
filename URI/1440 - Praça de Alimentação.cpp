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
	int n, e[64803], d[64803], s[64803];
	string h;
	char op;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		vector< pair<string, char> > v;
		rep( i, 0, n ){
			cin >> h >> op;
			d[i] = e[i] = s[i] = 0;
			v.pb( mk( h, op ) );
		}
		sort( all(v) );
		for( int i = v.size() - 1; i >= 0; i-- ){
			if( v[i].S == '?' ) d[i] = 1;
			if( v[i].S == 'X' ) e[i] = 1;
			if( v[i].S == 'E' ) s[i] = 1;
			if( i+1 < v.size() ) d[i] += d[i+1], e[i] += e[i+1], s[i] += s[i+1];
		}
		int ans = 0, cnt = 0;
		rep( i, 0, v.size() ){
			if( v[i].S == 'E' ) cnt++;
			else if( v[i].S == 'X' ) cnt--;
			else if( v[i].S == '?' ){
				if( cnt + 1 + s[i] <= e[i] + d[i]-1 ) cnt++;
				else cnt--;
			}
			ans = max( cnt, ans );
		}
		printf("%d\n", ans );
	}
}

