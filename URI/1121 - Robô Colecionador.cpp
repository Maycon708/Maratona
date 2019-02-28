#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int N,M,S,figurinhas, X, Y;
    char arena[200][200], instrucoes[50500], orientacao, linha[200];

    cin>>N>>M>>S;
    while(N!=0 || M!=0 || S!=0){
        figurinhas=0;
        getchar();
        for(int i=0; i<N; i++){
            gets(linha);
            for(int j=0; j<M; j++){
                arena[i][j]=linha[j];
                if(arena[i][j]=='N'||arena[i][j]=='L'||arena[i][j]=='O'||arena[i][j]=='S'){
                    orientacao=arena[i][j];
                    X=i;
                    Y=j;
                }
            }
        }
        gets(instrucoes);
        for(int i=0; i<S; i++){
                if(instrucoes[i]=='F'){
                    if(orientacao=='L'){
                        if(Y<M-1 && arena[X][Y+1]!='#'){
                                Y++;
                                if(arena[X][Y]=='*'){
                                    figurinhas++;arena[X][Y]='.';
                                }
                        }
                    }
                    else{
                        if(orientacao=='S'){
                            if(X<N-1 && arena[X+1][Y]!='#'){
                                X++;
                                if(arena[X][Y]=='*'){
                                    figurinhas++;arena[X][Y]='.';

                                }
                            }
                        }
                        else{
                            if(orientacao=='N'){
                                if(X>0 && arena[X-1][Y]!='#'){
                                    X--;
                                    if(arena[X][Y]=='*'){
                                        figurinhas++;arena[X][Y]='.';

                                    }
                                }
                            }
                            else{
                                if(orientacao=='O'){
                                    if(Y>0 && arena[X][Y-1]!='#'){
                                        Y--;
                                        if(arena[X][Y]=='*'){
                                            figurinhas++;arena[X][Y]='.';

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else{
                    if(instrucoes[i]=='D'){
                        if(orientacao=='L')orientacao='S';
                        else if(orientacao=='S')orientacao='O';
                             else if(orientacao=='O')orientacao='N';
                                  else if(orientacao=='N')orientacao='L';
                    }
                    else{
                        if(instrucoes[i]=='E'){
                            if(orientacao=='L')orientacao='N';
                            else if(orientacao=='S')orientacao='L';
                                 else if(orientacao=='O')orientacao='S';
                                      else if(orientacao=='N')orientacao='O';
                        }
                    }
                }
        }
        cout<<figurinhas<<endl;
        cin>>N>>M>>S;
    }

    return 0;
}
