#include "dyn_ds_l.h"

//struct sll_node* root = NULL;

//struct q_node* front_ = NULL;
//struct q_node* rear_ = NULL;

struct bst_node* root = NULL;

int main(int argc, char** argv){ //main here is to test all the library functions
/*    int n = 11;
    while(n--) sll_append(&root, n);
    sll_print_all(root);

    printf("\n%d", sll_len(root));
	
    sll_add_at_begining(&root, 100);
    sll_print_all(root);
	
    sll_add_at_position(&root, 3, 999);
    sll_print_all(root);
	
	sll_delete_begining(&root);
	sll_print_all(root);
	
	sll_delete_at_position(&root, 5);
	sll_print_all(root);
	
	sll_swap_data(&root, 3, 6);
	sll_print_all(root);
	
	sll_reverse_list(&root);
	sll_print_all(root);
	
	printf("\n%d\n", sll_peek(root, 6));
	
	sll_overwrite(&root, 5, 69);
	sll_print_all(root);
	
	sll_sort_bubble(&root, 'd');
	sll_print_all(root);
	
	printf("\n%d\n", sll_return_address(root, 4));
	*/
	
	/*
	int n = 11;
	while( n-- ) q_push(&front_, &rear_, n);
	q_print_all(front_);
	
	printf("\n%d\n", q_len(front_));
	
	q_pop(&front_);
	q_print_all(front_);
	
	printf("\n%d\n", q_peek(front_, 5));
	*/
	
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	int n = 0;
    while(n < sizeof(arr)/sizeof(arr[0])){
        bst_append(&root, arr[n]);
        n++;
    }
	bst_print_all(root, 1);
	
	//bst_delete(&root, 3);
	bst_print_all(root, 1);
	printf( "\n%d\n", (bst_search_parent(&root, 7, 'c'))->data );
	bst_inorder_traverse(root);
	bst_preorder_traverse(root);
	bst_postorder_traverse(root);
	
}
