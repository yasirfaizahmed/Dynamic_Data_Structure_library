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
int sll_append( sll_node **ROOT, int data );
void sll_print_all( sll_node *root );
int sll_len( sll_node* root );
int sll_add_at_begining( sll_node** ROOT, int data );
int sll_add_at_position( sll_node** ROOT, int pos, int data );
int sll_delete_begining( sll_node** ROOT );
int sll_delete_at_position( sll_node** ROOT, int pos );

#endif // DYN_DS_L_H_INCLUDED
