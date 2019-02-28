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

	int t, n;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		set<string> st;
		string a, b;
		while( n-- ){
			cin >> b >> a;
			if( a == "chirrin") st.insert(b);
			else if( a == "chirrion" && st.count(b) ) st.erase( st.find(b) );	
		}
		printf("TOTAL\n");
		for( auto y : st ) cout << y << endl;
	}

}
