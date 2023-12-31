#include "pruebas.h"
#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"

#define TAMANIO_ESPERADO 4
#define TAMANIO_ESPERADO_2 5
#define TAMANIO_ESPERADO_3 3
#define TAMANIO_ESPERADO_4 2

bool no_puede_insertar_final(lista_t *lista_aux, void *elemento)
{
	lista_t *lista = lista_insertar(lista_aux, elemento);
	if (lista != NULL) {
		return true;
	}
	return false;
}

bool tamanio_lista_vacia(lista_t *lista, void *elemento)
{
	size_t tamanio = lista_tamanio(lista);
	if (tamanio != 0) {
		return true;
	}
	return false;
}

bool quitar_lista_vacia(lista_t *lista)
{
	void *elemento_recibido = lista_quitar(lista);
	if (elemento_recibido != NULL) {
		return true;
	}
	return false;
}

bool posicion_inexistente()
{
	lista_t *lista = lista_crear();
	size_t posicion_auxiliar = 10;

	void *elemento_auxiliar =
		lista_elemento_en_posicion(lista, posicion_auxiliar);
	if (elemento_auxiliar != NULL) {
		lista_destruir(lista);
		return true;
	}
	lista_destruir(lista);
	return false;
}

bool no_se_puede_comparar()
{
	lista_t *lista = lista_crear();
	void *contexto = NULL;
	void *elemento = lista_buscar_elemento(lista, NULL, contexto);
	if (elemento != NULL) {
		lista_destruir(lista);
		return true;
	}
	lista_destruir(lista);
	return false;
}

bool no_hay_primero(lista_t *lista)
{
	void *elemento_auxiliar = lista_primero(lista);
	if (elemento_auxiliar != NULL) {
		return true;
	}
	return false;
}

bool lista_vacia_test(lista_t *lista)
{
	bool vacia = lista_vacia(lista);
	if (vacia == false) {
		return true;
	}
	return false;
}

bool falla_crear_iterador(lista_t *lista)
{
	lista_iterador_t *iterador = lista_iterador_crear(lista);
	if (iterador != NULL) {
		return true;
	}
	return false;
}

bool no_sigue_iterando()
{
	lista_t *lista = lista_crear();
	lista_iterador_t *iterador = lista_iterador_crear(lista);
	bool puede_seguir = lista_iterador_tiene_siguiente(iterador);
	bool resultado = false;
	if (puede_seguir == false) {
		void *elemento = lista_iterador_elemento_actual(iterador);
		if (elemento == NULL) {
			resultado = false;
		} else {
			resultado = true;
		}
	} else {
		resultado = true;
	}
	lista_iterador_destruir(iterador);
	free(lista);
	return resultado;
}

bool no_aplica_cada_elemento()
{
	lista_t *lista_aux = lista_crear();
	size_t cantidad_aplicada =
		lista_con_cada_elemento(lista_aux, NULL, NULL);
	lista_destruir(lista_aux);
	if (cantidad_aplicada != 0) {
		return true;
	}
	return false;
}

bool no_puede_encolar(cola_t *cola)
{
	void *elemento = NULL;
	cola = cola_encolar(cola, elemento);
	if (cola != NULL) {
		return true;
	}
	return false;
}

bool no_puede_desencolar(cola_t *cola)
{
	cola = cola_desencolar(cola);
	if (cola != NULL) {
		return true;
	}
	return false;
}

bool tamanio_cola_invalido()
{
	cola_t *cola = cola_crear();
	int valor1 = 1;
	void *elemento1 = &valor1;
	cola = cola_encolar(cola, elemento1);
	size_t tamanio = cola_tamanio(cola);
	if (tamanio != 1) {
		cola_destruir(cola);
		return true;
	}
	cola_destruir(cola);
	return false;
}

bool elemento_cola_null(cola_t *cola)
{
	void *elemento = cola_frente(cola);
	if (elemento != NULL) {
		return true;
	}
	return false;
}

bool cola_esta_vacia(cola_t *cola)
{
	bool vacia = cola_vacia(cola);
	if (vacia == false) {
		return true;
	}
	return false;
}

bool no_puede_apilar(pila_t *pila)
{
	void *elemento = NULL;
	pila = pila_apilar(pila, elemento);
	if (pila != NULL) {
		return true;
	}
	return false;
}

bool no_puede_desapilar(pila_t *pila)
{
	pila = pila_desapilar(pila);
	if (pila != NULL) {
		return true;
	}
	return false;
}

bool tamanio_pila_invalido()
{
	pila_t *pila = pila_crear();
	int valor1 = 1;
	void *elemento1 = &valor1;
	pila = pila_apilar(pila, elemento1);
	size_t tamanio = pila_tamanio(pila);
	if (tamanio != 1) {
		pila_destruir(pila);
		return true;
	}
	pila_destruir(pila);
	return false;
}

bool elemento_pila_null(pila_t *pila)
{
	void *elemento = pila_tope(pila);
	if (elemento != NULL) {
		return true;
	}
	return false;
}

bool pila_esta_vacia(pila_t *pila)
{
	bool vacia = pila_vacia(pila);
	if (vacia == false) {
		return true;
	}
	return false;
}

lista_t *crea_lista()
{
	lista_t *lista = lista_crear();
	pruebas_afirmar(lista != NULL, "La lista se crea exitosamente.");
	return lista;
}

lista_t *cargar_lista(lista_t *lista)
{
	int valor1 = true;
	char valor2 = 'A';
	bool valor3 = 3;
	bool valor4 = 4;

	void *elemento1 = &valor1;
	void *elemento2 = &valor2;
	void *elemento3 = &valor3;
	void *elemento4 = &valor4;
	lista = lista_insertar(lista, elemento1);
	if (lista != NULL) {
		lista = lista_insertar(lista, elemento2);
		if (lista != NULL) {
			lista = lista_insertar(lista, elemento3);
			if (lista != NULL) {
				lista = lista_insertar(lista, elemento4);
			}
		}
	}
	pruebas_afirmar(lista != NULL, "La lista se carga exitosamente.");
	return lista;
}

void ver_tamanio(lista_t *lista)
{
	size_t tamanio = lista_tamanio(lista);
	pruebas_afirmar(tamanio == TAMANIO_ESPERADO,
			"El tamanio de la lista es correcto.");
}

lista_t *insertar_medio(lista_t *lista)
{
	int valor_aux = 14;
	void *elemento = &valor_aux;
	size_t posicion = 1;
	lista = lista_insertar_en_posicion(lista, elemento, posicion);
	size_t tamanio = lista_tamanio(lista);
	pruebas_afirmar(tamanio == TAMANIO_ESPERADO_2,
			"Se pudo insertar en el medio de la lista.");
	return lista;
}

void ver_eliminacion(lista_t *lista)
{
	void *elemento = lista_quitar(lista);
	if (elemento != NULL) {
		size_t tamanio = lista_tamanio(lista);
	}
	pruebas_afirmar(tamanio == TAMANIO_ESPERADO,
			"La eliminacion al final fue exitosa.");
}

void ver_eliminacion_posicion(lista_t *lista)
{
	size_t posicion = 0;
	void *elemento = lista_quitar_de_posicion(lista, posicion);
	if (elemento != NULL) {
		size_t tamanio = lista_tamanio(lista);
	}
	pruebas_afirmar(tamanio == TAMANIO_ESPERADO_3,
			"La eliminacion en posicion fue exitosa.");
}

void conseguir_elemento(lista_t *lista)
{
	size_t posicion = 2;
	void *elemento = NULL;
	elemento = lista_elemento_en_posicion(lista, posicion);
	pruebas_afirmar(elemento != NULL, "Se pudo obtener el elemento.");
}

void conseguir_primero(lista_t *lista)
{
	void *elemento = lista_primero(lista);
	pruebas_afirmar(elemento != NULL, "Se consiguio el primer elemento.");
}

void conseguir_ultimo(lista_t *lista)
{
	void *elemento = lista_ultimo(lista);
	pruebas_afirmar(elemento != NULL, "Se consiguio el ultimo elemento.");
}

void comprobar_lista_cargada(lista_t *lista)
{
	bool vacia = lista_vacia(lista);
	pruebas_afirmar(vacia == false, "La lista no esta vacia.");
}

void manejos_iterador(lista_t *lista)
{
	lista_iterador_t *iterador = lista_iterador_crear(lista);
	pruebas_afirmar(iterador != NULL, "El iterador se creo con exito.");
	if (iterador != NULL) {
		bool existe_siguiente =
			lista_iterador_tiene_siguiente(iterador);
		pruebas_afirmar(existe_siguiente == true,
				"Existe siguiente para iterar.");
		if (existe_siguiente == true) {
			bool se_avanzo = lista_iterador_avanzar(iterador);
			pruebas_afirmar(se_avanzo == true,
					"Se pudo avanzar de forma exitosa.");
			if (se_avanzo == true) {
				void *elemento = lista_iterador_elemento_actual(
					iterador);
				pruebas_afirmar(
					elemento != NULL,
					"Se pudo acceder al elemento del iterador");
			}
		}
	}
	lista_iterador_destruir(iterador);
	return;
}

cola_t *creacion_cola()
{
	cola_t *cola = cola_crear();
	pruebas_afirmar(cola != NULL, "La cola se creo con exito.");
	return cola;
}

cola_t *prueba_encolar(cola_t *cola)
{
	int valor1 = 1;
	int valor2 = 2;
	int valor3 = 3;
	void *elemento1 = &valor1;
	void *elemento2 = &valor2;
	void *elemento3 = &valor3;
	cola = cola_encolar(cola, elemento1);
	cola = cola_encolar(cola, elemento2);
	cola = cola_encolar(cola, elemento3);
	pruebas_afirmar(cola != NULL, "Se puede encolar los elementos.");
	size_t tamanio = cola_tamanio(cola);
	pruebas_afirmar(tamanio == TAMANIO_ESPERADO_3,
			"La cantidad de elementos es correcta.");
	return cola;
}

cola_t *prueba_desencolar(cola_t *cola)
{
	void *elemento = cola_desencolar(cola);
	size_t tamanio = cola_tamanio(cola);
	pruebas_afirmar(elemento != NULL,
			"El elemento se borro de forma exitosa.");
	pruebas_afirmar(tamanio == TAMANIO_ESPERADO_4,
			"La nueva cantidad de elementos es correcta.");
	return cola;
}

void elemento_cola_valido(cola_t *cola)
{
	void *elemento = cola_frente(cola);
	pruebas_afirmar(elemento != NULL, "Se pudo obtener el elemento.");
}

void cola_esta_cargada(cola_t *cola)
{
	bool esta_vacia = cola_vacia(cola);
	pruebas_afirmar(esta_vacia == false, "La cola no esta vacia.");
}

pila_t *creacion_pila()
{
	pila_t *pila = pila_crear();
	pruebas_afirmar(pila != NULL, "La pila se creo con exito.");
	return pila;
}

pila_t *prueba_apilar(pila_t *pila)
{
	int valor1 = 1;
	int valor2 = 2;
	int valor3 = 3;
	void *elemento1 = &valor1;
	void *elemento2 = &valor2;
	void *elemento3 = &valor3;
	pila = pila_apilar(pila, elemento1);
	pila = pila_apilar(pila, elemento2);
	pila = pila_apilar(pila, elemento3);
	pruebas_afirmar(pila != NULL, "Se puede apilar los elementos.");
	size_t tamanio = pila_tamanio(pila);
	pruebas_afirmar(tamanio == TAMANIO_ESPERADO_3,
			"La cantidad de elementos es correcta.");
	return pila;
}

pila_t *prueba_desapilar(pila_t *pila)
{
	void *elemento = pila_desapilar(pila);
	size_t tamanio = pila_tamanio(pila);
	pruebas_afirmar(elemento != NULL,
			"El elemento se borro de forma exitosa.");
	pruebas_afirmar(tamanio == TAMANIO_ESPERADO_4,
			"La nueva cantidad de elementos es correcta.");
	return pila;
}

void elemento_pila_valido(pila_t *pila)
{
	void *elemento = pila_tope(pila);
	pruebas_afirmar(elemento != NULL, "Se pudo obtener el elemento.");
}

void pila_esta_cargada(pila_t *pila)
{
	bool esta_vacia = pila_vacia(pila);
	pruebas_afirmar(esta_vacia == false, "La pila no esta vacia.");
}

void probar_NULL_o_errores()
{
	lista_t *lista_vacia_aux = NULL;
	void *elemento = NULL;
	bool hay_error = false;
	hay_error = no_puede_insertar_final(lista_vacia_aux, elemento);
	hay_error = tamanio_lista_vacia(lista_vacia_aux, elemento);
	hay_error = quitar_lista_vacia(lista_vacia_aux);
	hay_error = posicion_inexistente();
	hay_error = no_se_puede_comparar(lista_vacia_aux);
	hay_error = no_hay_primero(lista_vacia_aux);
	hay_error = lista_vacia_test(lista_vacia_aux);
	hay_error = falla_crear_iterador(lista_vacia_aux);
	hay_error = no_sigue_iterando();
	hay_error = no_aplica_cada_elemento();
	cola_t *cola_aux = NULL;
	hay_error = no_puede_encolar(cola_aux);
	hay_error = no_puede_desencolar(cola_aux);
	hay_error = tamanio_cola_invalido();
	hay_error = elemento_cola_null(cola_aux);
	hay_error = cola_esta_vacia(cola_aux);
	pila_t *pila_aux = NULL;
	hay_error = no_puede_apilar(pila_aux);
	hay_error = no_puede_desapilar(pila_aux);
	hay_error = tamanio_pila_invalido();
	hay_error = elemento_pila_null(pila_aux);
	hay_error = pila_esta_vacia(pila_aux);

	pruebas_afirmar(hay_error == false,
			"El programa cumple en los casos NULL y de error.");
}

void casos_puntuales_lista()
{
	lista_t *lista = crea_lista();
	lista = cargar_lista(lista);
	ver_tamanio(lista);
	lista = insertar_medio(lista);
	ver_eliminacion(lista);
	ver_eliminacion_posicion(lista);
	conseguir_elemento(lista);
	conseguir_primero(lista);
	conseguir_ultimo(lista);
	comprobar_lista_cargada(lista);
	manejos_iterador(lista);
	lista_destruir(lista);
}

void casos_puntuales_cola()
{
	cola_t *cola = creacion_cola();
	cola = prueba_encolar(cola);
	cola = prueba_desencolar(cola);
	elemento_cola_valido(cola);
	cola_esta_cargada(cola);
	cola_destruir(cola);
}

void casos_puntuales_pila()
{
	pila_t *pila = creacion_pila();
	pila = prueba_apilar(pila);
	pila = prueba_desapilar(pila);
	elemento_pila_valido(pila);
	pila_esta_cargada(pila);
	pila_destruir(pila);
}

int main()
{
	pruebas_nuevo_grupo(
		"\n======================== XXX ========================");
	pruebas_nuevo_grupo("\nCasos Null o de error.\n");
	probar_NULL_o_errores();
	pruebas_nuevo_grupo("\nCasos puntuales de lista.\n");
	casos_puntuales_lista();
	pruebas_nuevo_grupo("\nCasos puntuales de cola.\n");
	casos_puntuales_cola();
	pruebas_nuevo_grupo("\nCasos puntuales de pila.\n");
	casos_puntuales_pila();
	pruebas_nuevo_grupo(
		"\n======================== XXX ========================");

	return pruebas_mostrar_reporte();
}