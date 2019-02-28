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
	while( cin >> s ){
		int a = 0, b = 0;
		rep( i, 0, s.size() ){
			if( s[i] >= 'A' && s[i] <= 'Z' ) a++;
			else b++;
		}
		rep( i, 0, s.size() ){
			if( a > b ) printf("%c", toupper(s[i]) );
			else printf("%c", tolower(s[i]) ); 
		}
		printf("\n");
	}
}

