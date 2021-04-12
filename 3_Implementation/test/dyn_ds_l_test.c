/******************************************************************

						UNITY TEST FILE

******************************************************************/

//#include "dyn_ds_l_test.h"
#include "dyn_ds_l.h"
#include "unity.h"
#include <stdio.h>
#include <stdlib.h>


/********************* definitiosn for other libs to work ***********************/
sll_node* root = NULL;	//lets start with an empty SLL
int actual_len = 0;



/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}


/****************** SLL test functions ****************************************/
/****************** Basic functions test ********************************/
void test_sll_append( void );	
void test_sll_len( void );
void test_sll_add_at_begining( void );	


/***************** test definitions **************************************/
void test_sll_append( void ){	//appending 10 values to empty SLL
	TEST_ASSERT_EQUAL(1, sll_append(&root, 10));	//appending values to SLL, if sucess, it returns 1 else -1
	actual_len++;	//incrementing the actual_len to test the test_sll_len later if needed
	TEST_ASSERT_EQUAL(1, sll_append(&root, 20));actual_len++;
	TEST_ASSERT_EQUAL(1, sll_append(&root, 30));actual_len++;
	TEST_ASSERT_EQUAL(1, sll_append(&root, 40));actual_len++;
	TEST_ASSERT_EQUAL(1, sll_append(&root, 50));actual_len++;
	TEST_ASSERT_EQUAL(1, sll_append(&root, 60));actual_len++;
	TEST_ASSERT_EQUAL(1, sll_append(&root, 70));actual_len++;
	TEST_ASSERT_EQUAL(1, sll_append(&root, 80));actual_len++;
	TEST_ASSERT_EQUAL(1, sll_append(&root, 90));actual_len++;
	TEST_ASSERT_EQUAL(1, sll_append(&root, 100));actual_len++;
}

void test_sll_len( void ){	//testing sll_len function
	TEST_ASSERT_EQUAL(actual_len, sll_len(root));
}

void test_sll_add_at_begining( void ){
	
	
}
int main(){
	UNITY_BEGIN();	//initilize the uinity framework
	
	RUN_TEST(test_sll_append);	//RUN_TEST macro needs function pointer, in our case for eg. test_sll_append (function name is also a function pointer hehe)
	RUN_TEST(test_sll_len);
	
	
	return UNITY_END();
	
}





















