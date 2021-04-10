/******************************************************************

USERDEFINED SOURCE C FILE INCLUDES FUNCTION DEFINTIONS

******************************************************************/

#include "dyn_ds_l.h"


/********************************* Function definitions ****************************/
/****************** Basic functions ********************************/
int q_push( q_node** FRONT_, q_node** REAR_, int data ){	//push operation
	q_node* temp = (q_node*) malloc(sizeof(q_node));
	if( temp == NULL ) return -1;
	else{
		temp->data = data;
		if( *FRONT_ == NULL ){
			*FRONT_ = temp;
			*REAR_ = temp;
			temp->link = NULL;
		}
		else{
			(*REAR_)->link = temp;
			*REAR_ = temp;
			temp->link = NULL;
		}
	}
	
	return 1;
}

void q_print_all( q_node* front_ ){	//prints the whole queue
	if( front_ == NULL ) printf("\nQueue is empty!!\n");
	q_node* p = front_;
	while( p->link != NULL ){
		printf("%d-->",p->data);
		p = p->link;
	}
	printf("%d\n", p->data);
}


int q_len( q_node* front_ ){	//returns the length of queue
	int len = 0;
	if( front_ == NULL ) return -1;
	q_node* p = front_;
	while( p->link != NULL ){
		len++;
		p = p->link;
	}
	len++;
	
	return len;
}

int q_pop( q_node** FRONT_ ){	//pops the first element
	int data = (*FRONT_)->data;
	q_node* temp = *FRONT_;
	*FRONT_ = (*FRONT_)->link;
	free(temp);	//freeing the node
	
	return data;

}

int q_peek( q_node* front_, int pos){	//peeks and returns the element
	int index = 0;
	q_node* p = front_;
	while( index < pos ){
		p = p->link;
		index++;
	}
	
	return p->data;
}



