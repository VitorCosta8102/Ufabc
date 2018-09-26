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
