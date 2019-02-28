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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

bool ehprimo[1048576];   
vector<int> primos, divisor; 
const int limite = 1048576;   
int e[1005], p[1005];

void crivo(){       
	for(int i=0; i<= limite; i++) ehprimo[i] = true;           
	ehprimo[0] = ehprimo[1] = false;             
	for(ll i = 2; i <= limite; i++)         
		if(ehprimo[i]){             
			for(ll j = i*i; j <= limite; j += i) ehprimo[j] = false;             
			primos.push_back(i);         
		} 
} 

int fatora(int n){  
	int primo, limite, idx = 0;  
	primo = primos[idx++];
	int tam = 0;  
	memset(e, 0, sizeof e);  
	limite = (int)sqrt(n);  
	while(n > 1 && primo<=limite){   
		if (n%primo == 0){    
			p[tam] = primo;    
			e[tam] = 1;    
			n/=primo;    
			while (n%primo == 0){    
				e[tam]++;     
				n/=primo;    
			}    
			tam++;   
		}   
		primo = primos[idx++];  
	}  
	if(n>1){    
		p[tam] = n;    
		e[tam] = 1;    
		tam++;  
	}  
	return tam; 
}   

inline bool C( int n ){
	if( n < 36 || ehprimo[n] ) return 0;
	int tam = fatora( n );
	if( tam == 1 ){
		return e[0] >= 8;
	}
	if( tam >= 4 ) return 1;
	if( tam == 3 ){
		rep( i, 0, tam ) if( e[i] > 1 ) return 1;
		return 0;
	}
	if( e[0] == 1 || e[1] == 1 ){
		return e[0] + e[1] >= 6; 
	}
	return 1;
}

void divisores(int i, int qt, int D){  
	if(i == qt){   
		divisor.pb(D);   
		return;  
	}  
	for(int k=0; k <= e[i]; k++){   
		divisores(i+1, qt, D);   
		D *= p[i];  
	} 
}  

int main(){
	int n, t, m;
	crivo();
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		
		int a = 0, b = 0;
		
		t = fatora( n );
		divisores( 0, t, 1 );
		rep( i, 0, divisor.size() ) a += divisor[i];
		divisor.clear();
		
		t = fatora( m );
		divisores( 0, t, 1 );
		rep( i, 0, divisor.size() ) b += divisor[i];
		divisor.clear();
		a -= n, b -= m;
		
		if( n%b == 0 && m%a == 0 ) printf("Friends and lovers <3\n");
		else if( a == b ) printf("Almost lovers!\n");
		else if( n%b == 0 ) printf("%d friendzoned %d!\n", n, m );
		else if( m%a == 0 ) printf("%d friendzoned %d!\n", m, n ); 
		else printf("No connection.\n");
	}
}

