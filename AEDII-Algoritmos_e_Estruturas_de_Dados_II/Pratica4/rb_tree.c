#include "rb_tree.h"

/* Valor de sentinela, indica que chegamos em alguma folha ou entao
 a raiz da arvore */
Node NIL_NODE;

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
	if(!raiz)
		return;
	print_arvore(raiz->left);
	printf("%d ",raiz->key);
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
Node* tree_insert(Node** T, int key){
	/*if(!*T)
		
	if(*T->key == key)
	    return NULL;
	if(key < *T->key) {
		Node *aux = tree_insert(&T->left);
		if(!aux)
			return NULL;
		*T->left = aux;
		return *T;
	}
	else {
		Node *aux = tree_insert(&T->right);
		if(!aux)
			return NULL;
		*T->right = aux;
		return *T;
	}*/
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





