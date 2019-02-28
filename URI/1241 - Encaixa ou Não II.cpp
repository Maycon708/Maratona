#include<iostream>
#include<cstring>
 
using namespace std;
 
int main(){
     
    int n, tb, ta;
    char a[1001], b[1001];
    bool aux;
     
    cin >> n;
     
    while(n--){
        aux = true;
        cin >> a >> b;
         
        ta=strlen(a);
        tb=strlen(b);
         
        for(int i=1; i<=tb; i++){
            if(a[ta-i]!=b[tb-i]){
                aux = false;
                break;
            }
        }
        if(aux) cout << "encaixa" << endl;
        else cout << "nao encaixa" << endl;
         
    }
     
    return(0);
}
