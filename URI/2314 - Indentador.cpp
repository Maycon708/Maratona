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

void identa( int k ){
	rep( i, 0, k )
		printf("....");
}

int main(){
	string s;
	while( getline( cin, s ) ){
		int k = 0, aux = 0, quebra = 0;
		if( s[0] == '#' ) printf("%s\n", s.c_str() );
		else{
			rep( i, 0, s.size() ){
				if( s[i] == ';' ){
					if( aux ){
						printf(";");
						continue;
					}
					printf(";\n");
					quebra = 1;
				}
				else if( s[i] == '{' ){
					printf("\n");
					identa(k);
					printf("{\n");
					quebra = 1;
					k++;
				}
				else if( s[i] == '}' ){
					k--;
					identa(k);
					printf("}\n");
					quebra = 1;
				}
				else if( s[i] == '(' ){
					printf("(");
					aux = 1;
				}
				else if( s[i] == ')' ){
					printf(")");
					aux = 0;
				}
				else if( quebra ){
					identa(k);
					quebra = 0;
					printf("%c", s[i] );
				}
				else printf("%c", s[i] );
			}
		}
	} 
}

