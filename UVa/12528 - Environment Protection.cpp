#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 100*30
#define F first
#define S second
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;
inline ll readInt ();
int k, p1[100], q1[100], p2[100], q2[100], w, d, a;

double eleva( double x, int pp){
    double resp = 1;
    rep( i, 0, pp ){
         resp *= x;
    }
    return resp;
}
double f(double x, double mid){
    double den = 0, quo = 0;
    rep( i, 0, k )
        den += ( p1[i]*eleva( x, i ) ), quo += ( q1[i]*eleva( x, i ) );
    double ans = den/quo;
    if( ans < mid ) return mid;
    return ans;
}
double f2(double x, double mid){
    double den = 0, quo = 0;
    rep( i, 0, k )
        den += ( p2[i]*eleva( x, i ) ), quo += ( q2[i]*eleva( x, i ) );
    double ans = den/quo;
    if( ans < mid ) return mid;
    return ans;
}
double simpsons1(double a,double b,int n, double mid ){
    double delta = delta = (b-a)/n;
    double integral = 0.0; int i;
    for(i= 0;i <n;i= i+1 ) 
        integral = integral + ( f( a + i*delta, mid )+ 4*f( a +( i + 0.5 ) *delta, mid )+f( a+( i+1 )*delta, mid ))/6*delta;
            return integral;
}
double simpsons2(double a,double b, int n, double mid ){
    double delta = delta = (b-a)/n;
    double integral = 0.0; int i;
    for(i= 0;i <n;i= i+1 ) 
        integral = integral + ( f2( a + i*delta, mid )+ 4*f2( a +( i + 0.5 ) *delta, mid )+f2( a+( i+1 )*delta, mid ))/6*delta;
            return integral;
}

double bb( double fim, int w, double resp ){
	double ini = 0, mid;
	rep( i, 0, 200 ){
		mid = ( ini + fim )/2;
		double area = simpsons1( 0, w, 10000, -mid) - simpsons2( 0, w, 10000, -mid);
	//	debug( area )
		if( abs( area - resp ) < EPS ) return mid;
		if( area > resp ) fim = mid;
		else ini = mid;
	}
	return mid;
}

int main(){
    while( scanf("%d", &w) != EOF ){
        d = readInt();
        a = readInt();
        k = readInt()+1;
        rep(i, 0, k )
            p1[i] = readInt();
        rep(i, 0, k )
            q1[i] = readInt();
        rep(i, 0, k )
            p2[i] = readInt();
        rep(i, 0, k )
            q2[i] = readInt();
        printf("%.5f\n", bb( d, w, a ) );
        
    }
}

inline ll readInt (){
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
