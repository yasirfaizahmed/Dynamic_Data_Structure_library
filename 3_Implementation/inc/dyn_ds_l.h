/*****************************************************************************************

USERDEFINED HEADER INVLUDES MACRO DEFINITIONS, FUNCTION PROTOTYPING AND OTHER DEFINITIONS

****************************************************************************************/

#ifndef DYN_DS_L_H_INCLUDED
#define DYN_DS_L_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

/****************************** structure defintions *************************/
/************************** SLL structure ************************/
typedef struct sll_node{	//Singly-linked list structure typedef
    int data;
    struct sll_node* link;
}sll_node;


/************************** Queue structure, defines ************/
typedef struct q_node{
	int data;
	struct q_node* link;
}q_node;




/****************************** Function prototypings *************************/
/****************** SLL functions **********************************/
/****************** Basic functions ********************************/
int sll_append( sll_node **ROOT, int data );
void sll_print_all( sll_node *root );
int sll_len( sll_node* root );
int sll_add_at_begining( sll_node** ROOT, int data );
int sll_add_at_position( sll_node** ROOT, int pos, int data );
int sll_delete_begining( sll_node** ROOT );
int sll_delete_at_position( sll_node** ROOT, int pos );
int sll_swap_data( sll_node** ROOT, int pos1, int pos2 );
int sll_reverse_list( sll_node** ROOT );
int sll_peek( sll_node* root, int pos );
int sll_overwrite( sll_node** ROOT, int pos, int data );

/****************** Advanced functions ***************************/
int sll_sort_bubble( sll_node** ROOT, char mode );	//bubble sorts, mode = a{assending}, mode = d{descending}
int sll_sort_insertion( sll_node** ROOT );	//insertion sort	(need to work on it)
sll_node* sll_return_address(sll_node *ROOT, int pos);	//returns the address of the node at given position


/****************** Queue functions **********************************/
int q_push(q_node** FRONT_, q_node** REAR_, int data);	//push operation
void q_print_all( q_node* front_ );	//prints the whole queue
int q_len( q_node* front_ );	//returns the length of queue
int q_pop( q_node** FRONT_ );	//pops the first element
int q_peek( q_node* front_, int pos );	//peeks and returns the element at given position








#endif // DYN_DS_L_H_INCLUDED
