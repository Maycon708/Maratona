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
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int get( char c, int op ){
	if( isdigit(c) ) return c - '0';
	if( !op ) return c - 'A';
	else{
		int cnt = 0;
		for( char i = 'A'; i != c; i++ ){
			if( i != 'A' && i != 'C' && i != 'I' && i != 'M' && i != 'P') cnt++;
		}
		return cnt;
	}
	
}

int sub( string a, string b, int op ){
	reverse( all(a) );
	reverse( all(b) );
	int resp = 0, aux = 0, u = 1;
	rep( i, 0, a.size() ){
		int aa = get( a[i], op ), bb = get( b[i], op );
//		debug2( aa, bb )
		if( aa - aux >= bb ) resp += (( aa - aux ) - bb ) * u, aux = 0;// printf("%d\n", resp );
		else if( isdigit( a[i] ) ) resp += ( ( aa + 10 - aux ) - bb ) * u, aux = 1;//, printf("%d\n", resp);
		else resp += ( ( aa + ((op) ? 21 : 26 ) - aux ) - bb ) * u, aux = 1;// printf("%d\n", resp);
		if( isdigit( a[i] ) ) u *= 10;
		else u *= ( op ) ? 21 : 26;
	}
	return resp;
}

inline bool invalid( string s ){
	rep( i, 0, s.size() ){
		if( s[i] != 'A' && s[i] != 'C' && s[i] != 'I' && s[i] != 'M' && s[i] != 'P') continue;
		return 1;
	}
	return 0;
}

bool ilegal( string a ){
	return isdigit(a[3]) != isdigit(a[4]);
}

inline bool tipo( string a ){
	return isdigit( a[3] );
}

int main(){
	string a, b;
	ll c;
	while( cin >> a >> b >> c ){
		if( a == "*") break;
		if( ilegal(b) ){
			printf("N\n");
			continue;
		}
		if( tipo( a ) ){
			if( tipo(b) ){
				if( a >= b ) printf("N\n");
				else if( sub( b, a, 0 ) <= c ) printf("Y\n");
				else printf("N\n");
			}
			else{
				if( invalid(b)) printf("N\n");
				else if( sub( b, "BBBBB00", 1 ) + sub("ZZZ9999", a, 0 ) + 1 <= c ) printf("Y\n");
				else printf("N\n");
			}
		}
		else{
			if( tipo(b) ) printf("N\n");
			else{
				if( a >= b || invalid(b) ) printf("N\n");
				else if( sub( b, a, 1 ) <= c ) printf("Y\n");
				else printf("N\n");
			}
		}
	}
}

