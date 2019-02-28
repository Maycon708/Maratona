#include<bits/stdc++.h>
 
using namespace std;

typedef pair<int,int> ii;

int n, m, matriz[10][10];

queue<pair<ii,int> >q; 
bool aux[11][11];
int cont=0;

int bfs(){
	
	while(!q.empty()){
	    
	    pair<ii,int> f = q.front();
		q.pop();
		int l=f.first.first;
		int h=f.first.second, d=f.second;
		
		if(matriz[l][h]==0) return d;
		
	    aux[l][h]=true;
	    
	    if(l+1<n && !aux[l+1][h] && matriz[l+1][h]!=2) {
			q.push(make_pair(ii(l+1,h),d+1));     
		 }
	    if(l-1>=0 && !aux[l-1][h] && matriz[l-1][h]!=2){
		     q.push(make_pair(ii(l-1,h),d+1));    
		 }
	    if(h+1<m && !aux[l][h+1] && matriz[l][h+1]!=2){
			q.push(make_pair(ii(l,h+1),d+1));     
		 }
	    if(h-1>=0 && !aux[l][h-1] && matriz[l][h-1]!=2){
			  q.push(make_pair(ii(l,h-1),d+1));     
		 }
	    

	}
}
 
int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		for(int j=0;  j<m; j++){
			scanf("%d", &matriz[i][j]);
			if(matriz[i][j]==3){
				q.push(make_pair(ii(i,j), 0));
			}
		}
		cout<<bfs()<<endl;
		
	
    return 0;
}
