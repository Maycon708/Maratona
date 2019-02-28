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

string c[2][22];
map<string, int> mp[2];
bool ans;
int tam[2];

void solve( string s, int id ){
	if( mp[id].count(s) ) return;
	mp[id][s] = 1; 
	rep( i, 0, tam[id] ){
		string &tmp = c[id][i];
		if( s.size() == tmp.size() && s == tmp && !ans ){
			ans = 1;
			return;
		}
		if( s.size() < tmp.size() && s == tmp.substr(0, s.size()) && !ans ) solve(tmp.substr(s.size(), tmp.size()-s.size() ), 1-id);
		if( s.size() > tmp.size() && tmp == s.substr(0, tmp.size()) && !ans ) solve(s.substr(tmp.size(), s.size()-tmp.size() ), id);
	}
}

int main(){
	
	while( scanf("%d%d", &tam[0], &tam[1] ) != EOF ){
		rep( i, 0, 2 ){
			rep( j, 0, tam[i] ){
				cin >> c[i][j];
			}
			mp[i].clear();
		}
		ans = 0;
		rep( i, 0, tam[0] ) if( !ans ) solve(c[0][i], 1);
		if( ans ) puts("S");
		else puts("N");
	}
	
}
