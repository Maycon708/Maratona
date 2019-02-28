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
	int n, u;
	while( scanf("%d", &n ) != EOF ){
		set<int> st;
		rep( i, 0, n ){
			scanf("%d", &u );
			st.insert(u);
		}
		if( st.size() > 3 ) printf("NO\n");
		else if( st.size() < 3 ) printf("YES\n");
		else{
			int a = *st.begin();
			int b = *( ++st.begin());
			int c = *( ++( ++st.begin() ) );
			if( b - a == c - b ) printf("YES\n");
			else printf("NO\n"); 
		}
	}
}
