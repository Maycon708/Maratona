#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
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

string C( int a ){
	string s = "", aux = "0123456789";
	
	while( a ){
		s += aux[ a%10 ];
		a /= 10;
	}
	reverse( all( s ) );
	return s;
}

string S( string s ){
	int t = s.size();
	string resp = "";
	char at = s[0];
	int cont = 1;
	rep( i, 1, t ){
		char u = s[i];
		if( u == at ) cont++;
		else{
			resp += C( cont );
			resp += at;
			at = u;
			cont = 1;
		}
	}
	resp += C( cont );
	resp += at;
	return resp;
}

int main(){
	
	string s;
	int t, n;
	
	cin >> t;
	rep( j, 0, t ){
		if( j ) printf("\n");
		cin >> s >> n;
		cout << s << "\n";
		rep( i, 0, n ){
			s = S( s );
			cout << s << "\n";
		}
	}

}
