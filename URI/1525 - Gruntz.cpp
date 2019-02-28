#include<bits/stdc++.h>
  
using namespace std;

typedef pair<int, int> ii;
  
int l, h, k;
char m[200][200];
bool vis[200][200][300];
int aux_x[] = {1, -1, 0, 0};
int aux_y[] = {0, 0, 1, -1};
  
bool dentro (int x, int y){
    return (x>=0 && x<h && y>=0 && y<l);
}
  
queue < pair< ii, int> > q;  
  
bool percorre (){
      
    int a=0, b=0, x=0, y=0;
      
    while(!q.empty()){
     
        int xx = q.front().first.first;
        int yy = q.front().first.second;
        int c = q.front().second;
        
 //     cout << c << endl;      
        
        q.pop();
        
        switch (m[xx][yy]){
            case '>':{
                a=0; b=1;
                break;
            }
            case '<':{
                a=0; b=-1;
                break;
            }
            case 'v':{
                a=1; b=0;
                break;
            }
            case '^':{
                a=-1; b=0;
                break;
            }
            case 'x':{
                return true;
                break;
            }
        }
        
        if(dentro(xx+a, yy+b) && !vis[xx+a][yy+b][c]){
            vis[xx+a][yy+b][c] = true;
            q.push(make_pair(ii(xx+a,yy+b), c));
        
        }   
        if(c<k){
            if(dentro(xx-a, yy-b) && !vis[xx-a][yy-b][c+1]){
                    vis[xx-a][yy-b][c+1] = true;
                    q.push(make_pair(ii(xx-a,yy-b), c+1));
            }       
        }
        
              
    }
    return false;
}
  
int main(){
      
    int x, y;
      
      
    while(cin >> h >> l >> k && l+h+k){
        
        while(!q.empty()) q.pop();
          
        for(int i=0; i<h; i++){
            for(int j=0; j<l; j++){
                cin >> m[i][j];
                for(int ij=0; ij<=k; ij++) vis[i][j][ij] = false;
                if(i==0 || j==0 || i==h-1 || j==l-1) q.push(make_pair(ii(i,j), 0));
            }
        }
          
        if(percorre()) cout<<"Sim"<<endl;
        else cout<<"Nao"<<endl;
          
    }
      
    return 0;
}
