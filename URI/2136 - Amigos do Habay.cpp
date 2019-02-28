#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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
	
	int aux = 0;
	set < string > s1, s2;
	set < string > :: iterator it;
	string s, op, resp;
	while( cin >> s ){
		if( s == "FIM" ) break;
		cin >> op;
		if( op == "NO" ){
			s2.insert( s );
			continue;
		}
		s1.insert( s );
		if( s.size() > aux ) aux = s.size(), resp = s;
	}
	it( it, s1 ) cout << *it << "\n";
	it( it, s2 ) cout << *it << "\n";
	printf("\n");
	printf("Amigo do Habay:\n");
	printf("%s\n", resp.c_str() );
	
}

