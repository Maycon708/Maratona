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
	string s;
	while( getline( cin, s ) ){
		set<int> adj[55];
		set<int> :: iterator it;;
		vector<int> g(55, 0);
		stack<int> p;
		int u = 0;
		int n = 0;
		rep( i, 1, s.size()-1 ){
			n = max( n, u );
			if( s[i] >= '0' && s[i] <= '9' ) u *= 10, u += s[i] - '0';
			if( s[i] == '(' && u ) p.push(u), u = 0;
			if( s[i] == ')' ){
				if( u ) p.push(u); u = 0;
				int v = p.top();
				p.pop();
				if( p.empty() ) continue;
				adj[p.top()].insert(v);
				adj[v].insert(p.top());
				g[p.top()]++;
				g[v]++;
			}
		}
		bool aux = 0;
		rep( cnt, 0, n-1 ){
			if( cnt ) printf(" ");
			rep( i, 1, n+1 ){
				if( g[i] == 1 ){
					g[i]--;
					for( it = adj[i].begin(); it != adj[i].end(); it++ ){
						int v = *it;
						printf("%d", v );
						g[v]--;
						adj[v].erase( adj[v].find(i) );
					}
					break;
				}
			}
		}
		printf("\n");
	}
}

