#include<bits/stdc++.h>
 
using namespace std;
 
int l, h;
char m[200][200];
bool vis[200][200];
 
bool dentro (int x, int y){
    return (x>=0 && x<h && y>=0 && y<l);
}
 
bool percorre (){
     
    int a=0, b=0, x=0, y=0;
     
    while(1){
        if(dentro(x, y)){
            vis[x][y]=true;
            switch (m[x][y]){
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
                case '*':{
                    return true;
                    break;
                }
            }
             
            if(!vis[x+a][y+b]){
                x+=a;
                y+=b;
            }
            else return false;
        }
        else return false;
     
    }
}
 
int main(){
     
    int x, y;
     
     
    while(cin >> l){
        cin >> h;
         
        for(int i=0; i<h; i++){
            for(int j=0; j<l; j++){
                cin >> m[i][j];
                vis[i][j]=false;
            }
        }
         
        if(percorre()) cout<<"*"<<endl;
        else cout<<"!"<<endl;
         
    }
     
    return 0;
}
