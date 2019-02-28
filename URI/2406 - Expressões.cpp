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

bool S( char a, char b ){
	string s;
	s += a;
	s += b;
	return s != "()" && s != "{}" && s != "[]";
}

bool check( string s ){
	stack<char> st;
	rep( i, 0, s.size() ){
		if( s[i] == '(' || s[i] == '{' || s[i] == '[' ) st.push( s[i] );
		else if( st.empty() ) return 0;
		else if( S( st.top(), s[i] ) ) return 0;
		else st.pop();
	}
	return st.empty();
}

int main(){
	int n;
	cin >> n;
	while( n-- ){
		string s;
		cin >> s;
		if( check(s) ) printf("S\n");
		else printf("N\n");
	}
}

