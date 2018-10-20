//
// Created by pedrito on 20/10/18.
//

#ifndef C_VECTOR_VECTOR_H
#define C_VECTOR_VECTOR_H

#include <stdlib.h>

#define VECTOR_NULL (500)
#define VECTOR_EMPTY (501)
#define INDEX_UNREACHABLE (502)
#define ORDER_INVALID (510)

#define ORDER_INTEGER (101)

#define VECTOR_GET_AS(type, vector_pointer, index) ((type)v_at((vector_pointer), (index)))

typedef struct object_s object_t;
typedef struct vector_s vector_t;

struct object_s
{
	void *data;
};

struct vector_s
{
	size_t length;
	object_t **objects;
	void *(*at)(vector_t *this, int index);
	void (*push_back)(vector_t *this, void *data);
	int (*remove)(vector_t *this, int index);
	int (*swap)(vector_t *this, int first, int second);
	int (*sort)(vector_t *this, int order_type);
};

void *v_at(vector_t *vector, int index);
void v_push_back(vector_t *vector, void *data);
int v_remove(vector_t *vector, int index);
int v_swap(vector_t *vector, int first, int second);
int v_sort(vector_t *vector, int order_type);

object_t *create_object(void *data);
vector_t *create_vector();
void destroy_vector(vector_t *vector);


#endif //C_VECTOR_VECTOR_H
