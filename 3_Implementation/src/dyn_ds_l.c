/******************************************************************
USERDEFINED SOURCE C FILE INCLUDES FUNCTION DEFINTIONS

---Include it in the directory where the source code is present.
---The data-type of the structure members can be costomized from the structure definition at line-15.
******************************************************************/


#include "dyn_ds_l.h"


/************************ Function definitions ******************/
int sll_append(sll_node **ROOT, int d){
    sll_node* temp = NULL;
    temp = (sll_node*) malloc(sizeof(sll_node));    //dynamic allocation
    if( temp == NULL ) return -1;   //if failed allocation

    temp->data = d;
    if( *ROOT == NULL ){
        *ROOT = temp;
        temp->link = NULL;
    }
    else{
        sll_node* p = *ROOT;
        while( p->link != NULL) p = p->link;
        p->link = temp;
        temp->link = NULL;
    }

    return 1;
}

void sll_printall(sll_node* root){
    sll_node* temp = root;
    if(root == NULL) printf("\n Singly-linked list is empty!!\n\n");
    else{
        printf("\n");
        while( temp->link != NULL ){
            printf("%d-->", temp->data);
            temp = temp->link;
        }
    }
    printf("%d", temp->data);
}

