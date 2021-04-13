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


int bst_delete( bst_node** ROOT, int data ){	//deletes the given data, if not in the tree then return 0
	bst_node* to_delete = bst_search_parent(ROOT, data, 'c');
	bst_node* parent = bst_search_parent(ROOT, data, 'p');
	
	if( to_delete->data < parent->data ){
		bst_node* temp = to_delete->left;	//search highest node in left sub-tree
		while( temp->right != NULL ) temp = temp->right;
		to_delete->data = temp->data;	//successor replacing the to_delete node
		bst_node *to_free = bst_search_parent(&to_delete, temp->data, 'p');	//getting the parent address to free the successor memory
		to_free->right = NULL;
		free(temp);
	}
	
}

void bst_inorder_traverse(struct bst_node* ROOT){
    if(ROOT == NULL) return;

    bst_inorder_traverse(ROOT->left);
    printf("%d ", ROOT->data);
    bst_inorder_traverse(ROOT->right);
}

void bst_preorder_traverse(struct bst_node* ROOT){
    if(ROOT == NULL) return;

    printf("%d ", ROOT->data);
    bst_preorder_traverse(ROOT->left);
    bst_preorder_traverse(ROOT->right);
}

void bst_postorder_traverse(struct bst_node* ROOT){
    if(ROOT == NULL) return;

    bst_postorder_traverse(ROOT->left);
    bst_postorder_traverse(ROOT->right);
    printf("%d ", ROOT->data);

}


