//
// Created by pedrito on 20/10/18.
//

#include "../inc/vector.h"

object_t *create_object(void *data)
{
	object_t *object = malloc(sizeof(object_t));

	if (!object)
		return (NULL);
	object->data = data;
	return (object);
}

vector_t *create_vector()
{
	vector_t *vector = malloc(sizeof(vector_t));

	if (!vector)
		return (NULL);
	vector->length = 0;
	vector->objects = malloc(sizeof(void *));
	vector->at = v_at;
	vector->push_back = v_push_back;
	vector->remove = v_remove;
	vector->swap = v_swap;
	vector->sort = v_sort;
	return (vector);
}

void v_push_back(vector_t *vector, void *data)
{
	object_t *object = create_object(data);

	if (!object)
		return;
	vector->objects = realloc(vector->objects, (1 + vector->length) * sizeof(object_t));
	vector->objects[vector->length] = object;
	vector->length++;
}

void *v_at(vector_t *vector, int index)
{
	return (index < vector->length) ? vector->objects[index]->data : NULL;
}

int v_remove(vector_t *vector, int index)
{
	if (index >= vector->length)
		return (INDEX_UNREACHABLE);
	vector->length--;
	for (int i = index; i < vector->length; i++) {
		vector->objects[i] = vector->objects[i + 1];
	}
	free(vector->objects[vector->length]);
	return (0);
}

void destroy_vector(vector_t *vector)
{
	if (!vector)
		return;
	for (int i = 0; i < vector->length; i++) {
		free(vector->objects[i]);
	}
	free(vector->objects);
	free(vector);
}

int v_swap(vector_t *vector, int first, int second)
{
	object_t *tmp;

	if (!vector || first >= vector->length || second >= vector->length)
		return (INDEX_UNREACHABLE);
	tmp = vector->objects[first];
	vector->objects[first] = vector->objects[second];
	vector->objects[second] = tmp;
	return (0);
}

static int v_sort_integer(vector_t *vector)
{
	void *tmp;
	int sorted = 0;

	for (int i = 0; i < vector->length; i++) {
		if (vector->objects[i + 1] && (int)vector->objects[i]->data > (int)vector->objects[i + 1]->data) {
			tmp = vector->objects[i]->data;
			vector->objects[i]->data = vector->objects[i + 1]->data;
			vector->objects[i + 1]->data = tmp;
			sorted = 1;
		}
		if (i == vector->length - 1 && sorted == 1) {
			i = -1;
			sorted = 0;
		}
	}
	return (0);
}

int v_sort(vector_t *vector, int order_type)
{
	if (!vector)
		return (VECTOR_NULL);
	if (!vector->length)
		return (VECTOR_EMPTY);
	switch (order_type) {
	case ORDER_INTEGER:
		return v_sort_integer(vector);
	default:
		return (ORDER_INVALID);
	}
}

