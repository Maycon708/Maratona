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
	int n;
	while( cin >> n ){
		if( !n ) break;
		string a, b, c;
		map<string, int> mp;
		int cnt = 0, e[1000], s[1000];
		while( n-- ){
			cin >> a >> c >> b;
			if( !mp.count(a) ) mp[a] = cnt, s[cnt] = e[cnt] = 0, cnt++;
			if( !mp.count(b) ) mp[b] = cnt, s[cnt] = e[cnt] = 0, cnt++;
			s[mp[a]]++;
			e[mp[b]]++;
		}
		bool notF = 0, notR = 0;
		rep( i, 0, cnt ){
			if( s[i] > 1 ) notF = 1;
			if( e[i] > 1 ) notR = 1;
		}
		if( notF ) printf("Not a function.\n");
		else if( notR ) printf("Not invertible.\n");
		else printf("Invertible.\n");
	}
}

