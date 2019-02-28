#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define D(x) cout << #x << " = " << x << endl;
#define D2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-6
#define mp make_pair

using namespace std;

int a, at;
int v[100010];
int n;

#define gc getchar_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

double bb( double ini, double fim ){
    
    while( fabs( ini - fim ) > EPS ){
        
		register double mid = ( ini + fim )/2;
        register double sum = 0;
        
		for( register int i = n; i > 0; i-- )
            if( v[i-1] > mid ){
                sum += ( v[i-1] - mid );
			}
			else break;
        
		if( fabs( sum - a ) < EPS ) return mid;
        
		else if( sum > a ) ini = mid;
        else fim = mid;
    }
    return ini;
}

int main(){
    
    while( 42 ){
    	scan(n), scan(a);
        if( !n ) break;
		int maior = 0;
        at = 0;
        for( register int i = n; i > 0; i-- ){
        	scan( v[n-i] );
            at += v[n-i];
            maior = max(maior, v[n-i]);
        }
        sort( v, v+n );
        if( at == a ) puts(":D");
        else if( at < a ) puts("-.-");
        else{
            register double aux = bb(0, maior);
            printf("%.4lf\n", aux);     
        }  
    }
}

