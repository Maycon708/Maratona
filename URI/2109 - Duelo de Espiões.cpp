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
  
int sum[50], n[100];
double prob[30][50];

void P1( int id, int a ){
	rep( i, 1, a+1 )
		prob[id][i] = 1.0/a;
}

void P2( int id, int a, int b ){
	rep( i, 1, a+1 )
		rep( j, 1, b+1 )
			prob[id][i+j] += 1.0/( a * b );
}

void P3( int id, int a, int b, int c ){
	rep( i, 1, a+1 )
		rep( j, 1, b+1 )
			rep( k, 1, c+1 )
				prob[id][i+j+k] += 1.0/( a * b * c );
}
  
int na, nb;

double solve( int va, int vb ){
    double pd[310][310][2];
	for( int i = 0; i <= va; i++ ){
		for( int j = 0; j <= vb; j++ ){
			
			if( !i ){ pd[i][j][0] = pd[i][j][1] = 0; continue; }
			if( !j ){ pd[i][j][0] = pd[i][j][1] = 1; continue; }
			pd[i][j][0] = 1, pd[i][j][1] = 0;
		    
			rep( k, 0, na ){
		        double a1 = 0;
		        rep( l, n[k], sum[k]+1 ){
		        	int u = max( 0, j-l );
		            a1 += pd[i][u][0] * prob[k][l];
		        }
		        pd[i][j][1] = max( pd[i][j][1], a1 );
		        if( pd[i][j][1] == 1 ) break;
		    }
		    rep( k, na, na+nb ){
		    	double a2 = 0;
		        rep( l, n[k], sum[k]+1 ){
		        	int u = max( 0, i-l );
		            a2 += pd[u][j][1] * prob[k][l];
		        }
		        pd[i][j][0] = min( pd[i][j][0], a2 );
		        if( pd[i][j][0] == 0 ) break;
			}
		}
	}
	return pd[va][vb][1];
}  
  
int main(){
      
    int va, vb;
    
	while( scanf("%d", &va ) != EOF ){
        vb = readInt(); na = readInt(); nb = readInt();
		memset( prob, 0, sizeof prob );
		rep( i, 0, na ){
			n[i] = readInt();
            if( n[i] == 1 ){
            	int a = readInt();
            	P1( i, a );
            	sum[i] = a;
			}
            else if( n[i] == 2 ){
            	int a = readInt();
            	int b = readInt();
            	P2( i, a, b );
            	sum[i] = a + b;
			}
            else{
            	int a = readInt();
            	int b = readInt();
            	int c = readInt();
				P3( i, a, b, c );
				sum[i] = a + b + c;
			}
        }
		rep( i, na, na+nb ){
            n[i] = readInt();
            sum[i] = 0;
            if( n[i] == 1 ){
            	int a = readInt();
            	P1( i, a );
            	sum[i] = a;
			}
            else if( n[i] == 2 ){
            	int a = readInt();
            	int b = readInt();
            	P2( i, a, b );
            	sum[i] = a + b;
			}
            else{
            	int a = readInt();
            	int b = readInt();
            	int c = readInt();
				P3( i, a, b, c );
				sum[i] = a + b + c;
			}
        }
        printf("%.3f\n", solve( va, vb ) );
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

