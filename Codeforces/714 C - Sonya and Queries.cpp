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

int cnt, sig[1800000][2], qttd[1800000];

void add( string s ){
	int x = 0;
	rep( i, 0, s.size() ){
		int c = s[i] - '0';
		if( !sig[x][c] ){
			sig[x][c] = cnt;
			qttd[cnt++] = 0;
		}
		x = sig[x][c];
		qttd[x]++;
	}
}

void remove( string s ){
	int x = 0;
	rep( i, 0, s.size() ){
		int c = s[i] - '0';
		x = sig[x][c];
		qttd[x]--;
	}
}

int busca( string s ){
	int x = 0, ans = 0;
	rep( i, 0, s.size() ){
		int c = s[i] - '0';
		if( !sig[x][c] ) return 0;
		x = sig[x][c];
	}
	return qttd[x];
}

string S( ll a ){
	string s;
	while( a ){
		if( a&1 ) s+= '1';
		else s += '0';	
		a/= 10;
	}   
	while( s.size() != 18 ) s += '0';
	reverse( all(s) );
	return s;
}
                
int main(){
	int n; ll u; char op; string s;
	while( scanf("%d", &n ) != EOF ){
		cnt = 1;
//		memset( sig, 0, sizeof sig );
		rep( i, 0, n ){
			cin >> op;
			switch( op ){
				case '+':
					scanf("%lld", &u );
					add(S(u));
					break;
				case '-':
					scanf("%lld", &u );
					remove(S(u));
					break;
				case '?':
					cin >> s;
					while( s.size() != 18 ) s = '0' + s;
					printf("%d\n", busca(s));
					break;
			}
		}
	}
}

