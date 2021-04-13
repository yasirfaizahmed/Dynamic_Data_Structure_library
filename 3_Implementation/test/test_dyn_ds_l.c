/*****************************************************************************************************

						                      UNITY TEST FILE

*******************************************************************************************************/

//#include "dyn_ds_l_test.h"
#include "dyn_ds_l.h"
#include "unity.h"
#include <stdio.h>
#include <stdlib.h>


/********************* definitiosn for other libs to work *****************************/
sll_node* root = NULL;	//lets start with an empty SLL
int actual_len = 0;
int data = 0;	//just a test data, increment this everytime when it gets inserted into SLL
int pos = 0;	//just a testing poition value to work with SLL

q_node* front_ = NULL;
q_node* rear_ = NULL;


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
void test_sll_append( void ){	//appending 10 values to empty SLL
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));	//appending values to SLL, if sucess, it returns 1 else -1
	actual_len++;				//incrementing the actual_len to test the test_sll_len later if needed
	sll_print_all(root);		//to visualize the SLL
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));actual_len++;
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_append(&root, ++data));actual_len++;sll_print_all(root);
}

void test_sll_len( void ){	//testing sll_len function
	TEST_ASSERT_EQUAL(actual_len, sll_len(root));sll_print_all(root);
}

void test_sll_add_at_begining( void ){
	TEST_ASSERT_EQUAL(1, sll_add_at_begining(&root, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_add_at_begining(&root, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_add_at_begining(&root, ++data));actual_len++;sll_print_all(root);
	
}

void test_sll_add_at_position( void ){
	TEST_ASSERT_EQUAL(1, sll_add_at_position(&root, ++pos, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_add_at_position(&root, ++pos, ++data));actual_len++;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_add_at_position(&root, ++pos, ++data));actual_len++;sll_print_all(root);
}

void test_sll_delete_begining( void ){
	TEST_ASSERT_EQUAL(1, sll_delete_begining(&root));actual_len--;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_delete_begining(&root));actual_len--;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_delete_begining(&root));actual_len--;sll_print_all(root);

}

void test_sll_delete_at_position( void ){
	TEST_ASSERT_EQUAL(1, sll_delete_at_position(&root, pos));actual_len--;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_delete_at_position(&root, pos));actual_len--;sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_delete_at_position(&root, pos));actual_len--;sll_print_all(root);
}

void test_sll_swap_data( void ){
	TEST_ASSERT_EQUAL(1, sll_swap_data(&root, 0, sll_len(root)-1));sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_swap_data(&root, 0, sll_len(root)-1));sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_swap_data(&root, 0, sll_len(root)-1));sll_print_all(root);
}

void test_sll_reverse_list( void ){
	TEST_ASSERT_EQUAL(1, sll_reverse_list(&root));sll_print_all(root);
}
	
void test_sll_peek( void ){	
	TEST_ASSERT_EQUAL(16, sll_peek(root, 0));
	TEST_ASSERT_EQUAL(9, sll_peek(root, 1));
	TEST_ASSERT_EQUAL(8, sll_peek(root, 2));
	TEST_ASSERT_EQUAL(7, sll_peek(root, 3));
}

void test_sll_overwrite( void ){
	pos = -1;
	TEST_ASSERT_EQUAL(1, sll_overwrite(&root, ++pos, 69));sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_overwrite(&root, ++pos, 69));sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_overwrite(&root, ++pos, 69));sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_overwrite(&root, ++pos, 69));sll_print_all(root);
}

void test_sll_sort_bubble( void ){
	TEST_ASSERT_EQUAL(1, sll_sort_bubble(&root, 'a'));sll_print_all(root);
	TEST_ASSERT_EQUAL(1, sll_sort_bubble(&root, 'd'));sll_print_all(root);
}


/******************* Queue test function definitions**************/
void test_q_push( void ){
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
	TEST_ASSERT_EQUAL(1, q_push(&front_, &rear_, ++data));q_print_all(front_);actual_len++;
}

void test_q_len( void ){
	TEST_ASSERT_EQUAL(actual_len, q_len(front_));
}

void test_q_pop( void ){
	TEST_ASSERT_EQUAL(1, q_pop(&front_));q_print_all(front_);actual_len--;
	TEST_ASSERT_EQUAL(2, q_pop(&front_));q_print_all(front_);actual_len--;
	TEST_ASSERT_EQUAL(3, q_pop(&front_));q_print_all(front_);actual_len--;
	TEST_ASSERT_EQUAL(4, q_pop(&front_));q_print_all(front_);actual_len--;
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
	
	/////// SLL testing
	RUN_TEST(test_sll_append);	
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_len);	
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_add_at_begining);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_len);	//testing sll_len again
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_add_at_position);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_delete_begining);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_delete_at_position);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_swap_data);
	printf("\n--------------------------------------------------------------------------\n");

	RUN_TEST(test_sll_reverse_list);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_peek);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_overwrite);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_sll_sort_bubble);
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("\n--------------------------------------------------------------------------------------------\n");
	pos = 0;actual_len = 0;data = 0;
	
	////// Queue testing
	RUN_TEST(test_q_push);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_q_len);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_q_len);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_q_pop);
	printf("\n--------------------------------------------------------------------------\n");
	
	RUN_TEST(test_q_peek);
	printf("\n--------------------------------------------------------------------------\n");
	
	return UNITY_END();
	
}





















