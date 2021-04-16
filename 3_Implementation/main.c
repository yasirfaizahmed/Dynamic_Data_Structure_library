#include "dyn_ds_l.h"

/************************************************************************************************************************************
************************************    Library function testing done by visualizing the processess *********************************
*************************************************************************************************************************************/



struct sll_node* sll_root = NULL;

struct q_node* front_ = NULL;
struct q_node* rear_ = NULL;

struct bst_node* bst_root = NULL;

int main(int argc, char** argv){ //main here is to test all the library functions
	printf("\n------------------------------------------------------------------------------------------------------------------\n");
	printf("\n ---------------------------  Library function testing done by visualizing the processess ------------------------\n");
	printf("\n------------------------------------------------------------------------------------------------------------------\n");
	
	printf("\n\n\n-------------------------------------  Singly-Linked Lists visualization -----------------------------------------\n");
	
    int n = 11;
    while(n--){
		printf("appending %d\n", n);
		sll_append(&sll_root, n);
		sll_print_all(sll_root);

	}
   

    printf("\nprinting the total lenght of SLL = %d", sll_len(sll_root));
	
    sll_add_at_begining(&sll_root, 100);
	printf("\nAdded 100 at begining of the SLL");
    sll_print_all(sll_root);
	
    sll_add_at_position(&sll_root, 3, 999);
	printf("\nAdded 999 at position 3 of the SLL");
    sll_print_all(sll_root);
	
	sll_delete_begining(&sll_root);
	printf("\nDeleted element at begining of the SLL");
	sll_print_all(sll_root);
	
	sll_delete_at_position(&sll_root, 5);
	printf("\nDeleted at position 5 of the SLL");
	sll_print_all(sll_root);
	
	sll_swap_data(&sll_root, 3, 6);
	printf("\nSwaped elements at position 3 and 6 in the SLL");
	sll_print_all(sll_root);
	
	sll_reverse_list(&sll_root);
	printf("\nReversed the whole SLL");
	sll_print_all(sll_root);
	
	printf("\nPeeking at position 6 = %d\n", sll_peek(sll_root, 6));
	
	sll_overwrite(&sll_root, 5, 69);
	printf("\nOverwriting ar position 5 as 69");
	sll_print_all(sll_root);
	
	sll_sort_bubble(&sll_root, 'd');
	printf("\nBubble sorted in descending order");
	sll_print_all(sll_root);
	
	sll_sort_bubble(&sll_root, 'a');
	printf("\nBubble sorted in ascending order");
	sll_print_all(sll_root);
	
	printf("\nAddress of element ar position 4 = %d\n", sll_return_address(sll_root, 4));
	
	
	
	printf("\n\n\n--------------------------------------------  Queues visualization ---------------------------------------------------\n");
	
	n = 11;
	while( n-- ){
		printf("\npushing %d in Queue\n", n);
		q_push(&front_, &rear_, n);
		q_print_all(front_);
	}
	
	printf("\nTotal length of Queue = %d\n", q_len(front_));
	
	printf("\nPoppin the first element form Queue\n");
	q_pop(&front_);
	q_print_all(front_);
	
	printf("\nPeeking at position 5 in Queue = %d\n", q_peek(front_, 5));


	
	printf("\n\n\n-------------------------------------  Binary Search Trees visualization -----------------------------------------\n");
	
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	n = 0;
    while(n < sizeof(arr)/sizeof(arr[0])){
		printf("\n\n\n adding %d to the binary search tree\n",arr[n]);
        bst_append(&bst_root, arr[n]);
        n++;
		bst_print_all(bst_root, 1);
    }
	bst_print_all(bst_root, 1);
	
	//bst_delete(&root, 3);
	
	printf("\n\n In_order traversal\n");
	bst_inorder_traverse(bst_root);
	
	printf("\n\n pre_order traversal\n");
	bst_preorder_traverse(bst_root);
	
	printf("\n\n post_order traversal\n");
	bst_postorder_traverse(bst_root);
	
}
