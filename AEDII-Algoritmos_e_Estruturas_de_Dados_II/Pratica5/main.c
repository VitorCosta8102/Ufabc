#include "rb_tree.h"
#include <stdio.h>
extern Node *NIL_PTR;

int main() {
	Node *raiz = NIL_PTR;
	Node **pRaiz = &raiz;
	rb_insert(pRaiz, 20);
	rb_insert(pRaiz, 18);
	rb_insert(pRaiz, 22);
	print_arvore(raiz);
	return 0;
}
