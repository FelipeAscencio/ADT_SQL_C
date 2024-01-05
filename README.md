# ADT SQL

- To compile and run the tests in your own console (being inside the general folder containing the files):

```bash
bash .tests/test.sh
```

---

## Introduction

The idea of ​​the project was to be able to provide the user with the implementation of a "stack, queue and list", with all its corresponding functions and in a 100% functional way.

In particular, the idea of ​​dynamic memory management (ensuring not to lose any byte of memory in the process) and the correct management of pointers, so as not to have invalid memory accesses, or reference losses in the process.

The end user would be provided with the compiled .h and .o so that they can use the library with the knowledge of all the pre and post conditions of the functions, but obviously without the implementation code.

Additionally, in the repository there is my own test library, with which in the example file I test the operation of the stack, the queue and the list

I use this library with the idea of ​​visually making it easier for anyone who wants to see how it works to read the tests and whether they work correctly or incorrectly.

## Functioning

###  Explanation of "Implementation and design"

First of all, this was a project for the university, so the code is written in spanish.

With that clarified, we move on to the explanation.

For the implementation of the 3 "ADTs" what I did was, start with the total implementation of the "list", and then propose the cases of the "stack" and the "queue" as specific cases of the operations of the " list", reusing the functions that I implemented for it.

I used 3 main structures:

- The "node" structure which contains the "node" own element and a pointer to the next "node".

- The structures "stack", "queue" and "list" (which are the same), and contain 2 pointers to the first and last node.

- And finally, in order to provide an external iterator to the user, the "iterator" structure has a pointer to a list, and a pointer to the current node.

Having the element be a "void*" allows the user to save whatever they want inside the "ADTs".

---

## Testing

For test the code, i implemented my own tests.

In the repository actions you can see the status of the executed tests.

Also add the analysis with valgrind to see if you have memory leaks, since the program uses dynamic memory.

---

## Functions

First of all, it is important to clarify something, in order to reduce the amount of information in the explanations below, corresponding to each function, the best case of its execution is contemplated.

But, each function has all its respective validations to, in case of error, terminate its execution.

The pre and post conditions of each function are specified in the corresponding ".h" file.

### Computational complexity

I am going to make a list of the computational complexities in "BIG O" notation of each implemented function.

### Stack

- pila_crear = O(1).

- pila_apilar = O(1).

- pila_desapilar = O(1).

- pila_tope = O(1).

- pila_tamanio = O(n).

- pila_vacia = O(1).

- pila_destruir = O(n).

### Queue

- cola_crear = O(1).

- cola_encolar = O(1).

- cola_desencolar = O(1).

- cola_frente = O(1).

- cola_tamanio = O(n).

- cola_vacia = O(1).

- cola_destruir = O(n).

### List

- lista_crear = O(1).

- lista_insertar = O(1).

- lista_insertar_en_posicion = O(n).

- lista_quitar = O(n).

- lista_quitar_de_posicion = O(n).

- lista_elemento_en_posicion = O(n).

- lista_buscar_elemento = O(n).

- lista_primero = O(1).

- lista_ultimo = O(1).

- lista_vacia = O(1).

- lista_tamanio = O(n).

- lista_destruir = O(n).

- lista_destruir_todo = O(n).

- lista_iterador_crear = O(1).

- lista_iterador_tiene_siguiente = O(1).

- lista_iterador_avanzar = O(1).

- lista_iterador_elemento_actual = O(1).

- lista_iterador_destruir = O(1).

- lista_con_cada_elemento = O(n).
