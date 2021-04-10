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
	
	return 1;
}

int sll_delete_at_position( sll_node** ROOT, int pos ){	//deletes element at passed position
	if( pos > sll_len(*ROOT) ) return -1;
	if( *ROOT == NULL )	return -1;
	if( pos == 1 ) sll_delete_begining(ROOT);
	else{
		sll_node* p = *ROOT;
		int index = 0;
		while( index != pos-1 ){
			p = p->link;
			index++;
		}
		//swap operation
		sll_node* q = p->link;
		p->link = q->link;
		q->link = NULL;
		free(q);
	}
	
	return 1;
}

int sll_swap_data( sll_node** ROOT, int pos1, int pos2 ){	//swaps the data at pos1 with data at pos2
	if( *ROOT == NULL ) return -1;
	else{
		//goin to first position
		sll_node* temp1 = *ROOT;
		int index = 0, temp_data;
		while( index < pos1 ){
			temp1 = temp1->link;
			index++;
		}
		temp_data = temp1->data;
		
		//going to second position
		index = 0;
		sll_node* temp2 = *ROOT;
		while( index < pos2 ){
			temp2 = temp2->link;
			index++;
		}
		//swaping here
		temp1->data = temp2->data;
		temp2->data = temp_data;
		
	}
	
	return 1;
}


int sll_reverse_list( sll_node** ROOT ){	//reverses the SLL
	if( *ROOT == NULL ) return -1;
	else{
		int index = 0;
		int len = sll_len(*ROOT);
		while( index <= len/2 ){
			sll_swap_data(ROOT, index, (len-index-1));
			index++;
		}
	}
	
	return 1;
}

int sll_peek( sll_node* root, int pos ){	//peeks at position and returns it
	if( root == NULL ) return -1;
	sll_node* temp = root;
	if( pos > sll_len(root) ) return -1;
	else{
		int index = 0;
		while( index < pos ){
			temp = temp->link;
			index++;
		}
	}
	
	return temp->data;
}





