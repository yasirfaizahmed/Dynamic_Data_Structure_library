/*****************************************************************************************************

						                      UNITY TEST FILE

*******************************************************************************************************/

//#include "dyn_ds_l_test.h"
#include "dyn_ds_l.h"
#include "unity.h"
#include <stdio.h>
#include <stdlib.h>


/********************* definitiosn for other libs to work *****************************/
sll_node* sll_root = NULL;	//lets start with an empty SLL
sll_node* root = NULL;	//lets start with an empty SLL
sll_node* temp = NULL;	//for moving accross the LLs
int pos = 0;	//just a testing poition value to work with SLL
int actual_val;	//for testing ASSERTS
int rand_val;

q_node* front_ = NULL;
q_node* rear_ = NULL;
int actual_len;
int data;

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}


/************************* test functions prototyping **************************/
/****************** SLL test functions ********************************/
void test_sll_append( void );	
void test_sll_len( void );
void test_sll_add_at_begining( void );	
void test_sll_add_at_position( void );
void test_sll_delete_begining( void );
void test_sll_delete_at_position( void );
void test_sll_swap_data( void );
void test_sll_reverse_list( void );
void test_sll_peek( void );
void test_sll_overwrite( void );
void test_sll_sort_bubble( void );

/****************** Queue test functions ********************************/
void test_q_push( void );	
void test_q_print_all( void );	
void test_q_len( void );	
void test_q_pop( void );
void test_q_peek( void );	

/***************** test functions definitions **************************************/
/******************* SLL test function definitions**************/
void test_sll_append( void ){	//testing sll_append
	rand_val = rand();	//generating random value
	sll_append(&sll_root, rand_val);	//appending that random value
	temp = sll_root;			
	while( temp->link != NULL )temp = temp->link;	//going to the last node to fetch
	actual_val = temp->data;
	temp = NULL;	//releasing the pointer
	TEST_ASSERT(rand_val == actual_val);	//comparing to the last node's actual value to rand_value
	
}

void test_sll_len( void ){	//testing sll_len function
	temp = sll_root;
	actual_val = 0;
	while( temp->link != NULL ){
		temp = temp->link;
		actual_val++;
	}
	actual_val++;
	temp = NULL;	//releasing the pointer
	TEST_ASSERT(actual_val == sll_len(sll_root));
	
}

void test_sll_add_at_begining( void ){
	rand_val = rand();
	sll_add_at_begining(&sll_root, rand_val);
	temp = sll_root;
	actual_val = temp->data;	//first element value
	temp = NULL;	//releasing the pointer
	TEST_ASSERT(actual_val == rand_val);
	
}

void test_sll_add_at_position( void ){
	rand_val = rand();
	sll_add_at_position(&sll_root, ++pos, rand_val);
	temp = sll_root;
	int index = 0;
	while( index != pos ){
		temp = temp->link;
		index++;
	}
	actual_val = temp->data;
	temp = NULL;
	TEST_ASSERT(actual_val == rand_val);
	
}

void test_sll_delete_begining( void ){
	TEST_ASSERT_EQUAL(1, sll_delete_begining(&sll_root));
	TEST_ASSERT_EQUAL(1, sll_delete_begining(&sll_root));
	TEST_ASSERT_EQUAL(1, sll_delete_begining(&sll_root));

}

void test_sll_delete_at_position( void ){
	sll_append(&sll_root, rand());
	sll_append(&sll_root, rand());
	sll_append(&sll_root, rand());		//adding some elements so that the LL is always filled and not empty
	sll_append(&sll_root, rand());
	sll_append(&sll_root, rand());
	pos = sll_len(sll_root);
	TEST_ASSERT_EQUAL(1, sll_delete_at_position(&sll_root, --pos));
	TEST_ASSERT_EQUAL(1, sll_delete_at_position(&sll_root, --pos));
	TEST_ASSERT_EQUAL(1, sll_delete_at_position(&sll_root, --pos));
}

void test_sll_swap_data( void ){
	TEST_ASSERT_EQUAL(1, sll_swap_data(&sll_root, 0, sll_len(sll_root)-1));
	TEST_ASSERT_EQUAL(1, sll_swap_data(&sll_root, 0, sll_len(sll_root)-1));
	TEST_ASSERT_EQUAL(1, sll_swap_data(&sll_root, 0, sll_len(sll_root)-1));
}

void test_sll_reverse_list( void ){
	TEST_ASSERT_EQUAL(1, sll_reverse_list(&sll_root));
}
	
void test_sll_peek( void ){	
	temp = sll_root;
	pos = 0;
	int index = 0;	//peeking at index 0
	while( index != pos ){
		temp = temp->link;
		index++;
	}
	actual_val = temp->data;
	temp = NULL;
	TEST_ASSERT(actual_val == sll_peek(sll_root, pos));
}

void test_sll_overwrite( void ){
	pos = 0;	//overwriting at position 0
	TEST_ASSERT_EQUAL(1, sll_overwrite(&sll_root, pos, 69));
}

void test_sll_sort_bubble( void ){
	TEST_ASSERT_EQUAL(1, sll_sort_bubble(&sll_root, 'a'));
	TEST_ASSERT_EQUAL(1, sll_sort_bubble(&sll_root, 'd'));
}


/******************* Queue test function definitions**************/
void test_q_push( void ){
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));actual_len++;
}

void test_q_len( void ){
	TEST_ASSERT_EQUAL(actual_len, q_len(front_));
}

void test_q_pop( void ){
	TEST_ASSERT_EQUAL(1, q_pop(&front_));actual_len--;
	TEST_ASSERT_EQUAL(2, q_pop(&front_));actual_len--;
	TEST_ASSERT_EQUAL(3, q_pop(&front_));actual_len--;
	TEST_ASSERT_EQUAL(4, q_pop(&front_));actual_len--;
}

void test_q_peek( void ){
		TEST_ASSERT_EQUAL(5, q_peek(front_, pos++));
		TEST_ASSERT_EQUAL(6, q_peek(front_, pos++));
		TEST_ASSERT_EQUAL(7, q_peek(front_, pos++));
		TEST_ASSERT_EQUAL(8, q_peek(front_, pos));
}


/******************* Queue test function definitions**************/



int main(){
	UNITY_BEGIN();	//initilize the uinity framework
	//RUN_TEST macro needs function pointer, in our case for eg. test_sll_append (function name is also a function pointer, hehehe)
	
	
	RUN_TEST(test_sll_append);
	
	RUN_TEST(test_sll_len);
	
	RUN_TEST(test_sll_add_at_begining);
	
	RUN_TEST(test_sll_add_at_position);
	
	RUN_TEST(test_sll_delete_begining);
	
	RUN_TEST(test_sll_delete_at_position);
	
	RUN_TEST(test_sll_swap_data);
	
	RUN_TEST(test_sll_reverse_list);
	
	RUN_TEST(test_sll_peek);
	
	RUN_TEST(test_sll_overwrite);
	
	RUN_TEST(test_sll_sort_bubble);
	
	
	RUN_TEST(test_q_push);
	
	RUN_TEST(test_q_len);
	
	RUN_TEST(test_q_pop);
	
	RUN_TEST(test_q_peek);
	
	return UNITY_END();
	
}


