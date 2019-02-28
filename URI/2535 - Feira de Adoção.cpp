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

string a, b, c, d;

bool C(){
	if( a != "cachorro" ) return 0;
	if( c.find(' ') > c.size()  ) return 0;
	stringstream ss;
	ss << c;
	while( ss >> d ) if( d[0] == b[0] ) return 1;
	return 0;
}

int main(){
	int n;	
	while( scanf("%d", &n ) != EOF ){
		getchar();
		int cnt = 0;
		while( n-- ){
			getline( cin, a );
			getline( cin, b );
			getline( cin, c );
			getline( cin, d );
		
			if( C() ) cnt++;
		}
		printf("%d\n", cnt );
	}
	
	
}
