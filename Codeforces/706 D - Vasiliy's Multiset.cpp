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

int sig[6400000][2], used[6400000], cnt;

string toS( int num ){
	string aux;
	while( num ){
		if( num&1 ) aux += '1';
		else aux += '0';
		num >>= 1;
	}
	while( aux.size() != 31 ) aux += '0';
	reverse( all(aux) );
	return aux;
}

void add( string s ){
	int x = 0;
	rep( i, 0, s.size() ){
		int c = s[i] - '0';
		if( !sig[x][c] ){
			sig[x][c] = cnt++;
		}
		x = sig[x][c];
		used[x]++;
	}
}

void del( string s ){
	int x = 0;
	rep( i, 0, s.size() ){
		int c = s[i] - '0';
		x = sig[x][c];
		used[x]--;
	}
}

void busca( int resp ){
	string s = toS( resp );
	int n = resp;
	int x = 0;
	rep( i, 0, s.size() ){
		int c = '1' - s[i];
		
		if( sig[x][c] && used[sig[x][c]] ){
			if( c == 1 ) resp |= ( 1 << ( 30 - i ) );
			x = sig[x][c];
		}
		else if( sig[x][!c] ){
			if( (!c) == 1 ) resp ^= ( 1 << ( 30 - i ) );
			x = sig[x][!c];
		}
		else break;
	}
	printf("%d\n", max( n, resp ) );
}

int main(){

	int n, num;
	char op;	
	cnt = 1;
	while( scanf("%d", &n ) != EOF ){
		while( n-- ){
			scanf(" %c%d", &op, &num );
			switch(op){
				case '+': add( toS(num) ); break;
				case '-': del( toS(num) ); break;
				case '?': busca( num );	   break;
			}
		}
	}	

}

