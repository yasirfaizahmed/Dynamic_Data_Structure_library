#include "dyn_ds_l.h"

struct sll_node* root = NULL;

int main(){
    int n = 11;
    while(n--) sll_append(&root, n);
    sll_printall(root);
}
