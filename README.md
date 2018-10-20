# C_VECTOR


Here's an small C implementation of **vectors**.


| Action | Prototype | Exemple |
|--|--|--|
| Retrieve data  | `    VECTOR_GET_AS(type, vector_pointer, index)`  |  `VECTOR_GET_AS(int, my_vector, 0)`
|Push data|`v_push_back(vector_pointer, void *data)`|`vector->push_back(my_vector, (void *)3)`
|Remove data|`v_remove(vector_pointer, void *data)`|`vector->remove(my_vector, 1)` 
|Sort data|`v_sort(vector_pointer, ORDER_TYPE)`|`vector->sort(my_vector, ORDER_INTEGER)`