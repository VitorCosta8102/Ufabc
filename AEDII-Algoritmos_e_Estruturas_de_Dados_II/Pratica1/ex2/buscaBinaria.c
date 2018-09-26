#include<stdio.h>
#include "search.h"

int main() {
	int dados[] = {1,2,3,4,5,6,7,8,9};
	int resultado;
	
	resultado = binary_search(dados, 10, 4);
	printf("Resultado = %d\n", resultado);
	
	resultado = binary_search(dados, 10, 1);
	printf("Resultado = %d\n", resultado);
	
	resultado = binary_search(dados, 10, 0);
	printf("Resultado = %d\n", resultado);
	
	resultado = binary_search(dados, 10, 10);
	printf("Resultado = %d\n", resultado);
	
	return 0;
}
