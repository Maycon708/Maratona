#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 250
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	string a, b, c;
	while( cin >> a >> b >> c ){
		if( a == b && (( a == "papel" && c == "tesoura" ) || ( a == "pedra" && c == "papel" ) || ( a == "tesoura" && c == "pedra" ) ) ) 
			printf("Urano perdeu algo muito precioso...\n");
		else if( a == c && (( a == "papel" && b == "tesoura" ) || ( a == "pedra" && b == "papel" ) || ( a == "tesoura" && b == "pedra" ) ) ) 
			printf("Iron Maiden's gonna get you, no matter how far!\n");
		else if( b == c && (( b == "papel" && a == "tesoura" ) || ( b == "pedra" && a == "papel" ) || ( b == "tesoura" && a == "pedra" ) ) ) 
			printf("Os atributos dos monstros vao ser inteligencia, sabedoria...\n");
		else 
			printf("Putz vei, o Leo ta demorando muito pra jogar...\n");
		
	}
}