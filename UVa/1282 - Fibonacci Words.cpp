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
#define N 200010

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;
typedef long long int ull;

ull fib[200];

ull back( string s, int n ){
	string aux;
	int t = s.size()-1;
	if( !n ) return 0;
	if( s.size() == 1 ){
		if( s[0] == '1' ) return fib[n-1];
		else return n >= 2 ? fib[n-2] : 0;
	}

	if( s[0] == '0' ) aux.pb('1');
	rep( i, 0, t ){
		if( s[i] == '1' ){
			if( s[i+1] == '0' ) aux.pb('1');
			else aux.pb('0');
		}
		else if( s[i+1] == '0' ) return 0;
	}
	if( s[t] == '1' ){
		string x = aux;
		aux.pb('1'), x.pb('0');
		return back(x, n-1) + back(aux, n-1);
	} 
	
	return back(aux, n-1);
}

int main(){
	int n, test = 1;
	char s[100010];
	
	fib[0] = fib[1] = 1;
	rep( i, 2, 101 ) fib[i] = fib[i-1] + fib[i-2];
	
	while( scanf("%d", &n ) != EOF ){
		scanf("%s", s );
		if( !n && s[0] == '0' && s[1] == '\0' ) printf("Case %d: 1\n", test++);
		else printf("Case %d: %lld\n", test++, back(s, n) );
	}
}
