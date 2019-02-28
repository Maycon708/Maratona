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

int C( char s ){
	int u = tolower(s) - 'a';
	return (u%9)+1; 
}

int main(){

	string s;
	while( getline( cin, s ) ){
		int ans = 0;
		rep( i, 0, s.size() ){
			if( isalpha(s[i]) ) ans += C( s[i] );
		}
		while( log10(ans) >= 1 ){
			int aux = 0;
			while( ans ){ 
				aux += ans%10;
				ans /= 10;
			}
			ans = aux;
		}
		printf("%d\n", ans );
	}
	
}

