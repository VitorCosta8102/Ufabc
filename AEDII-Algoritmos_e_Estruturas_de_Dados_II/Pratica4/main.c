#include "rb_tree.h"
#include <stdio.h>
extern Node *NIL_PTR;

int main() {

	Node *raiz = new_node(10);
	raiz->left = new_node(8);
	raiz->left->parent=raiz;
	raiz->right = new_node(15);
	raiz->right->parent=raiz;
	raiz->right->right = new_node(20);
	raiz->right->right->parent = raiz->right;
	print_arvore(raiz);
	printf("\n");
	left_rotate(&raiz, raiz->right);
	print_arvore(raiz);
	return 0;
}
