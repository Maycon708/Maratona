#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

struct ponto{
	int x, y;
};

typedef ponto vetor;

struct reta{
	ponto A, B;
};

typedef reta segmento;

/*
	Encontra o vetor AB
	AB = B - A;
	Portanto:
	AB.x = B.x - A.x
	AB.y = B.y - A.y
*/
vetor calc( ponto a, ponto b ){
	vetor v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	return v;
}

/*
	Retorna o produto vetorial A x B
	|   x   y  z  | 
	| A.x A.y  0  |
	| B.x B.y  0  |
	
	OBS.: Ambos os vetores estão no plano, considerando o plano z = 0 facilita os calculos 
	
	O calculo do determinante então seria:
	D = (0*A.y)x + (0*B.x)y + (A.x*B.y)z - (A.y*B.x)z - (0*B.y)x - (0*A.x)y
	Simplificando:
	D = (A.x*B.y - A.y*B.x)z
	
	Como sabemos que o resultado sempre vai estar no eixo z, podemos retornar apenas um número inteiro correspondente ao valor dessa componente z
	
	Análise do resultado:
		< 0: Vetor resultante entrando no plano
		= 0: Vetor resultante nulo, pontos colineares
		> 0: Vetor resultante saindo do plano  
	
*/
int vetorial( vetor a, vetor b ){
	return a.x * b.y - a.y * b.x;
}

/* 
	Retorna o produto escalar A.B
	A . B = A.x * B.x + A.y * B.y

*/
int escalar( vetor a, vetor b ){
	return a.x * b.x + a.y * b.y;
}

/*	
	Dados 3 pontos, a função calcula se eles estão em sentido horário, anti-horário ou se são colineares
	Retorno:
		-1 se estão em sentido horário
		0 se são colineares
		1 se estão em sentido anti-horário
	
	Funcionamento:
		Calcula o vetor de A para B e de A para C 
		Calcula o produto vetorial AB x AC
		Com base na analise do sinal do produto vetorial podemos notar que:
			AB x AC < 0 se os pontos A, B e C estão em sentido horário 
			AB x AC > 0 se os pontos A, B e C estão em sentido anti-horário
			AB x AC = 0 se os pontos A, B e C são colineares
			
*/

int sentido( ponto A, ponto B, ponto C){
	vetor AB, AC;
	int z;
	
	AB = calc(A, B);
	AC = calc(A, C);
	z = vetorial(AB, AC);
	
	if( z < 0 )	return -1;			// Sentido horário	
	else if( z > 0 ) return 1;		// Sentido Anti-horário
	else return 0;					// Colineares
	
}

double dist( ponto A, ponto B ){
	vetor AB = calc(A, B);
	return hypot(AB.x, AB.y);
}

void fechoConvexo( ponto *P, int &n ){
	
	ponto fecho[n+1];
	int t, i, j;
	
	for( i = 0; i < n; i++ ){
		if( P[i].y < P[0].y || P[i].y == P[0].y && P[i].x < P[0].x ){
			swap( P[i], P[0] );
		}
	}
	for( i = 1; i < n; i++ ){
		for( j = i+1; j < n; j++ ){
			if( sentido(P[0], P[i], P[j]) == -1 ) swap(P[i], P[j]);
			if( sentido(P[0], P[i], P[j]) == 0 && dist(P[0], P[i]) > dist(P[0], P[j]) ) swap(P[i], P[j]);
		}
	}
	
	P[n++] = P[0];
	fecho[0] = P[0];
	fecho[1] = P[1];
	t = 2;
	i = 2;
	
	while( i < n ){
		if( t <= 1 || sentido(fecho[t-2], fecho[t-1], P[i]) == 1 ){
			fecho[t] = P[i++];
			t++;
		}
		else{
			t--;
		} 
	}
	
	memcpy( P, fecho, sizeof fecho );
	n = t;
}

int main(){
	int n;
	ponto P[2020];
	while( scanf("%d", &n ) != EOF && n ){
		for( int i = 0; i < n; i++ ){
			scanf("%d%d", &P[i].x, &P[i].y );
		}
		fechoConvexo(P, n);
		double ans = 0;
		for( int i = 0; i < n-1; i++ ) ans = ans + dist(P[i], P[i+1]);
		printf("Tera que comprar uma fita de tamanho %.2f.\n", ans );
	}
}

