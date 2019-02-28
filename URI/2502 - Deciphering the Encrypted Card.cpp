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
	
	int c, n;
	
	string s, s1, s2;
	
	while( scanf("%d%d", &c, &n ) != EOF ){
		getline( cin, s1 );
		getline( cin, s1 );
		getline( cin, s2 );
		
		map<char,char> mp;
		rep( i, 0, c ){
			if( s1[i] >= 'A' && s1[i] <= 'Z' ) s1[i] = tolower(s1[i]);
			if( s2[i] >= 'A' && s2[i] <= 'Z' ) s2[i] = tolower(s2[i]);
			mp[s1[i]] = s2[i], mp[s2[i]] = s1[i];
		}
		rep( i, 0, n ){
			getline( cin, s );
			int t = s.size();
			rep( i, 0, t ){
				if( s[i] >= 'A' && s[i] <= 'Z' && mp.count( tolower(s[i]) ) ) 
				printf("%c", toupper( mp[tolower(s[i])] ));
				else if( mp.count( (s[i]) ) ) printf("%c", mp[s[i]] );
				else printf("%c", s[i] );
			}
			printf("\n");
		}
		printf("\n");
	}

}
