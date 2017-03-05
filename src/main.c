#include <stdio.h>
#include "IntVector.h"
#include <stdlib.h>

int main()
{
	size_t initial_capacity = 5;

	IntVector *v = int_vector_new(initial_capacity);
	printf("Capacity = %d\nSize = %d\nData = %p\n", v->capacity, v->size, v->data);
	for(int i = 0; i < initial_capacity; i++){
		v->data[i] = i;
	}
	for(int i = 0; i < initial_capacity; i++){
		printf("%d", v->data[i]);
	}
	printf("\n");

	IntVector *copy_v = int_vector_copy(v);
//	copy_v->data = malloc(sizeof(int) * initial_capacity);
	printf("Capacity = %d\nSize = %d\nData = %p\n", copy_v->capacity, copy_v->size, copy_v->data);
//	printf("%d\n", *copy_v->data);

	int_vector_free(v);
	printf("Capacity = %d\nSize = %d\nData = %p\n", v->capacity, v->size, v->data);

	return 0;
}
