#include "cola.h"
#include "lista.h"

#define PRIMERA_POSICION 0

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct _cola_t {
	nodo_t *nodo_inicio;
	nodo_t *nodo_final;
};

cola_t *cola_crear()
{
	lista_t *lista = lista_crear();
	return (cola_t *)lista;
}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	lista_t *lista = (lista_t *)cola;
	lista = lista_insertar(lista, elemento);
	return (cola_t *)lista;
}

void *cola_desencolar(cola_t *cola)
{
	lista_t *lista = (lista_t *)cola;
	size_t posicion = PRIMERA_POSICION;
	return lista_quitar_de_posicion(lista, posicion);
}

void *cola_frente(cola_t *cola)
{
	lista_t *lista = (lista_t *)cola;
	return lista_primero(lista);
}

size_t cola_tamanio(cola_t *cola)
{
	lista_t *lista = (lista_t *)cola;
	return lista_tamanio(lista);
}

bool cola_vacia(cola_t *cola)
{
	lista_t *lista = (lista_t *)cola;
	return lista_vacia(lista);
}

void cola_destruir(cola_t *cola)
{
	lista_t *lista = (lista_t *)cola;
	lista_destruir(lista);
}