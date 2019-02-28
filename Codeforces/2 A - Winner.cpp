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
	int n, p[1001];
	string s[1001];
	while( scanf("%d", &n ) != EOF ){
		map<string, int> mp, mp2;
		map<string, int> :: iterator it;
		int ans = 0;
		rep( i, 0, n ){
			cin >> s[i] >> p[i];
			mp[s[i]] += p[i];
		}
		for( it = mp.begin(); it != mp.end(); it++ ) ans = max( ans, it->S );
		rep( i, 0, n ){
			mp2[s[i]] += p[i];
			if( mp2[s[i]] >= ans && mp[s[i]] == ans ){
				printf("%s\n", s[i].c_str() );
				break;
			}
		}
	}
}

