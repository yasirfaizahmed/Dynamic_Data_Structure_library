/*****************************************************************************************
USERDEFINED HEADER INVLUDES MACRO DEFINITIONS, FUNCTION PROTOTYPING AND OTHER DEFINITIONS

---Include it in the directory where the source code is present.
---The data-type of the structure members can be costomized from the structure definition at line-15.
****************************************************************************************/

#ifndef DYN_DS_L_H_INCLUDED
#define DYN_DS_L_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

/****************************** structure defintions *************************/
typedef struct sll_node{	//Singly-linked list structure typedef
    int data;
    struct sll_node* link;
}sll_node;


/****************************** Function prototypings *************************/
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






#endif // DYN_DS_L_H_INCLUDED
