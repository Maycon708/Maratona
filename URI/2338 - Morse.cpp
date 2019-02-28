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
	map<string, char> mp;
	mp[".-"  ] = 'a';	mp["-..."] = 'b';	mp["-.-."] = 'c';
	mp["-.." ] = 'd';	mp["."   ] = 'e';	mp["..-."] = 'f';
	mp["--." ] = 'g';	mp["...."] = 'h';	mp[".."  ] = 'i';
	mp[".---"] = 'j';	mp["-.-" ] = 'k';	mp[".-.."] = 'l';
	mp["--"  ] = 'm';	mp["-."  ] = 'n';	mp["---" ] = 'o';
	mp[".--."] = 'p';	mp["--.-"] = 'q';	mp[".-." ] = 'r';	
	mp["..." ] = 's';	mp["-"   ] = 't';	mp["..-" ] = 'u';	
	mp["...-"] = 'v';	mp[".--" ] = 'w';	mp["-..-"] = 'x';
	mp["-.--"] = 'y';	mp["--.."] = 'z';
	
	freopen("teste.txt", "r", stdin );
	int t;
	scanf("%d", &t );
	getchar();
	while( t-- ){
		string s, ans, aux;
		getline( cin, s );
		ans.clear();
		int a = 0, b = 0;
		rep( i, 0, s.size() ){
			if( s[i] == '=' ){ 
				switch(b){
					case 1:
						aux += ( a == 1 ) ? '.' : '-';
						a = 0;
						break;
					case 3:
						aux += ( a == 1 ) ? '.' : '-';
						a = 0;
						ans += mp[aux];
						aux.clear();
						break;
					case 7:
						aux += ( a == 1 ) ? '.' : '-';
						a = 0;
						ans += mp[aux];
						aux.clear();
						ans += ' ';
						break;	
				}
				b = 0, a++;
			}
			else b++;
		}
		aux += ( a == 1 ) ? '.' : '-';
		ans += mp[aux];
		printf("%s\n", ans.c_str() );
	}	
}

