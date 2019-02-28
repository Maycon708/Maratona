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

int main(){
	int n;
	string s;
	while( cin >> n ){
		cin >> s;
		int d = 0, r = 0, vote[200100];
		rep( i, 0, n ){
			if( s[i] == 'D' ) d++;
			else r++;
			vote[i] = 1;
		}
		int rr = 0, dd = 0;
		while( r && d ){
			rep( i, 0, n ){
				if( !r || !d ) break;
				if( !vote[i] ) continue;
				if( s[i] == 'D' ){
					if( dd ) vote[i] = 0, dd--;
					else r--, rr++;
				}
				else{
					if( rr ) vote[i] = 0, rr--;
					else d--, dd++;
				}
			}
		}
		if( r ) printf("R\n");
		else printf("D\n");
	}
}

