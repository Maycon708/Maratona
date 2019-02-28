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

bool pallin( string s ){
	int j = s.size()-1;
	for( int i = 0, j = s.size()-1; i < j; i++, j-- ){
		if( s[i] != s[j] ) return 0;
	}
	return 1;
}

string toP( string n ){
	string s = n;
	reverse( all(s) );
	return n + '.' + s;
} 

string sub( string a, string b ){
	char aux[] = "0123456789";
	string s;
	int aa = a.size(), bb = b.size();
	rep( i, 0, a.size() ) if( a[i] == '.' ) aa = i;
	rep( i, 0, b.size() ) if( b[i] == '.' ) bb = i;
	if( aa == a.size() ) a += '.';
	if( bb == b.size() ) b += '.';
	while( bb < aa ) b = "0" + b, bb++;
	while( aa < bb ) a = "0" + a, aa++;
	while( b.size() < a.size() ) b += "0";
	while( a.size() < b.size() ) a += "0";
	int take = 0;
	for( int i = a.size()-1; i >= 0; i-- ){
		if( a[i] == '.' ) s += '.';
		else{
			int u = a[i] - take - b[i];
			if( u < 0 ) take = 1, u += 10;
			else take = 0;
			s += aux[u];
		}
	}
	int j = s.size() - 1, k = 0;
	while( s[j] == '0' ) j--;
	while( s[k] == '0' ) k++;
	string aux2;
	rep( i, k, j+1 ) aux2 += s[i]; 
	reverse( all(aux2) );
	if( aux2[0] == '.' ) aux2 = '0' + aux2;
	return aux2;
}

string I2A( int n ){
	string s;
	while( n ){
		s += char( '0' + n%10 );
		n /= 10;
	}
	reverse( all(s) );
	return s;
}
 
int A2I( string s ){
	int n = 0;
	rep( i, 0, s.size() ){
		if( s[i] == '.' ) break;
		n *= 10;
		n += ( s[i] - '0' );
	}
	return n;
} 
 
bool cmp( string a, string b ){
	if( A2I(a) != A2I(b) ) return A2I(a) > A2I(b);
	bool aux = 0;
	string aa, bb;
	rep( i, 0, a.size() ) 
		if( a[i] == '.') aux = 1; 
		else if( aux ) aa += a[i];
	aux = 0;
	rep( i, 0, b.size() ) 
		if( b[i] == '.') aux = 1; 
		else if( aux ) bb += b[i];
	return A2I(aa) > A2I(bb);
} 
 
int main(){
	int t;
	string v;
	scanf("%d", &t );
	while( t-- ){
		cin >> v;
		int w = A2I(v);
		string a = toP(I2A(w));
		string b = toP(I2A(w+1));
		string c = I2A(w+1);
		if( pallin(v) ) printf("0\n");
		else if( cmp( a, v ) ) cout << sub(a,v) << "\n";
		else if( pallin(c) ) cout << sub(c,v) << "\n";
		else cout << sub(b,v) << "\n";
	}
}     
