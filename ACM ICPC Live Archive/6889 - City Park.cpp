#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 450

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

struct point{
	int x, y, type, id;
	point(){};
	point( int _x, int _y, int _type, int _id ){
		x = _x, y = _y, type = _type, id = _id;
	}
};

bool cmpX( point a, point b ){
	if( a.x != b.x ) return a.x < b.x;
	if( a.y != b.y ) return a.y < b.y;
	if( a.type != b.type ) return a.type > b.type;
	return a.id < b.id;
}

bool cmpY( point a, point b ){
	if( a.y != b.y ) return a.y < b.y;
	if( a.x != b.x ) return a.x < b.x;
	if( a.type != b.type ) return a.type > b.type;
	return a.id < b.id;
}

int pai[50505];
ll area[50505];

void init(int v){
    for (int i=0; i <= v; i++)
        pai[i] = i;
}
 
int findset(int i ){
    if (i != pai[i]){ 
        pai[i] = findset(pai[i]);
    }
    return pai[i];
}
  
void unionset(int a, int b ){
    int aa = findset(a); 
    int bb = findset(b);
    area[aa] += area[bb];
    area[bb] = area[aa];
    pai[bb] = aa;
}
 
bool sameset(int a, int b){
    return findset(a) == findset(b);
}

int main(){
	int n, w, h, x, y;
	while( scanf("%d", &n ) != EOF ){
		init(n);
		vector<point> v;
		vector<ii> c;
		rep( i, 0, n ){
			scanf("%d%d%d%d", &x, &y, &w, &h );
			v.pb( point( x, y, 2, i ) );
			v.pb( point( x, y+h, 3, i ) );
			v.pb( point( x+w, y, 0, i ) );
			v.pb( point( x+w, y+h, 1, i ) );
			area[i] = w * h;
		}
		sort( all(v), cmpX );
		int last = v[0].x;	
		deque<int> d;
		d.pb( v[0].id );
		rep( i, 1, v.size() ){
			if( v[i].x == last ){
				if( v[i].type&1 ){
					if( v[i].id == d[0] ) d.pop_front();
					else d.pop_back(); 
				}
				else{
					if( d.size() ){
						c.pb( ii( d[0], v[i].id ) );
					}
					d.pb( v[i].id );
				}
			}
			else{
				last = v[i].x;
				d.pb(v[i].id);
			}
		} 
		sort( all(v), cmpY );
		d.pb( v[0].id );
		last = v[0].y;
		rep( i, 1, v.size() ){
			if( v[i].y == last ){
				if( v[i].type < 2 ){
					if( v[i].id == d[0] ) d.pop_front();
					else d.pop_back(); 
				}
				else{
					if( d.size() ){
						c.pb( ii( d[0], v[i].id ) );
					}
					d.pb( v[i].id );
				}
			}
			else{
				last = v[i].y;
				d.pb(v[i].id);
			}
		}
		ll maior = 0;
		rep( i, 0, c.size() ){
			int a = c[i].F, b = c[i].S;
			if( !sameset( a, b ) ){
				unionset( a, b );
			}
		}	
		rep( i, 0, n ) maior = max( maior, area[i]);
		printf("%lld\n", maior );	 
	}	
}
