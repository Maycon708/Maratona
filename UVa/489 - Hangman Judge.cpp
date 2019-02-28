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
	string word, guess;
	while( scanf("%d", &n ) != EOF && n != -1 ){
		cin >> word >> guess;
		set<char> st, aux;
		rep( i, 0, word.size() ) st.insert( tolower(word[i]) );
		int w = 0, l = 0;
		rep( i, 0, guess.size() ){
			if( aux.count( tolower( guess[i] ) ) ) continue;
			if( st.count( tolower(guess[i])) ) w++, aux.insert( tolower( guess[i] ));
			else l++;
			if( w == st.size() || l == 7 ) break;
		}
		printf("Round %d\n", n );
		if( w == st.size() ) printf("You win.\n");
		else if( l == 7 ) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
}

