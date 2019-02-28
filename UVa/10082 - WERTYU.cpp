#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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

int main(){
	     
    map <char, char> mp;
     
    mp['W']='Q'; mp['E']='W'; mp['R']='E'; mp['T']='R'; mp['Y']='T'; mp['U']='Y'; mp['I']='U'; mp['O']='I'; 
    mp['P']='O'; mp['[']='P'; mp[']']='['; mp['S']='A'; mp['D']='S'; mp['F']='D'; mp['G']='F'; mp['H']='G';
    mp['J']='H'; mp['K']='J'; mp['L']='K'; mp[';']='L'; mp['X']='Z'; mp['C']='X'; mp['V']='C'; mp['B']='V';
    mp['N']='B'; mp['M']='N'; mp[',']='M'; mp['.']=','; mp['/']='.'; mp['\\'] =']';
    mp['1']='`'; mp['2'] = '1'; mp['3'] = '2'; mp['4'] = '3'; mp['5'] = '4'; mp['6'] = '5'; mp['7'] = '6'; mp['8'] = '7'; mp['9'] = '8'; mp['0'] = '9'; mp['-'] = '0'; mp['='] = '-';mp['\'']=';';
     
    char c[100000];
	     
	while( gets(c) ){
	    
	    int t = strlen(c);
	    rep( i, 0, t ){
	        if( c[i] == ' ' ) printf(" ");
	        else printf("%c", mp[ c[i] ]);
	    }
	    printf("\n");
	}
    return 0;
}

