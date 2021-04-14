#include "dyn_ds_l.h"

struct sll_node* sll_root = NULL;

struct q_node* front_ = NULL;
struct q_node* rear_ = NULL;

struct bst_node* bst_root = NULL;

int main(int argc, char** argv){ //main here is to test all the library functions
    int n = 11;
    while(n--) sll_append(&sll_root, n);
    sll_print_all(sll_root);

    printf("\n%d", sll_len(sll_root));
	
    sll_add_at_begining(&sll_root, 100);
    sll_print_all(sll_root);
	
    sll_add_at_position(&sll_root, 3, 999);
    sll_print_all(sll_root);
	
	sll_delete_begining(&sll_root);
	sll_print_all(sll_root);
	
	sll_delete_at_position(&sll_root, 5);
	sll_print_all(sll_root);
	
	sll_swap_data(&sll_root, 3, 6);
	sll_print_all(sll_root);
	
	sll_reverse_list(&sll_root);
	sll_print_all(sll_root);
	
	printf("\n%d\n", sll_peek(sll_root, 6));
	
	sll_overwrite(&sll_root, 5, 69);
	sll_print_all(sll_root);
	
	sll_sort_bubble(&sll_root, 'd');
	sll_print_all(sll_root);
	
	printf("\n%d\n", sll_return_address(sll_root, 4));
	
	
	
	n = 11;
	while( n-- ) q_push(&front_, &rear_, n);
	q_print_all(front_);
	
	printf("\n%d\n", q_len(front_));
	
	q_pop(&front_);
	q_print_all(front_);
	
	printf("\n%d\n", q_peek(front_, 5));

	
	
	
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	n = 0;
    while(n < sizeof(arr)/sizeof(arr[0])){
        bst_append(&bst_root, arr[n]);
        n++;
    }
	bst_print_all(bst_root, 1);
	
	//bst_delete(&root, 3);
	bst_print_all(bst_root, 1);
	printf( "\n%d\n", (bst_search_parent(&bst_root, 7, 'c'))->data );
	bst_inorder_traverse(bst_root);
	bst_preorder_traverse(bst_root);
	bst_postorder_traverse(bst_root);
	
}
