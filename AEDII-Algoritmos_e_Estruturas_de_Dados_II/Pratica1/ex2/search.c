#include "search.h"

int seq_search(int array[] , int array_size, int key) {
	int ret_val = -1;
	int i;
	
	for(i = 0; i< array_size; i = i+1) {
		if(array[i] == key) {
			ret_val = i;
			break;
		}
	}
	
	return ret_val;
}

int binary_search(int array[], int array_size, int key) {
	int val_ret = -1;
	int inicio = 0;
	int fim = array_size-1;
	int meio;
	
	while(inicio<=fim) {
		meio = inicio + (fim - inicio)/2;
		
		if(array[meio]<key) {
			inicio = meio+1;
		}
		else if(array[meio]>key) {
			fim = meio-1;
		}
		else {
			val_ret = meio;
			break;
		}
	}
	return val_ret;
}
