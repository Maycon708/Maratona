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

struct aux{
	int l, k;
	bool ok;
	aux(){};
	aux( int _l, int _k, bool _ok ){
		l = _l, k = _k, ok = _ok;
	}
};

int main(){
	int n, v[100010];
	while( scanf("%d", &n ) != EOF ){
		
		map<int, aux> mp;
		map<int, aux> :: iterator it;
		
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			if( !mp.count( v[i] ) ){
				mp[v[i]] = aux( i, 0, 1 );
				continue;
			}
			aux a = mp[v[i]];
			if( !a.k ) a.k = i - a.l;
			else if( a.k != i - a.l ) a.ok = 0; 
			a.l = i; 
			mp[v[i]] = a;
		}
		int cnt = 0;
		for( it = mp.begin(); it != mp.end(); it++ ){
			if( !it -> S.ok ) continue;
			cnt++;
		}
		printf("%d\n", cnt );
		for( it = mp.begin(); it != mp.end(); it++ ){
			if( !it -> S.ok ) continue;
			printf("%d %d\n", it -> F, it -> S.k );
		}
	}
}

