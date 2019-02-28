#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){

	string s, a;
	while( getline( cin, s ) ){
		unordered_map<string, vector<int> > mp;
		stringstream ss;
		ss << s;
		int ans = 0;
		while( ss >> s ){
			mp[s].pb(ans);
			ans += ( s.size() + 1 );
		}
		scanf("%d", &ans );
		rep( i, 0, ans ){
			cin >> a;
			if( mp.count(a) ){
				rep( i, 0, mp[a].size() ) printf("%d%s", mp[a][i], i+1 == mp[a].size() ? "\n" : " " );
			}
			else puts("-1");
		}
		cin.ignore();
	}	
	
}
