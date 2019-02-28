#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

#define pb push_back
#define mp make_pair
#define MAXV 100001

int pai[MAXV];

typedef pair<int,int> ii;

priority_queue<pair<int,ii> > pq;

int S = 0;


void init(int v){
    for (int i=0; i <= v; i++)
        pai[i] = i; // inicialmente cada vertice esta no seu proprio conjunto
}

int findset(int i){ // retorna o conjunto que o elemento i pertence
    if (i != pai[i]) 
        pai[i] = findset(pai[i]); // i esta no mesmo conjunto de pai[i]
    return pai[i];
}
 
void unionset(int a, int b){
    int aa = findset(a); 
    int bb = findset(b);
    pai[bb] = aa; // aa se torna o pai do conjunto bb

}

bool sameset(int a, int b)
{
    return findset(a) == findset(b); // retorna true se os conjuntos que contem os elementos A e B é o mesmo
}

int main(){
    
    int n, m, u, v, w;
    
    cin>>n>>m;
    
    init(n);
   
    for(int i=0;i<m;i++){
    
        scanf("%d %d %d",&u,&v,&w);
        
        pq.push(make_pair(-w,ii(u,v)));
    
    }
    
    while(pq.size()!=0){
    
	    if(!sameset(pq.top().second.first, pq.top().second.second)){
	        
	         S += -pq.top().first;
	        
	        unionset(pq.top().second.first, pq.top().second.second);  
	        
	    }
	    pq.pop();
	}
    
    printf("%d\n", S);
    
    return 0;
}
