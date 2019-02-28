#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
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

inline bool check( string a, char b, char c ){
	rep( i, 0, a.size() ){
		if( a[i] == b || a[i] == c ) return 1;
	}
	return 0;
}

void up( string s ){
	if( !check( s, 's', 'r' ) ){
		printf("<none> ");
		return;
	}
	string resp = s;
	int tam = s.size()-1;
	for( int i = tam; i >= 0; i-- ){
		if( resp[i] == 's' ){
			resp[i] = 'p';
			break;
		}
		if( resp[i] == 'r' ){
			resp[i] = 'q';
			break;
		}
		if( resp[i] == 'p' ) resp[i] = 's';
		if( resp[i] == 'q' ) resp[i] = 'r';
	}
	printf("%s ", resp.c_str() );
}

void down( string s ){
	if( !check( s, 'p', 'q' ) ){
		printf("<none> ");
		return;
	}
	string resp = s;
	int tam = s.size()-1;
	for( int i = tam; i >= 0; i-- ){
		if( resp[i] == 'p' ){
			resp[i] = 's';
			break;
		}
		if( resp[i] == 'q' ){
			resp[i] = 'r';
			break;
		}
		if( resp[i] == 's' ) resp[i] = 'p';
		if( resp[i] == 'r' ) resp[i] = 'q';
	}
	printf("%s ", resp.c_str() );
	
}

void left( string s ){
	if( !check( s, 'q', 'r' ) ){
		printf("<none> ");
		return;
	}
	string resp = s;
	int tam = s.size()-1;
	for( int i = tam; i >= 0; i-- ){
		if( resp[i] == 'q' ){
			resp[i] = 'p';
			break;
		}
		if( resp[i] == 'r' ){
			resp[i] = 's';
			break;
		}
		if( resp[i] == 'p' ) resp[i] = 'q';
		if( resp[i] == 's' ) resp[i] = 'r';
	}
	printf("%s ", resp.c_str() );
}

void right( string s ){
	if( !check( s, 's', 'p' ) ){
		printf("<none>\n");
		return;
	}
	string resp = s;
	int tam = s.size()-1;
	for( int i = tam; i >= 0; i-- ){
		if( resp[i] == 's' ){
			resp[i] = 'r';
			break;
		}
		if( resp[i] == 'p' ){
			resp[i] = 'q';
			break;
		}
		if( resp[i] == 'r' ) resp[i] = 's';
		if( resp[i] == 'q' ) resp[i] = 'p';
	}
	printf("%s\n", resp.c_str() );
}

int main(){
	
	string s;
	int t;
	cin >> t;
	while( t-- ){
		cin >> s;
		up( s );
		down( s );
		left( s );
		right( s );
	}
	
}

