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
	string s;
	while( scanf("%d", &n ) != EOF && n ){
		getline( cin, s );
		getline( cin, s );
		stringstream ss;
		ss << s;
		char c; int a, aux = 1, ans = 0;
		while( ss >> c ){
			ss >> a;
			if( c == 'm' ){ if( a&1 ) aux *= -1; }
			else ans = (( ans + aux * a )%n + n)%n;
		}
		if( !ans ) printf("\n");
		else if( ans <= n-ans+1+(aux!=-1) ) printf("r%d%s", ans, aux == -1 ? " m1\n" : "\n" );
		else printf("m1 r%d%s", n-ans, aux == -1 ? "\n" : " m1\n" );
	}
}
