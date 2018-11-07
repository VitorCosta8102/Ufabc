#include <stdio.h>
#include "rb_tree.h"
#include "funcoes_teste.h"

extern Node *NIL_PTR;

/** 
* Funcao que recebe um vetor de chaves para montar uma 
* arvore rubro-negra
* 
* Entrada: vetor de chaves inteiras
* Saida: altura da arvore e chamada a funcao print_arvore
*/

void testeCorretude_altura(int casoTeste[],int tamanhoTeste) {
	Node *raiz = NIL_PTR;
	Node **pRaiz = &raiz;
	for(int i=0;i<tamanhoTeste;i++)
		rb_insert(pRaiz,casoTeste[i]);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
}

void testes(void) {
	Node *raiz = NIL_PTR;
	Node **pRaiz = &raiz;
	int teste1[] = {20,18,22,28};
	int teste2[] = {120,114,122,128,112,129,19,16};
	int teste3[] = {20,18,22,28,12,19,9,6,30};
	int teste4[] = {45,33,47,40,42};
	int teste5[] = {70,68,72,65,67,78,77};
	int teste6[] = {56,34,17};
	int teste7[] = {20,22,25};
	int teste8[] = {80,10,15};
	int teste9[] = {28,39,30};
	int teste10[] = {120,114,122,128,112,129,19,16,113,115,116};
	printf("\n\nTeste 1: recoloracao\n\n");
	testeCorretude_altura(teste1,4);
	
	printf("\n\nTeste 2: recoloracao e rotacao esquerda\n\n");
	testeCorretude_altura(teste2,8);
	
	printf("\n\nTeste 3: recoloracao, rotacoes esquerda e direita\n\n");
	testeCorretude_altura(teste3,9);
	
	printf("\nTeste 4: recoloracao e rotacao dupla direita\n\n");
	testeCorretude_altura(teste4,5);
	
	printf("\nTeste 5: recoloracao e rotacoes duplas a direita e a esquerda\n\n");
	testeCorretude_altura(teste5,7);
	
	printf("\nTeste 6: rotacao direita alterando a raiz\n\n");
	testeCorretude_altura(teste6,3);
	
	printf("\nTeste 7: rotacao esquerda alterando a raiz\n\n");
	testeCorretude_altura(teste7,3);
	
	printf("\nTeste 8: rotacao dupla direita alterando a raiz\n\n");
	testeCorretude_altura(teste8,3);
	
	printf("\nTeste 9: rotacao dupla esquerda alterando a raiz\n\n");
	testeCorretude_altura(teste9,3);
	
	printf("\nTeste 10\n\n");
	testeCorretude_altura(teste10,11);
	
}
