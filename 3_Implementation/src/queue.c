/******************************************************************

USERDEFINED SOURCE C FILE INCLUDES FUNCTION DEFINTIONS


******************************************************************/

#include "dyn_ds_l.h"


/********************************* Function definitions ****************************/
/****************** Basic functions ********************************/
int q_push( q_node** ROOT, int data ){	//push operation
	q_node* temp = (q_node*) malloc(sizeof(q_node));
	if( temp == NULL ) return -1;
	else{
		temp->data = data;
		if( front_ == NULL ){
			front_ = temp;
			temp->link = NULL;
			rear_ = temp;
		}
		else{
			rear_->link = temp;
			rear_ = temp;
			temp->link = NULL;
		}
	}
	
	return 1;
}