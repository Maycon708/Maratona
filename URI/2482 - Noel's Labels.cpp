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
	string a, b;
	while( cin >> n ){
		map< string, string > mp;
		getline( cin, a );
		while( n-- ){
			getline( cin, a );
			getline( cin, b );
			mp[a] = b;
		}
		cin >> n;
		getline( cin, a );
		while( n-- ){
			getline( cin, a );
			getline( cin, b );
			cout << a << "\n" << mp[b] << "\n\n";
		}
	}
}

