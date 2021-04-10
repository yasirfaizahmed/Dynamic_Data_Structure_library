#include "dyn_ds_l.h"

struct sll_node* root = NULL;

int main(){ //main here is to test all the library functions
    int n = 11;
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
	
	sll_overwrite(&root, 5, 6969);
	sll_print_all(root);
	
	sll_sort_bubble(&root, 'd');
	sll_print_all(root);
	
	printf("\n%d\n", sll_return_address(root, 4));
}
