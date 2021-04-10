/******************************************************************

USERDEFINED SOURCE C FILE INCLUDES FUNCTION DEFINTIONS

******************************************************************/

#include "dyn_ds_l.h"


/********************************* Function definitions ****************************/
/****************** Basic functions ********************************/
int bst_append( bst_node** ROOT, int data ){	//adds element to BST accordingly
	bst_node* temp = (bst_node*) malloc(sizeof(bst_node));
	if( temp == NULL ) return -1;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	if( *ROOT == NULL ) *ROOT = temp;
	else{
		bst_node* current = *ROOT;
		bst_node* parent;
		while( current != NULL ){
			parent = current;
			if( data > current->data ) current = current->right;
			else current = current->left;
		}
		if( data > parent->data ) parent->right = temp;
		else parent->left = temp;
	}
	
	return 1;
}

void bst_print_all( bst_node* root, int space ){	//prints the whole SBT (I've copied this function totally from Stackoverflow, LOL !!)
	if( root == NULL ) return;
	space += COUNT;
	bst_print_all(root->right, space);
	printf("\n");
	for(int i=COUNT;i<space;i++) printf(" ");
	printf("%d\n", root->data);
	bst_print_all(root->left, space);
}

bst_node* bst_search_parent(bst_node **ROOT, int data, char mode){	//returns address of node p{parent}, c{current}
    bst_node *temp = *ROOT;
    if( data == temp->data ) return *ROOT;
    while( temp != NULL ){
        if( mode == 'p' ){
            if( temp->left != NULL ) if( data == temp->left->data ) return temp;
            if( temp->right != NULL ) if( data == temp->right->data ) return temp;

            if( data > temp->data ) temp = temp->right;
            else temp = temp->left;
        }
        if(mode == 'c'){
            if( data == temp->data ) return temp;

            if( data > temp->data ) temp = temp->right;
            else temp = temp->left;
        }
    }

    return NULL;
}


