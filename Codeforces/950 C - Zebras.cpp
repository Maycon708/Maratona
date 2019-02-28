#include <bits/stdc++.h>

#define INF 200*18+10
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

typedef int ll;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> tri;
 
int nxt[2][200200]; 
bool vis[200200]; 
 
int main(){
	
	char s[200200];
	
	while( scanf("%s", s ) != EOF ){
		int t = strlen(s);
		int o = 0, z = 0, cant = 0;
		rep( i, 0, t ){
			if( s[i] == '0' ) z++;
			else o++;
			if( s[i] == '1' && o > z ){
				cant = 1;
				break;
			}
		}
		o = z = 0;
		for( int i = t-1; i >= 0; i-- ){
			if( s[i] == '0' ) z++;
			else o++;
			if( s[i] == '1' && o > z ){
				cant = 1;
				break;
			}
		}
		if( cant ){
			puts("-1");
			continue;
		}
		set<int> st0, st1;
		int at;
		for( int i = t-1; i >= 0; i-- ){
			vis[i] = 0;
			if( s[i] == '0' ) st0.insert(i);
			else st1.insert(i);
		}
		vector< vector<int> > resp;
		vector<int> ans;
		rep( i, 0, t ){
			if( vis[i] ) continue;
			at = i;
			ans.pb(at);
			while(42){
				set<int> :: iterator it;
				if( s[at] == '0' ){
					it = st1.upper_bound(at);
					if( it == st1.end() ) break;
					at = *it;
					st1.erase(st1.find(at));
				}
				else{
					it = st0.upper_bound(at);
					if( it == st0.end() ) break;
					at = *it;
					st0.erase(it);
				}
				ans.pb(at);
				vis[at] = 1;
			}
			resp.pb(ans);
			ans.clear();
		}
		printf("%d\n", resp.size() );
		rep( i, 0, resp.size() ){
			printf("%d", resp[i].size() );
			rep( j, 0, resp[i].size() ) printf(" %d", resp[i][j]+1 );
			printf("\n");
		}
	}
	
}