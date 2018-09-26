#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // para gerar um valor semente para a função rand()
#include "search.h"

void teste_sequencial() {
	int teste=1;
	int casoEspecial;
	int dados[] = {1,2,80,5,4,6,30,8,9,78};
	int dados2[100];
	int resultado;
	
	printf("\n-----------------\nBusca sequencial \n-----------------\n\n");
	resultado = seq_search(dados, 10, 1);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados, 10, 5);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados, 10, -4);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados, 10, 10);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados, 10, 9);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	srand(time(NULL));
	
	for(int i=0;i<100;i++) {
		dados2[i]=rand()%301;
	}
	teste = 1;
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, 301);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, 1000);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	teste = 1;
	
	casoEspecial = dados2[0];
	
	resultado = seq_search(dados2, 100, casoEspecial);
	printf("Resultado teste especial %d = %d\n",teste++,resultado);
	
	dados2[0]++;
	
	resultado = seq_search(dados2, 100, casoEspecial);
	printf("Resultado teste especial %d = %d\n",teste++,resultado);
}

void teste_binaria() {
	printf("\n-----------------\nBusca binaria\n-----------------\n\n");
	int teste=1;
	int casoEspecial;
	int dados[] = {-1,0,1,2,3,5,4,6,7,8,9};
	int dados2[100];
	int resultado;
	
	resultado = seq_search(dados, 11, -1);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados, 11, 5);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados, 11, -4);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados, 11, 10);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados, 11, 9);
	printf("Resultado %d = %d\n",teste++,resultado);
	
	
	for(int i=0;i<100;i++) {
		dados2[i]=rand()%301;
	}
	teste = 1;
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, 301);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, 1000);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	resultado = seq_search(dados2, 100, dados2[rand()%100]);
	printf("Resultado teste aleatorio %d = %d\n",teste++,resultado);
	
	teste = 1;
	
	casoEspecial = dados2[0];
	
	resultado = seq_search(dados2, 100, casoEspecial);
	printf("Resultado teste especial %d = %d\n",teste++,resultado);
	
	dados2[0]++;
	
	resultado = seq_search(dados2, 100, casoEspecial);
	printf("Resultado teste especial %d = %d\n",teste++,resultado);
}
