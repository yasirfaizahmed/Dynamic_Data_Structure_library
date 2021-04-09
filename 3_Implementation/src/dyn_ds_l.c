/******************************************************************
USERDEFINED SOURCE C FILE INCLUDES FUNCTION DEFINTIONS

---Include it in the directory where the source code is present.
---The data-type of the structure members can be costomized from the structure definition at line-15.
******************************************************************/


#include "dyn_ds_l.h"


/************************ Function definitions ******************/
int sll_append( sll_node **ROOT, int data ){	//appends an element at the end
    sll_node* temp = (sll_node*) malloc(sizeof(sll_node));    //dynamic allocation
    if( temp == NULL ) return -1;   //if failed allocation

    temp->data = data;
    if( *ROOT == NULL ){
        *ROOT = temp;
        temp->link = NULL;
    }
    else{
        sll_node* p = *ROOT;
        while( p->link != NULL ) p = p->link;
        p->link = temp;
        temp->link = NULL;
    }

    return 1;
}

void sll_print_all( sll_node* root ){ 	//prints all the data in SLL
    sll_node* temp = root;
    if( root == NULL ) printf("\n Singly-linked list is empty!!\n\n");
    else{
        printf("\n");
        while( temp->link != NULL ){
            printf("%d-->", temp->data);
            temp = temp->link;
        }
    }
    printf("%d\n", temp->data);
}

int sll_len(sll_node* root){    //returns length of SLL
    int len = 0;
    sll_node* temp = root;
    while( temp->link != NULL ){
        temp = temp->link;
        len++;
    }
    if( temp->link == NULL ) len++;

    return len;
}

int sll_add_at_begining( sll_node** ROOT, int data ){    //adds an element at begening
    sll_node* temp = (sll_node*) malloc(sizeof(sll_node));
    if( temp == NULL ) return -1;

    temp->data = data;
    temp->link = NULL;
    if( *ROOT == NULL ) *ROOT = temp;
    else{
        temp->link = *ROOT;
        *ROOT = temp;
    }

    return 1;
}

int sll_add_at_position( sll_node** ROOT, int pos, int data ){	//adds element at given position
    if( pos > sll_len(*ROOT) ) return -1;
    if( pos == 1 ) sll_add_at_begining(ROOT, data);
    if( pos == sll_len(*ROOT)-1 ) sll_append(ROOT, data);
    else{
        sll_node* temp = (sll_node*) malloc(sizeof(sll_node));
        temp->data = data;
        if( temp == NULL ) return -1;
        else{
            sll_node* p = *ROOT;
            int index = 0;
            while( index != pos-1 ){
                p = p->link;
                index++;
            }
            // swap operation
            sll_node* q = p->link;
            p->link = temp;
            temp->link = q;
        }
    }

    return 1;
}

int sll_delete_begining( sll_node** ROOT ){	//deletes element at begining
	if( *ROOT == NULL ) return -1; 
	else {
		sll_node* temp = *ROOT;
		*ROOT = temp->link;
		temp->link = NULL;
		free(temp);
	}
	
	return -1;
}

