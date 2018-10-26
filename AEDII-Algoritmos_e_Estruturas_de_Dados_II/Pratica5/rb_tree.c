#include "rb_tree.h"

/* Valor de sentinela, indica que chegamos em alguma folha ou entao
 a raiz da arvore */
Node NIL_NODE = {.key = 0, .color = BLACK};

/* Ponteiro para o valor de sentinela */
Node *NIL_PTR = &NIL_NODE;

/** Funcao auxiliar que cria um novo Node, alocando memoria,
* para um valor de chave passado como parametro.
* Note que os valores dos ponteiros left/right/parent sao
* mantidos como NULL
*
* Parametros:
* key: a chave para o novo Node
*
* Devolve:
* Um novo Node em caso de sucesso, NULL caso nao consiga alocar
* a memoria para o novo Node
*/
Node* new_node(int key) {
    Node *ret_val = (Node*) malloc(sizeof(Node));
    if(NULL == ret_val) return NULL;
    ret_val->key = key;
    ret_val->color = RED;
    ret_val->left = NULL;
    ret_val->right = NULL;
    ret_val->parent = NULL;
    return ret_val;
}

void print_arvore(Node *raiz) {
	if(raiz == NIL_PTR)
		return;
	printf("%d<-%d->%d\n",raiz->left->key,raiz->key,raiz->right->key);
	print_arvore(raiz->left);
	print_arvore(raiz->right);	
}

/**
* A funcao abaixo insere uma nova chave em uma arvore RB
* sem realizar o balanceamento.
*
* Parametros:
* T: aponta para a raiz da arvore onde devemos inserir a chave
* key: valor da nova chave
*
* Devolve:
* O novo Node inserido em caso de sucesso, NULL caso nao
* seja possivel inserir o novo valor
*/


/*
Node* tree_insert(Node** T, int key){
	
}
*/


void rb_insert(Node** T, int key) {
	Node *y = NIL_PTR;
	Node *x = *T;
	
	Node *newNode = new_node(key);
	if(!newNode) return;
	
	while(x != NIL_PTR) {
		y = x;
		if(key < y->key)
			x = x->left;
		else
			x = x->right;
	}
	PAR(newNode) = y;
	
	if(NIL_PTR == y) 
		*T = newNode;
	else {
		if(key < y->key)
			y->left=newNode;
		else
			y->right=newNode;
	}
	newNode->left = NIL_PTR;
	newNode->right = NIL_PTR;
	rb_insert_fixup(T, newNode);
}	


void rb_insert_fixup (Node** T, Node *z) {
	
	while(RED == PAR(z)->color) {
		if(PAR(z) == GPAR(z)->left) {
			Node *uncle = GPAR(z)->right;
			if(RED == uncle->color) {
				PAR(z)->color = BLACK;
				uncle->color = BLACK;
				GPAR(z)->color = RED;
			}
			else {
				if(z == PAR(z)->right) {
					z = PAR(z);
					left_rotate(T,z);
				}
				PAR(z)->color = BLACK;
				GPAR(z)->color = RED;
				right_rotate(T,GPAR(z));
			}
		}
	}
	
	

	(*T)->color = BLACK;
}


/**
* Realiza uma rotacao simples para a esquerda
*
* Parametros:
* T: aponta para a raiz da arvore onde a rotacao sera realizada
* x: Node pertencente a arvore em torno do qual faremos a rotacao
*
*/
void left_rotate(Node** T, Node* x) {
	Node *pp = x->parent;
	Node *py = x->right;
	x->right = py->left;
	py->left = x;
	
	if(x==pp->left)
		pp->left=py;
	else
		pp->right=py;
}

/**
* Realiza uma rotacao simples para a direita
*
* Parametros:
* T: aponta para a raiz da arvore onde a rotacao sera realizada
* x: Node pertencente a arvore em torno do qual faremos a rotacao
*
*/
void right_rotate(Node** T, Node* x) {
	Node *pp = x->parent;
	Node *py = x->left;
	x->left = py->right;
	py->right = x;
	
	if(x==pp->left)
		pp->left=py;
	else
		pp->right=py;
}


/**
* Realiza a troca de cor em alguns nos, caso esses satisfacam
* algumas condicoes.
*
* Parametros:
* T: aponta para a raiz da arvore onde a rotacao sera realizada
* x: Node pertencente a arvore em torno do qual faremos a rotacao
*
*/
void flip_color(Node** T, Node* x){
	Node *xParent = x->parent;
	Node *xGrandPa = xParent->parent;
	Node *xUncle;
	
	if(xParent = xGrandPa->left)
		xUncle = xGrandPa->right;
	else 
		xUncle = xGrandPa->left;
	
	if(x->color == RED && xParent->color == RED && 
	xUncle->color == RED && xGrandPa->color == BLACK) {
		xParent->color = BLACK;
		xUncle->color = BLACK;
		xGrandPa->color = RED;
	}	
}





