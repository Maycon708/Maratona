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

bool check( string a, string b ){
	if( a.size() == b.size() ){
		int cnt = 0, p;
		rep( i, 0, a.size() ) if( a[i] != b[i] ) cnt++, p = i;
		if( cnt == 1 ) return 1;
		if( cnt == 2 && a[p] == b[p-1] && a[p-1] == b[p] ) return 1;
		return 0; 
	}
	if( a.size() == b.size()+1 ){
		int j = 0;
		rep( i, 0, a.size() ){
			if( a[i] != b[i-j] ){
				if( j ) return 0;
				j = 1;
			}
		}
		return 1;
	}
	
	if( a.size()+1 == b.size() ){
		int j = 0;
		rep( i, 0, b.size() ){
			if( a[i-j] != b[i] ){
				if( j ) return 0;
				j = 1;
			}
		}
		return 1;
	}
	return 0;
}

int main(){
	int n, q;
	string d[10010], a;
	while( scanf("%d", &n ) != EOF ){
		map<string, int> mp;
		rep( i, 0, n ){
			cin >> d[i];
			mp[d[i]] = 1;
		}
		scanf("%d", &q );
		while( q-- ){
			
			cin >> a;
			
			if( mp.count(a) ){
				printf("%s is correct\n", a.c_str() );
				continue;
			}
			bool f = 0;
			rep( i, 0, n ){
				if( check( a, d[i] ) ){
					printf("%s is a misspelling of %s\n", a.c_str(), d[i].c_str() );
					f = 1;
					break;
				}
			}
			
			if( !f ) printf("%s is unknown\n", a.c_str() );
		}
	}
}

