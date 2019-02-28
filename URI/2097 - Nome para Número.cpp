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

ll readInt();

map < string, ll > mp, mp2;

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
	mp["cento"			] = 100;
	mp2["mil"			] = 1000;
	mp2["milhao"		] = ll( 1e6  );
	mp2["milhoes"		] = ll( 1e6  );
	mp2["bilhao"		] = ll( 1e9  );
	mp2["bilhoes"		] = ll( 1e9  );
	mp2["trilhao"		] = ll( 1e12 );
	mp2["trilhoes"		] = ll( 1e12 );
	mp2["quadrilhao"	] = ll( 1e15 );
	mp2["quadrilhoes"	] = ll( 1e15 );
}

int main(){

	pre();
	string s;
	stringstream ss;
	while( getline( cin, s ) ){
		ss.clear();
		ss << s;
		ll resp = 0, ans = 0;
		while( ss >> s ){
			if( mp.count( s ) ){
				ans += mp[s];
			}
			else if( mp2.count( s ) ){
				if( !ans ) ans = 1;
				ans *= mp2[s];
				resp += ans;
				ans = 0;
			}
		}
		printf("%lld\n", resp + ans );
	}

}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}



