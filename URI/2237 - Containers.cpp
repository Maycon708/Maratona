#include<bits/stdc++.h>

#define rep( i, a, b ) for( int i = a; i < b; i++ )
#define mk make_pair
#define F first
#define S second

using namespace std;

typedef long long int ll;

int aa[] = { 0, 0, 1, 1, 2, 2, 3, 4, 5, 6 };
int bb[] = { 1, 4, 2, 5, 3, 6, 7, 5, 6, 7 };

struct Q{
    int v[8];
    Q(){};
    void scan(){
        rep( i, 0, 8 ) scanf("%d", &v[i] );
    }
    bool operator < ( Q a ) const{
        rep( i, 0, 8 ){
            if( v[i] != a.v[i] ) return v[i] < a.v[i];
        }
        return 0;
    }
    bool operator == ( Q a ) const{
        rep( i, 0, 8 ){
            if( v[i] != a.v[i] ) return 0;
        }
        return 1;
    }
    void debug(){
    	rep( i, 0, 8 ) printf("%d ", v[i] );
    	printf("\n");
	}
};

int dijkstra( Q a, Q b ){
    priority_queue< pair< int, Q > > pq;
    pq.push( mk( 0, a ) );    
    
	map< Q, int > dist;
    
    while( !pq.empty() ){
    	Q u = pq.top().S;
    	int c = -pq.top().F;
    	pq.pop();
		if( u == b ) return c;
    	if( dist[u] != c ) continue;
    	rep( i, 0, 10 ){
			Q w = u;
			swap( w.v[ aa[i] ], w.v[ bb[i] ] );

			int d_u_w = w.v[ aa[i] ] + w.v[ bb[i] ];
			if( !dist.count(w) || dist[w] > c + d_u_w ){
				int k = d_u_w + c;
				dist[w] = k;
				pq.push( mk( -dist[w], w ) );
    		}
		}
	}
}

int main(){
	Q a, b;
	a.scan();
	b.scan();
	if( a == b ) puts("0");
	else printf("%d\n", dijkstra( a, b ) );
}
