#include <bits/stdc++.h>

#define INF 0x3F3F3F
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

inline bool C( int a ){
	return a != -INF && a != -2*INF && a != -3*INF && a != -4*INF;
}

int main(){
	
	string c;
	while( getline( cin, c ) ){
		
		bool valid = 1, zero = 0;
		stack<int> s;
		
		int t = c.size();
		if( !( t&1 ) ){
			printf("Invalid expression.\n");
			continue;
		}
		rep( i, 0, t ){
			if( c[i] == ' ' ) continue;
			if( c[i] == '+' ) s.push( -1*INF );
			else if( c[i] == '-' ) s.push( -2*INF );
			else if( c[i] == '*' ) s.push( -3*INF );
			else if( c[i] == '/' ) s.push( -4*INF );
			else{
				int v = c[i] - '0';
				while( s.size() && C( s.top() ) ){
					int u = s.top(); s.pop();
					if( s.empty() || s.top() >= 0 ){
						valid = 0;
						break;
					}
					int op = s.top(); s.pop();
					switch( op ){
						case -1*INF: v = ( u + v ); break;
						case -2*INF: v = ( v - u ); break;
						case -3*INF: v = ( u * v ); break;
						case -4*INF:{
							if( !u ) zero = 1, v = ( 0 );
							else v = ( v/u );
							break;
						}
					}
				}
				s.push( v );
			}
		}
		if( s.size() != 1 ) valid = 0;
		if( !valid ) printf("Invalid expression.\n");
		else if( zero ) printf("Division by zero.\n");
		else printf("The answer is %d.\n", s.top() );
	}
}

