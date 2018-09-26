#include <stdio.h>
#include "search.h"

int main() {
	int resultado;
	int dados[] = {3,5,6};
	
	resultado = seq_search(dados, 3, 10);
	printf("Resultado = %d\n", resultado);
	
	resultado = seq_search(dados, 3, 6);
	printf("Resultado = %d\n", resultado);
}
