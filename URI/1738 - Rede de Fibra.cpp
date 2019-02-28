#include<bits/stdc++.h>

#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int n, m[1000][1000];

void floyd(){
    
    rep(k,0,n)
        rep(i,0,n)
            rep(j,0,n)
                m[i][j] |= m[i][k] & m[k][j];
    
}

int main(){
    
    int ini, fim;
    char c[10000], aux[] = {"abcdefghijklmnopqrstuvwxyz"};
    
    while(cin >> n && n){
    	bool aux = true;
    	memset(m, 0, sizeof(m));
    	
        while(cin >> ini >> fim && ini+fim){
           scanf(" %s", c);       
//           cout << c << endl;
           int tam = strlen(c);
           ini --;
           fim --;
           for(int i=0; i<tam; i++){
               int pos = c[i] - 'a' ;
               m[ini][fim] |= 1 << pos;
           }
             
        }
        
        
        floyd();
        
        while(cin >> ini >> fim && ini+fim){
            aux = true; 
            ini--;
            fim--;
            for(int i=0; i<26; i++){
            	if(m[ini][fim] & 1 << i){
            		cout << char('a'+i);
            		aux = false;
				} 
			}
			if(aux) cout << "-";
            cout << endl;
        }
        cout << endl;
    }

}
