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

struct monster{
	
	char name[1000];
	int lvl;
	double hp, mp, atk, mag, def, hpmax;
	int debuf;
	
	void print(){
		if( hp <= 0 ) 
			printf("%s is dead.\n", name );
		else{
			if( debuf & 1 ) atk *= 1.25;
			if( debuf & 4 ) atk *= 0.75;
			if( debuf & 2 ) def *= 1.25;
			if( debuf & 8 ) def *= 0.75;
			printf("%s HP: %.2f, MP: %.2f, ", name, hp, mp );
			printf("ATK: %.1f, MAG: %.1f, DEF: %.1f\n", atk, mag, def );
		}
	}
	bool scan(){
		if( scanf("%s%d%lf%lf%lf%lf%lf", name, &lvl, &hp, &mp, &atk, &mag, &def ) == EOF ) return 0;
		debuf = 0; hpmax = hp;
		return 1; 
	}
};

struct ataque{
	int op, cost, power;
	int debuf;
	ataque( int a = 0, int b = 0, int c = 0, int d = 0 ) : 
		op(a), cost(b), power(c), debuf(d){}
};

map < string, ataque > mp;

void init(){
	mp[ "MightySwing"] = ataque( 1, 14, 270,  0 );
	mp["GiganticFist"] = ataque( 1, 16, 560,  0 );
	mp[ "RainyDeath" ] = ataque( 1, 20, 350,  0 );
	mp[   "Agilao"   ] = ataque( 2,  8, 200,  0 );
	mp[   "Agidyne"  ] = ataque( 2, 12, 320,  0 );
	mp[   "Bufula"   ] = ataque( 2,  8, 200,  0 );
	mp[  "Bufudyne"  ] = ataque( 2, 12, 320,  0 );
	mp[  "Megidola"  ] = ataque( 2, 32, 360,  0 );
	mp[ "Megidolaon" ] = ataque( 2, 60, 420,  0 );
	mp[ "BlackViper" ] = ataque( 2, 64, 440,  0 );
	mp[  "Tarukaja"  ] = ataque( 0, 12,  25,  1 );
	mp[  "Rakukaja"  ] = ataque( 0, 12,  25,  2 );
	mp[   "Tarunda"  ] = ataque( 0, 12,  25,  4 );
	mp[   "Rakunda"  ] = ataque( 0, 12,  25,  8 );
}

void B( monster *a, monster *b, ataque k ){
	if( !k.op ){
		if( a -> mp < k.cost ) return;
		a -> mp -= k.cost;
		int d = k.debuf;
		if( d < 4  )
			a -> debuf |= k.debuf;
		else
			b -> debuf |= k.debuf;
	}
	else if( k.op == 1 ){
		double atk = a -> atk, def = b -> def;
		int diff = a -> lvl - b -> lvl;
		if( a -> debuf & 1 ) atk *= 1.25;
		if( a -> debuf & 4 ) atk *= 0.75;
		if( b -> debuf & 2 ) def *= 1.25;
		if( b -> debuf & 8 ) def *= 0.75;
		
		double dano = 5 * sqrt( (atk/def) * k.power ) * ( 1 + diff * 0.1 );
		b -> hp -= dano;
		a -> hp *= ( 100 - k.cost )/100.0;
		a -> debuf &=  (~5);
		b -> debuf &= (~10);
	}
	else{
		if( a -> mp < k.cost ) return;
		double atk = a -> mag, def = b -> def;
		int diff = a -> lvl - b -> lvl;
		if( b -> debuf & 2 ) def *= 1.25;
		if( b -> debuf & 8 ) def *= 0.75;
		
		double dano = 5 * sqrt( (atk/def) * k.power ) * ( 1 + diff * 0.1 );
		b -> hp -= dano;
		a -> mp -= k.cost;
		b -> debuf &= (~10);
	}
}

int main(){
	monster a, b;
	string atq;
	init();
	while( a.scan() ){
		b.scan();
		bool turn = 1, aux = 0;
		while( cin >> atq ){
			if( turn ) B( &a, &b, mp[atq] );
			else B( &b, &a, mp[atq] );
			if( a.hp <= 0 || b.hp <= 0 ) break;
			turn ^= 1;
		}
		if( b.hp <= 0 ) swap( a, b );
		a.print(); b.print();
		
	}
}
