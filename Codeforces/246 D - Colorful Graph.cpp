#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

map< int, set<int> > st;

int main(){
	
	int n, m, c[100100], a, b;
	int mx = -1, id = INT_MAX;
	
	scanf("%d%d", &n, &m );
	rep( i, 0, n ){
		scanf("%d", &c[i] );
		id = min( id, c[i] );
	}
	while( m-- ){
		scanf("%d%d", &a, &b );
		a = c[a-1], b = c[b-1];
		if( a != b ){
			st[a].insert(b);
			st[b].insert(a);
		}
	}
	for( auto x : st ){
		if( (int)x.second.size() > mx ){
			mx = x.second.size();
			id = x.first;
		}
	}
	cout << id << endl;
	
}
