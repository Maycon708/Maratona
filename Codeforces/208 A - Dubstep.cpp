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

	string s, a = "WUB", at;
	while( getline( cin, s ) ){
		s += "WUBWUB";
		int sp = 0;
		rep( i, 0, s.size()-3 ){
			bool aux = 1;
			for( int j = 0; j < 3; j++ ) aux &= (s[i+j] == a[j]);
			if( aux ){
				i += 2;
				if( at == "" ) continue;
				if( sp ) printf(" ");
				sp = 1;
				printf("%s", at.c_str() );
				at.clear();
			}
			else at += s[i];
		}
		printf("\n");
	}
	
}

