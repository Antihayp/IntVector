#include "IntVector.h"
#include <string.h>
#include <stdlib.h>

IntVector *int_vector_new(size_t initial_capacity)
{
	IntVector *v = malloc(sizeof(IntVector));
	if (v == NULL) {
		return NULL;
	}
	v->data = malloc(sizeof(int) * initial_capacity);
	if (v->data == NULL) {
		free(v);
		return NULL;
	}
	v->size = 0;
	v->capacity = initial_capacity;
	return v;
}

IntVector *int_vector_copy(const IntVector *v)
{
	IntVector *copy_v = malloc(sizeof(IntVector));
	if (copy_v == NULL) {
		return NULL;
	}
	copy_v->data = malloc(sizeof(int) * int_vector_get_capacity(v));
	if (copy_v->data == NULL) {
		free(copy_v);
		return NULL;
	}
	memcpy(copy_v->data, v->data, sizeof(int) * int_vector_get_capacity(v));
	copy_v->size = int_vector_get_size(v);
	copy_v->capacity = int_vector_get_capacity(v);
	return copy_v;
}

void int_vector_free(IntVector *v)
{
	if (v != NULL) {
		free(v->data);
		free(v);
	}
}

int int_vector_get_item(const IntVector *copy_v, size_t index)
{
	if (index < int_vector_get_capacity(copy_v)) {
		return copy_v->data[index];
	}
	return 0;
}

void int_vector_set_item(IntVector *copy_v, size_t index, int item)
{
	if (item < int_vector_get_capacity(copy_v)) {
		copy_v->data[index] = item;
	}
}

size_t int_vector_get_size(const IntVector *copy_v)
{
	return copy_v->size;
}

size_t int_vector_get_capacity(const IntVector *copy_v)
{
	return copy_v->capacity;
}

int int_vector_push_back(IntVector *copy_v, int item)
{
	if (int_vector_get_capacity(copy_v) == 0){
		copy_v->capacity = 1;
	}
	if (int_vector_get_capacity(copy_v) == int_vector_get_size(copy_v)) {
		int *test = realloc(copy_v->data, sizeof(int) * int_vector_get_capacity(copy_v) * 2);
		if (test == NULL) {
			return -1;
		}
		copy_v->capacity = int_vector_get_capacity(copy_v) * 2;
		copy_v->data = test;
	}
	copy_v->data[int_vector_get_size(copy_v)] = item;
	copy_v->size = int_vector_get_size(copy_v) + 1;

	return 0;
}

void int_vector_pop_back(IntVector *copy_v)
{
	if (int_vector_get_size(copy_v) != 1) {
		copy_v->size--;
	}
}

int int_vector_shrink_to_fit(IntVector *copy_v)
{
	if (int_vector_get_capacity(copy_v) > int_vector_get_size(copy_v)) {
		int *test = realloc(copy_v->data, sizeof(int) * int_vector_get_size(copy_v));
		if (test == NULL) {
			return -1;
		}
		copy_v->data = test;
	}
	copy_v->capacity = int_vector_get_size(copy_v);
	return 0;
}

int int_vector_resize(IntVector *copy_v, size_t new_size)
{
	if (new_size > int_vector_get_size(copy_v)) {
		for (int i = int_vector_get_size(copy_v); i < new_size; i++) {
			if (int_vector_push_back(copy_v, 0) == -1) {
				return -1;
			}
		}
	}
	copy_v->size = new_size;
	return 0;
}

int int_vector_reserve(IntVector *copy_v, size_t new_capacity)
{
	if (new_capacity > copy_v->capacity) {	
		copy_v->capacity = new_capacity;
		// FIXME
		int *test = realloc(copy_v->data, sizeof(int) * copy_v->capacity);
		if (test == NULL) {
			return -1;
		}
		copy_v->data = test;
	}
	return 0;
}
