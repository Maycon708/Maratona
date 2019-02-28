#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int flag;

struct tree{
	
	char info;
	struct tree *L;
	struct tree *R;	
	
};

typedef struct tree node;

void add( node **p, char v ){
	if( (*p) == NULL ){
		(*p) = (node*) malloc( sizeof( node ) );
		if( (*p) ){
			(*p) -> info =	v;
			(*p) -> L = NULL;
			(*p) -> R = NULL;	
		}
	}
	else{
		if( v < (*p) -> info )
			add( &(*p) -> L, v );
		else
			add( &(*p) -> R, v );
	}
	
}

int search( node* p, char v ){
	if( p == NULL ) return 0;
	else if( v == ( p -> info ) ) return 1;
	else if( v < ( p -> info ) )
		search( p -> L, v );
	else
		search( p -> R, v );
}

void Prefixa( node* p ){

	if( p == NULL ) return;
	
	if( p -> info ){
		if( flag ) printf(" ");
		flag = 1;
		printf("%c", p -> info );
	}
	Prefixa( p -> L );
	Prefixa( p -> R );

}

void Posfixa( node* p ){

	if( p == NULL ) return;
	
	Posfixa( p -> L );
	Posfixa( p -> R );
	
	if( p -> info ){
		if( flag ) printf(" ");
		flag = 1;
		printf("%c", p -> info );
	}
}

void Infixa( node* p ){	
	if( p == NULL ) return;
	
	Infixa( p -> L );
	
	if( p -> info ){
		if( flag ) printf(" ");
		flag = 1;
		printf("%c", p -> info );
	}
	Infixa( p -> R );
}

int main(){

	node* p = (node*) malloc( sizeof( node ) );
	char op[100], v;	
	
	while( scanf(" %s", op) != EOF ){
				
		if( !strcmp( op, "I" ) ){ 
			scanf( " %c", &v); 
			add( &p, v );
		}
		else if( !strcmp( op, "P") ){
			scanf(" %c", &v);
			printf("%c %s\n", v, ( search(p, v) ) ? "existe": "nao existe" );
		}
		else if( !strcmp( op, "INFIXA" ) ){
			flag = 0;
			Infixa(p);
			printf("\n");
		}
		else if( !strcmp( op, "POSFIXA" ) ){
			flag = 0;
			Posfixa(p);
			printf("\n");
		}
		else if( !strcmp( op, "PREFIXA" ) ){
			flag = 0;
			Prefixa(p);
			printf("\n");
		}
	
	}

}
