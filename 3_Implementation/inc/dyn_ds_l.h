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
typedef struct sll_node{
    int data;
    struct sll_node* link;
}sll_node;


/****************************** Function prototypings *************************/
int sll_append( sll_node **ROOT, int d );
void sll_printall( sll_node *root);


#endif // DYN_DS_L_H_INCLUDED
