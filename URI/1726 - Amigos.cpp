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

struct conjunto{
	bool v[30];
	void init(){
		rep( i, 0, 30 )
			v[i] = 0;
	}
	void construct( string s ){
		rep( i, 0, s.size() ){
			int u = s[i] - 'A';
			v[u] = 1;
		}
	}
	conjunto operator + ( conjunto A ){
		conjunto resp;
		resp.init();
		rep( i, 0, 26 ) resp.v[i] = ( v[i] | A.v[i] );
		return resp;
	}
	conjunto operator - ( conjunto A ){
		conjunto resp;
		resp.init();
		rep( i, 0, 26 ) resp.v[i] = ( v[i] && !A.v[i] );
		return resp;
	}
	conjunto operator * ( conjunto A ){
		conjunto resp;
		resp.init();
		rep( i, 0, 26 ) resp.v[i] = v[i] && A.v[i];
		return resp;
	}
	void print(){
		printf("{");
		rep( i, 0, 26 ){
			if( v[i] )	printf("%c", char( 'A'+i ) );
		}
		printf("}\n");
	}
};

conjunto solve( string s ){
	conjunto a, b, c;
	stack<conjunto> st;
	stack<char> op;
	bool mult = 0;
	rep( i, 0, s.size() ){
		if( s[i] == '}' ){
			string aux;
			i++;
			while( s[i] != '{' ){
				aux += s[i];
				i++;
			}
			a.init();
			a.construct( aux );
			st.push( a );
		}
		if( s[i] == ')' ){
			string aux;
			i++; 
			int cnt = 0;
			while( s[i] != '(' || cnt ){
				if( s[i] == ')' ) cnt++;
				if( s[i] == '(' ) cnt--;
				aux += s[i];
				i++;
			}
			a = solve( aux );
			st.push( a );
		}
		if( mult ){
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push( a*b );
			mult = 0;
		} 
		if( s[i] == '*' ) mult = 1;
		if( s[i] == '-' || s[i] == '+' ) op.push( s[i] );
	}
	while( !op.empty() ){
		a = st.top(); st.pop();
		b = st.top(); st.pop();
		char signal = op.top(); op.pop();
		if( signal == '+' ) st.push( a+b );
		else st.push( a-b );
	}
	return st.top();
}

int main(){
	conjunto a, b, c;
	char op;
	string  s;
	while( getline( cin, s ) ){
		reverse( all(s) );
		c = solve( s );	
		c.print();
	}
}

