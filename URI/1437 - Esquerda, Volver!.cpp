#include<iostream>
#include<math.h>
#include<iomanip>
 
using namespace std;
 
int main(){
     
    int n=1, aux, i;
    char c;
     
    while(n>0){
        cin>>n;
        i=0;
        if(n!=0){
            for(aux=0;aux<n;aux++){
                cin >> c;
                 
                switch(c){
                    case 'D': {
                        i=i+1;
                        break;
                    }
                                 
                    case 'E': {
                        i=i-1;
                        break;
                    }
                }
            }
             
            if(i>3) i=i%4;
            else if(i<0) while(i<0){
                i=i+4;
            }
             
            switch(i){
                case 0:{
                    cout << "N" << endl;
                    break;
                }
                case 1:{
                     cout << "L" << endl;
                    break;
                }
                case 2:{
                     cout << "S" << endl;
                    break;
                }
                case 3:{
                     cout << "O" << endl;
                    break;
                }
                 
            }
        }
    }
    return(0);
}
