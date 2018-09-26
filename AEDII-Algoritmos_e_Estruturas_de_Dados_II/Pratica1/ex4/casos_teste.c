#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // para gerar um valor semente para a função rand() e o tempo
#include "search.h"

void imprime_teste(int array[], int array_size,int key,int teste,int tipo) {
  int resultado;
  clock_t t_inicio, t_fim;
  double delta;

  t_inicio = clock();
  if(tipo==1)
	  resultado = seq_search(array, array_size, key);
  else
    resultado = binary_search(array, array_size, key);
  t_fim = clock();
  delta = (double)(t_fim - t_inicio)*1e6/CLOCKS_PER_SEC;
	printf("Resultado %d = %d \t tamanho: %d \t tempo: %f\n",teste,resultado,array_size,delta);
}

void teste_sequencial() {
  int teste=1,valorTeste;
	int dados[] = {1,2,80,5,4,6,30,8,9,78};
	int dados2[100];
  int dados3[1000];
  int dados4[5000];
  int dados5[10000];
	
	printf("\n-----------------\nBusca sequencial \n-----------------\n\n");
  
  imprime_teste(dados,10,1,teste++,1);
	imprime_teste(dados,10,6,teste++,1);
  imprime_teste(dados,10,-4,teste++,1);
  imprime_teste(dados,10,10,teste++,1);
  imprime_teste(dados,10,78,teste++,1);
	
	srand(time(NULL));
	for(int i=0;i<100;i++) {
		dados2[i]=rand()%301;
  }

	valorTeste=dados2[rand()%100];
  imprime_teste(dados2,100,valorTeste,teste++,1);

  valorTeste=dados2[rand()%100];
	imprime_teste(dados2,100,valorTeste,teste++,1);
  imprime_teste(dados2,100,301,teste++,1);
	imprime_teste(dados2,100,-10,teste++,1);

  for(int i=0;i<200;i++)
    dados3[i]=i;
  imprime_teste(dados3,200,201,teste++,1);

  for(int i=0;i<400;i++)
    dados3[i]=i;
  imprime_teste(dados3,400,401,teste++,1);
  
  for(int i=0;i<800;i++)
    dados3[i]=i;
  imprime_teste(dados3,800,801,teste++,1);

  for(int i=0;i<1000;i++)
    dados3[i]=i;
  imprime_teste(dados3,1000,1001,teste++,1);
}

void teste_binaria() {
	printf("\n-----------------\nBusca binaria\n-----------------\n\n");
	int teste=1;
	int valorTeste;
	int dados[] = {-1,0,1,2,3,5,4,6,7,8,9};
	int dados2[100];
  int dados3[1000];
  int dados4[5000];
  int dados5[10000];
	
  imprime_teste(dados,11,-1,teste++,2);
	imprime_teste(dados,10,5,teste++,2);
  imprime_teste(dados,10,-4,teste++,2);
  imprime_teste(dados,10,10,teste++,2);
  imprime_teste(dados,10,9,teste++,2);
	
	srand(time(NULL));
	for(int i=0;i<100;i++) {
		dados2[i]=i+5;
  }

	valorTeste=dados2[rand()%100];
  imprime_teste(dados2,100,valorTeste,teste++,2);

  valorTeste=dados2[rand()%100];
	imprime_teste(dados2,100,valorTeste,teste++,2);
  imprime_teste(dados2,100,301,teste++,2);
	imprime_teste(dados2,100,-10,teste++,2);

  for(int i=0;i<200;i++)
    dados3[i]=i;
  imprime_teste(dados3,200,201,teste++,2);

  for(int i=0;i<400;i++)
    dados3[i]=i;
  imprime_teste(dados3,400,401,teste++,2);
  
  for(int i=0;i<800;i++)
    dados3[i]=i;
  imprime_teste(dados3,800,801,teste++,2);

  for(int i=0;i<1000;i++)
    dados3[i]=i;
  imprime_teste(dados3,1000,1001,teste++,2);

}
