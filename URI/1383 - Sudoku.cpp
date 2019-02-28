#include<iostream>
#include<map>
 
using namespace std;
 
int main(){
     
    map<int,int> mp;
     
    int n, m[10][10], t, x;
    int dx[10] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
    int dy[10] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
	bool aux;
     
    cin >> n;
     
    for(int a=1; a<=n; a++){
        aux = true;
        for(int i=0; i<9;i++){
            for(int j=0; j<9; j++){
                cin >> m[i][j];
            }
        }
         
        for(int i=0; i<9;i++){
            for(int j=0; j<9; j++){
                int b=m[i][j];
                mp[b]++;
            }
            if(mp.size()!=9) {
                aux=false;
                break;
            }
            mp.clear();
        }
         
        if(aux){
            for(int i=0; i<9;i++){
                for(int j=0; j<9; j++){
                    int b=m[j][i];
                    mp[b]++;
                }
                if(mp.size()!=9) {
                    aux=false;
                    break;
                }
                mp.clear();
            }
        }
         
        if(aux){
        	for(int k=0; k<9; k++){
                for(int i=dx[k]; i<dx[k]+3; i++){
                	for(int j=dy[k]; j<dy[k]+3; j++){
                		mp[m[i][j]]++;
					}
				}
			
				if(mp.size()!=9) {
		            aux=false;
		            break;
		        }
	            mp.clear();
	        }
        }
               
        cout << "Instancia "<< a << endl;
        if(aux) cout <<"SIM" << endl;
        else cout << "NAO" << endl;
        cout << endl;
    }
    return 0;
}
