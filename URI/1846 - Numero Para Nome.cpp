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

string aux[][10] = { {"", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"}, {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"}, {"", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove" }};

string C( int k ){
	string aux1[] = { "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove" };
	return aux1[ k-10 ];
}

int main(){
	int n;
	while( cin >> n ){
		if( !n ){
			printf("zero\n");
			continue;
		}
		if( n == 100 ){
			printf("cem\n");
			continue;
		}
		vector < string > ans;
		bool check = 1, check2 = 0;
		int k = n/1000;
		int c = 2;
		while( k ){
			if( k == 1 && check ){
				ans.pb("*");
				break;
			}
			if( k == 100 ){
				ans.pb( "cem" );
				break;
			} 
			int u = k%10;
			if( k%100 >= 10 && k%100 < 20 && check ){
				string s = C( k%100 );
				ans.pb( s );
				k/= 100;
				c -= 2;
				check = 0;
				continue;
			}
			check = 0;
			if( aux[c][u] != "" ){
				if( !ans.empty() ) ans.pb( "e" );
				ans.pb( aux[c][u] );
			}
			c--;
			k/=10;
		}
		if( !ans.empty() ){
			reverse( all( ans) );
			rep( i, 0, ans.size() ){
				if( ans[i] != "*" )cout << ans[i] << " ";
			}
			printf("mil");
			check2 = 1;
		}
		ans.clear();
		n%=1000;
		k = n;
		c = 2;
		check = 1;
		if( check2 && ( ( !(n/100) && n%100 ) || ( n/100 && !(n%100) ) ) ) printf(" e");
		while( k ){
			if( k == 100 ){
				ans.pb( "cem" );
				break;
			}
			int u = k%10;
			if( k%100 >= 10 && k%100 < 20 && check){
				string s = C( k%100 );
				ans.pb( s );
				k/= 100;
				c = 0;
				check = 0;
				continue;
			}
			check = 0;
			if( aux[c][u] != "" ){
				if( !ans.empty() ) ans.pb( "e" );
				ans.pb( aux[c][u] );
			}
			c--;
			k/=10;
		}
		if( !ans.empty() ){
			reverse( all( ans) );
			rep( i, 0, ans.size() ){
				if( i || check2 ) printf(" ");
				cout << ans[i];
			}
			check = 1;
		}
		printf("\n");
	}

}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

