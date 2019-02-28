#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 450

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int n, v[200], aux[200];

int cmp( int a, int b ){
	return v[a] < v[b];
}

int main(){
	string s, aux;
	while( getline( cin, s ) && s != "DONE" ){
		aux.clear();
		rep( i, 0, s.size() ){
			if( s[i] >= 'a' && s[i] <= 'z' ) aux.pb(s[i]);
			else if( s[i] >= 'A' && s[i] <= 'Z' ) aux.pb( tolower(s[i]) );
		}
		s = aux;
		reverse( all(s) );
		if( s == aux ) puts("You won't be eaten!");
		else puts("Uh oh..");
	}
}
