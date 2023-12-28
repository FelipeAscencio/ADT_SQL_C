#include "pila.h"
#include "lista.h"

#define PRIMERA_POSICION 0

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct _pila_t {
	nodo_t *nodo_inicio;
	nodo_t *nodo_final;
};

pila_t *pila_crear()
{
	lista_t *lista = lista_crear();
	return (pila_t *)lista;
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	lista_t *lista = (lista_t *)pila;
	size_t posicion = PRIMERA_POSICION;
	lista = lista_insertar_en_posicion(lista, elemento, posicion);
	return (pila_t *)lista;
}

void *pila_desapilar(pila_t *pila)
{
	lista_t *lista = (lista_t *)pila;
	size_t posicion = PRIMERA_POSICION;
	return lista_quitar_de_posicion(lista, posicion);
}

void *pila_tope(pila_t *pila)
{
	lista_t *lista = (lista_t *)pila;
	return lista_primero(lista);
}

size_t pila_tamanio(pila_t *pila)
{
	lista_t *lista = (lista_t *)pila;
	return lista_tamanio(lista);
}

bool pila_vacia(pila_t *pila)
{
	lista_t *lista = (lista_t *)pila;
	return lista_vacia(lista);
}

void pila_destruir(pila_t *pila)
{
	lista_t *lista = (lista_t *)pila;
	lista_destruir(lista);
}