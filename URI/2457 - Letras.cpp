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
	char letra;
	string s;
	while( cin >> letra ){
		getline( cin, s );
		getline( cin, s );
		stringstream ss;
		ss << s;
		int num = 0, den = 0;
		while( ss >> s ){
			rep( i, 0, s.size() )
				if( s[i] == letra ){
					num++;
					break;
				}
			den++;
		}
		printf("%.1f\n", num*100.0/den );
	}
}

