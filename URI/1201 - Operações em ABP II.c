#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int flag;
 
struct tree{
     
    int info;
    struct tree *L;
    struct tree *R; 
     
};
 
typedef struct tree node;
 
void add( node **p, int v ){
    if( (*p) == NULL ){
        (*p) = (node*) malloc( sizeof( node ) );
        if( (*p) ){
            (*p) -> info =   v;
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
 
int search( node* p, int v ){
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
        printf("%d", p -> info );
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
        printf("%d", p -> info );
    }
}
 
void Infixa( node* p ){ 
    if( p == NULL ) return;
     
    Infixa( p -> L );
     
    if( p -> info ){
        if( flag ) printf(" ");
        flag = 1;
        printf("%d", p -> info );
    }
    Infixa( p -> R );
}

node * minValueNode( node* no){
    node* current = no;
 
    /* loop down to find the leftmost leaf */
    while (current-> R != NULL)
        current = current-> R;
 
    return current;
}
/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
node* deleteNode( node* root, int key){
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key > root->info)
        root -> R = deleteNode(root-> R, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key < root -> info )
        root -> L = deleteNode( root -> L, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root-> R == NULL)
        {
            node *temp = root-> L;
            free(root);
            return temp;
        }
        else if (root -> L == NULL)
        {
            node *temp = root-> R;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node* temp = minValueNode( root -> L );
 
        // Copy the inorder successor's content to this node
        root-> info = temp -> info;
 
        // Delete the inorder successor
        root-> L = deleteNode(root-> L, temp-> info);
    }
    return root;
}
 
int main(){
 
    node* p = (node*) malloc( sizeof( node ) );
    char op[100];
    int  v;    
     
    while( scanf(" %s", op) != EOF ){
                 
        if( !strcmp( op, "I" ) ){ 
            scanf( "%d", &v); 
            add( &p, v );
        }
        else if( !strcmp( op, "P") ){
            scanf("%d", &v);
            printf("%d %s\n", v, ( search(p, v) ) ? "existe": "nao existe" );
        }
        else if( !strcmp( op, "R") ){
            scanf("%d", &v);
            p = deleteNode( p, v );
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
