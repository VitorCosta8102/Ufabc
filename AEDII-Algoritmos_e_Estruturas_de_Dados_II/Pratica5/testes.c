#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "rb_tree.h"
#include "funcoes_teste.h"

extern Node *NIL_PTR;

/** 
* Funcao que recebe um vetor de chaves para montar uma 
* arvore rubro-negra
* 
* Entrada: raiz da arvore, vetor de chaves inteiras e tamanho do vetor (tamanho da arvore)
* Saida: constroi a arvore
*/

void criaArvoreTeste(Node **pRaiz,int casoTeste[],int tamanhoTeste) {
	for(int i=0;i<tamanhoTeste;i++)
		rb_insert(pRaiz,casoTeste[i]);
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
	criaArvoreTeste(pRaiz,teste1,4);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	raiz=NIL_PTR;
	printf("\n\nTeste 2: recoloracao e rotacao esquerda\n\n");
	criaArvoreTeste(pRaiz,teste2,8);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	raiz=NIL_PTR;
	printf("\n\nTeste 3: recoloracao, rotacoes esquerda e direita\n\n");
	criaArvoreTeste(pRaiz,teste3,9);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	raiz=NIL_PTR;
	printf("\nTeste 4: recoloracao e rotacao dupla direita\n\n");
	criaArvoreTeste(pRaiz,teste4,5);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	raiz=NIL_PTR;
	printf("\nTeste 5: recoloracao e rotacoes duplas a direita e a esquerda\n\n");
	criaArvoreTeste(pRaiz,teste5,7);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	raiz=NIL_PTR;
	printf("\nTeste 6: rotacao direita alterando a raiz\n\n");
	criaArvoreTeste(pRaiz,teste6,3);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	raiz=NIL_PTR;
	printf("\nTeste 7: rotacao esquerda alterando a raiz\n\n");
	criaArvoreTeste(pRaiz,teste7,3);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	raiz=NIL_PTR;
	printf("\nTeste 8: rotacao dupla direita alterando a raiz\n\n");
	criaArvoreTeste(pRaiz,teste8,3);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	raiz=NIL_PTR;
	printf("\nTeste 9: rotacao dupla esquerda alterando a raiz\n\n");
	criaArvoreTeste(pRaiz,teste9,3);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	raiz=NIL_PTR;
	printf("\nTeste 10\n\n");
	criaArvoreTeste(pRaiz,teste10,11);
	print_arvore(raiz);
	printf("\nAltura: %d\n",height(raiz));
	
	printf("\n\n------------------------\n");
	printf("Testes de altura");
	printf("\n------------------------\n\n");
	
	
	/** O parametro de saida status dos testes de altura diz respeito
	* ao fato da altura estar ou nao dentro dos limites para alturas de 
	* arvores rubro-negras.
	*/

	srand(time(NULL));
	
	/*--------Teste de altura 1---------- */
	/*valores sao crescentes no vetor de insercao*/
	raiz=NIL_PTR;
	int ok = 1, altura;
	int testeA1[100];

	for (int i=0;i<100;i++)
		testeA1[i]=i;

	criaArvoreTeste(pRaiz,testeA1,100);
	altura = height(raiz);
	if( altura < (1 + floor(log(100)/log(2))) || altura > (2*(log(101)/log(2))) )
		ok = 0;
	printf("Teste de altura 1: chaves crescentes\n\n");
	printf("Tamanho da arvore: 100\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");

	/*--------Teste de altura 2----------- */
	/*valores sao decrescentes no vetor de insercao*/
	raiz=NIL_PTR;
	int testeA2[100];
	ok = 1;

	for (int i=0;i<100;i++)
		testeA2[i]=100-i;
	criaArvoreTeste(pRaiz,testeA2,100);
	altura = height(raiz);
	if( altura < (1 + floor(log(100)/log(2))) || altura > (2*(log(101)/log(2))) )
		ok = 0;
	printf("Teste de altura 2: chaves decrescentes\n\n");
	printf("Tamanho da arvore: 100\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
	
	/*--------Teste de altura 3----------- */
	/*vetor da forma [50,51,...,98,99,0,1,2,...,49]*/
	raiz=NIL_PTR;
	int testeA3[100];
	ok = 1;

	for(int i=0;i<50;i++)
		testeA3[i]=i+50;
	for(int i=50;i<100;i++)
		testeA3[i]=i-50;

	criaArvoreTeste(pRaiz,testeA3,100);
	altura = height(raiz);
	if( altura < (1 + floor(log(100)/log(2))) || altura > (2*(log(101)/log(2))) )
		ok = 0;
	printf("Teste de altura 3: chaves 'meio' crescentes\n\n");
	printf("Tamanho da arvore: 100\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
	
	/*--------Teste de altura 4----------- */
	/*valores aleatorios de chaves*/
	raiz=NIL_PTR;
	int testeA4[100];
	ok = 1;
 
	for(int i=0;i<100;i++)
		testeA4[i]=rand()%10000;
	
	criaArvoreTeste(pRaiz,testeA4,100);
	altura = height(raiz);
	if( altura < (1 + floor(log(100)/log(2))) || altura > (2*(log(101)/log(2))) )
		ok = 0;
	printf("Teste de altura 4: chaves aleatorias\n\n");
	printf("Tamanho da arvore: 100\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
	
	/*--------Teste de altura 5---------- */
	/*valores sao crescentes no vetor de insercao*/
	raiz=NIL_PTR;
	int testeA5[1000];

	for (int i=0;i<1000;i++)
		testeA5[i]=i;

	criaArvoreTeste(pRaiz,testeA5,1000);
	altura = height(raiz);
	if( altura < (1 + floor(log(1000)/log(2))) || altura > (2*(log(1001)/log(2))) )
		ok = 0;
	printf("Teste de altura 5: chaves crescentes\n\n");
	printf("Tamanho da arvore: 1000\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");

	/*--------Teste de altura 6----------- */
	/*valores sao decrescentes no vetor de insercao*/
	raiz=NIL_PTR;
	int testeA6[1000];
	ok = 1;

	for (int i=0;i<1000;i++)
		testeA6[i]=1000-i;
	criaArvoreTeste(pRaiz,testeA6,1000);
	altura = height(raiz);
	if( altura < (1 + floor(log(1000)/log(2))) || altura > (2*(log(1001)/log(2))) )
		ok = 0;
	printf("Teste de altura 6: chaves decrescentes\n\n");
	printf("Tamanho da arvore: 1000\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
	
	/*--------Teste de altura 7----------- */
	/*vetor da forma [500,501,...,998,999,0,1,2,...,499]*/
	raiz=NIL_PTR;
	int testeA7[1000];
	ok = 1;

	for(int i=0;i<500;i++)
		testeA7[i]=i+500;
	for(int i=500;i<1000;i++)
		testeA7[i]=i-500;

	criaArvoreTeste(pRaiz,testeA7,1000);
	altura = height(raiz);
	if( altura < (1 + floor(log(1000)/log(2))) || altura > (2*(log(1001)/log(2))) )
		ok = 0;
	printf("Teste de altura 7: chaves 'meio' crescentes\n\n");
	printf("Tamanho da arvore: 1000\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");

	/*--------Teste de altura 8----------- */
	/*valores aleatorios de chaves*/
	raiz=NIL_PTR;
	int testeA8[1000];
	ok = 1;
 
	for(int i=0;i<1000;i++)
		testeA8[i]=rand()%10000;
	
	criaArvoreTeste(pRaiz,testeA8,1000);
	altura = height(raiz);
	if( altura < (1 + floor(log(1000)/log(2))) || altura > (2*(log(1001)/log(2))) )
		ok = 0;
	printf("Teste de altura 8: chaves aleatorias\n\n");
	printf("Tamanho da arvore: 1000\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
	
	/*--------Teste de altura 9----------- */
	/*valores sao crescentes no vetor de insercao*/
	raiz=NIL_PTR;
	int testeA9[10000];
	ok = 1;
 
	for(int i=0;i<10000;i++)
		testeA9[i]=i;

	criaArvoreTeste(pRaiz,testeA9,10000);
	altura = height(raiz);
	if( altura < (1 + floor(log(10000)/log(2))) || altura > (2*(log(10001)/log(2))) )
		ok = 0;
	printf("Teste de altura 9: chaves crescentes\n\n");
	printf("Tamanho da arvore: 10000\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
  
	/*--------Teste de altura 10----------- */
	/*vetor da forma [5000,5001,...,9998,9999,0,1,2,...,4999]*/
	raiz=NIL_PTR;
	int testeA10[10000];
	ok = 1;

	for(int i=0;i<5000;i++)
		testeA10[i]=i+5000;
	for(int i=5000;i<10000;i++)
		testeA10[i]=i-5000;
	
	criaArvoreTeste(pRaiz,testeA10,10000);
	altura = height(raiz);
	if( altura < (1 + floor(log(10000)/log(2))) || altura > (2*(log(10001)/log(2))) )
		ok = 0;
	printf("Teste de altura 10: chaves 'meio' crescentes\n\n");
	printf("Tamanho da arvore: 10000\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
 
	/*--------Teste de altura 11----------- */
	/*valores aleatorios de chaves*/
	raiz=NIL_PTR;
	int testeA11[10000];
	ok = 1;
 
	for(int i=0;i<10000;i++)
		testeA11[i]=rand()%100000;
	
	criaArvoreTeste(pRaiz,testeA11,10000);
	altura = height(raiz);
	if( altura < (1 + floor(log(10000)/log(2))) || altura > (2*(log(10001)/log(2))) )
		ok = 0;
	printf("Teste de altura 11: chaves aleatorias\n\n");
	printf("Tamanho da arvore: 10000\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
	
	/*--------Teste de altura 12----------- */
	/*valores sao crescentes no vetor de insercao*/
	raiz=NIL_PTR;
	int testeA12[100000];
	ok = 1;
 
	for(int i=0;i<100000;i++)
		testeA12[i]=i;

	criaArvoreTeste(pRaiz,testeA12,100000);
	altura = height(raiz);
	if( altura < (1 + floor(log(100000)/log(2))) || altura > (2*(log(100001)/log(2))) )
		ok = 0;
	printf("Teste de altura 12: chaves crescentes\n\n");
	printf("Tamanho da arvore: 100000\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
	
	/*--------Teste de altura 13----------- */
	/*valores aleatorios de chaves*/
	raiz=NIL_PTR;
	int testeA13[100000];
	ok = 1;
 
	for(int i=0;i<100000;i++)
		testeA13[i]=rand()%1000000;
	
	criaArvoreTeste(pRaiz,testeA13,100000);
	altura = height(raiz);
	if( altura < (1 + floor(log(100000)/log(2))) || altura > (2*(log(100001)/log(2))) )
		ok = 0;
	printf("Teste de altura 13: chaves aleatorias\n\n");
	printf("Tamanho da arvore: 100000\n");
	printf("Altura: %d\n",altura);
	printf("Status: %s\n\n",ok == 1? "Altura ok": "Altura errada");
  
}
