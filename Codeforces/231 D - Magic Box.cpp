#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

struct ponto{
	int x, y, z;
	ponto(){};
	ponto( int x, int y, int z ){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	ponto operator - ( ponto q ){
		return ponto( x-q.x, y-q.y, z-q.z );
	}
	ponto operator * ( int k ){
		return ponto( x*k, y*k, z*k );
	}
	int operator * ( ponto q ){
		return x*q.x+y*q.y+z*q.z;
	}
	
	void read(){
		cin >> x >> y >> z;
	}
	
	void debug(){
		cout << "X: " << x << " Y: " << y << " Z: " << z << endl;
	}
};

int dx[] = {  0, 0,  0, 0, -1, 1 };
int dy[] = { -1, 1,  0, 0,  0, 0 };
int dz[] = {  0, 0, -1, 1,  0, 0 };

ponto get( ponto k, int i ){
	if( dx[i] == -1 ) k.x = 0;
	if( dy[i] == -1 ) k.y = 0;
	if( dz[i] == -1 ) k.z = 0;
	return ponto( k.x/(2-dx[i]), k.y/(2-dy[i]), k.z/(2-dz[i]) ); 
}

int main(){
	ponto a, l;
	int v;

	a.read();
	l.read();
	a = a*2;
	l = l*2;
	
	int ans = 0;	
	rep( i, 0, 6 ){
		cin >> v;
		ponto vetor = ponto( dx[i], dy[i], dz[i] );
		ponto aux = get( l, i ); 
		aux = a-aux;
		if( aux*vetor > 0 ) ans += v;
	}
	cout << ans << "\n";
}
