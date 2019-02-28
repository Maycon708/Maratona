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

char s[100010], p[10001];
int t1, t2;

bool check( int n ){
	int j = 0, cnt = 0;
	for( int i = t1; i > 0; i-- ){
		if( s[t1-i] == p[j] ) cnt++;
		if( cnt == n ) cnt = 0, j++;
		if( j == t2 ) return 1;
	}
	return 0;
}

int bb(){
	int a = 0, b = t1/t2, c;
	while( a < b ){
		c = ( a + b + 1 ) >> 1;
		if( check(c) ) a = c;
		else b = c - 1;
	}
	return a;
}
#define gc getchar_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int main(){
	int t;
	scan(t);
	for( register int i = t; i > 0; i-- ){
		t1 = 0, t2 = 0;
		gets(s);
		gets(p);
		t1 = strlen(s);
		t2 = strlen(p);
		printf("%d\n", bb() );
	}
}

