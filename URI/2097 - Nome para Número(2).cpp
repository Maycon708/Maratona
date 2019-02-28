#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

map < string, ll > mp;

void pre(){
	mp["zero"  			] = 0;
	mp["um"   			] = 1;
	mp["dois"  			] = 2;
	mp["tres"  			] = 3;
	mp["quatro" 		] = 4;
	mp["cinco"  		] = 5;
	mp["seis" 			] = 6;
	mp["sete"  			] = 7;
	mp["oito"  			] = 8;
	mp["nove"  			] = 9;
	mp["dez"  			] = 10;
	mp["onze"  			] = 11;
	mp["doze"  			] = 12;
	mp["treze" 			] = 13;
	mp["quatorze"		] = 14;
	mp["quinze"			] = 15;
	mp["dezesseis"		] = 16;
	mp["dezessete"		] = 17;
	mp["dezoito" 		] = 18;
	mp["dezenove" 		] = 19;
	mp["vinte"  		] = 20;
	mp["trinta"  		] = 30;
	mp["quarenta"		] = 40;
	mp["cinquenta" 		] = 50;
	mp["sessenta"   	] = 60;
	mp["setenta"   		] = 70;
	mp["oitenta"   		] = 80;
	mp["noventa"   		] = 90;
	mp["cem"			] = 100;
	mp["duzentos"		] = 200;
	mp["trezentos"		] = 300;
	mp["quatrocentos"	] = 400;
	mp["quinhentos"		] = 500;
	mp["seiscentos"		] = 600;
	mp["setecentos"		] = 700;
	mp["oitocentos"		] = 800;
	mp["novecentos"		] = 900;
	mp["mil"			] = 1000;
	mp["cento"			] = 100;
	mp["milhao"			] = ll( 1e6  );
	mp["milhoes"		] = ll( 1e6  );
	mp["bilhao"			] = ll( 1e9  );
	mp["bilhoes"		] = ll( 1e9  );
	mp["trilhao"		] = ll( 1e12 );
	mp["trilhoes"		] = ll( 1e12 );
	mp["quadrilhao"		] = ll( 1e15 );
	mp["quadrilhoes"	] = ll( 1e15 );
	
	
}

int main(){

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
	pre();
	string s;
	stringstream ss;
	while( getline( cin, s ) ){
		ss.clear();
		ss << s;
		ll resp = 0, ans = 0;
		while( ss >> s ){
			if( !mp.count( s ) ) continue;
			if( mp[s] > 900 ) resp += ( max( 1LL, ans ) * mp[s] ), ans = 0;
			else ans += mp[s];
		}
		printf("%lld\n", resp + ans );
	}

}

