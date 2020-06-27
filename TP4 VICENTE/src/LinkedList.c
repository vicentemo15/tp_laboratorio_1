/*
 * LinkedList.c
 *
 *  Created on: 18 jun. 2020
 *      Author: sebam
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!= NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;

    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i = 0;
    Node* nodoActual = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		nodoActual = this->pFirstNode;

	    while(nodeIndex != i)
	    {
	    	nodoActual = nodoActual->pNextNode;
	    	i++;
	    }

	}

    return nodoActual;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nodoNuevo = NULL;
    Node* nodoAnterior= NULL;

    if (this != NULL && nodeIndex >=0 && nodeIndex <ll_len(this)+1)
    {

    	if ( this->pFirstNode == NULL && this->size ==0 )
    	{
    		nodoNuevo = (Node*) malloc(sizeof(Node));
    		nodoNuevo->pElement = pElement;
    		nodoNuevo->pNextNode = NULL;
    		this->pFirstNode = nodoNuevo;
    	    this->size = this->size + 1;
    		returnAux = 0;
    	}else if(nodeIndex == 0 && this->size !=0)
    	{
    		nodoNuevo = (Node*) malloc(sizeof(Node));
    		nodoNuevo->pElement = pElement;
    		nodoNuevo->pNextNode= this->pFirstNode;
    		this->pFirstNode = nodoNuevo;
    		this->size = this->size + 1;
    		returnAux = 0;
    	}else
    	{
    		nodoAnterior= getNode(this,nodeIndex-1);

    		if (nodoAnterior!= NULL)
    		{

    			nodoNuevo = (Node*) malloc(sizeof(Node));
    			nodoNuevo->pElement = pElement;
    			nodoNuevo->pNextNode= nodoAnterior->pNextNode;
    			nodoAnterior->pNextNode = nodoNuevo;
    			this->size = this->size + 1;
    			returnAux = 0;
    		}
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)

    {
    	returnAux = addNode(this,ll_len(this),pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxiliar = NULL;
    if( this!= NULL && index >= 0 && index < ll_len(this) )
    {
    	auxiliar= getNode(this,index);
    	if (auxiliar != NULL)
    	{
    		returnAux = auxiliar->pElement;
    	}
    }


    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxiliar = NULL;

    if( this!= NULL && index >=0 && index <ll_len(this) )
    {
    	auxiliar = getNode(this,index);
        free(auxiliar->pElement);
    	auxiliar->pElement = pElement;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxiliar = NULL;
    Node* auxiliarAnterior = NULL;
    if( this!= NULL && index >=0 && index <ll_len(this))
    {
    	auxiliar = getNode(this,index);
    	if (index == 0)
    	{
    		this->pFirstNode = auxiliar->pNextNode;
    	}
    	else
    	{
        	auxiliarAnterior = getNode(this,index-1);
        	auxiliarAnterior->pNextNode = auxiliar->pNextNode;
    	}

    	if (auxiliar->pElement != NULL)
    	{
    		free(auxiliar->pElement);
    	}
    	free(auxiliar);
    	this->size = this->size - 1;
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i ;
    if( this != NULL)
    {
    	for(i=ll_len(this)-1;i >= 0;i--)
    	{
    		ll_remove(this,i);
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
   if (this != NULL)
   {
	   ll_clear(this);
	   free (this);
	   returnAux = 0;
   }

   return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	void* auxiliar = NULL;
	int i ;
	if( this != NULL)
	{
		for(i=0;i < ll_len(this);i++)
		{
			auxiliar = ll_get(this,i);
			if (pElement == auxiliar)
			{
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int returnAux = -1;
	if( this != NULL)
	{
		if (this->size == 0)
		{
			returnAux = 1;
		}else
		{
			returnAux = 0;
		}

	}

	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{

	return addNode(this, index, pElement);

}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* auxNode = NULL;

    if( this!= NULL && index >=0 && index <ll_len(this))
    {
    	auxNode = getNode(this,index);
    	if (auxNode!= NULL)
    	{
    		returnAux = auxNode->pElement;
    		ll_remove(this,index);
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	int auxIndex ;
	if (this != NULL)
	{
		auxIndex = ll_indexOf(this,pElement);
		if (auxIndex != -1)
		{
			returnAux = 1;
		}else
		{
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int i;
    void* auxElemento = NULL;
    if (this != NULL && this2 != NULL )
    {
    	for (i=0; i < ll_len(this2);i++)
    	{
    		auxElemento = ll_get( this2, i);
    		if (ll_contains(this,auxElemento)== 0)
    		{
    			return 0;
    		}
    	}
    	return 1;
    }
    return -1;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* auxElemento = NULL;
    if (this != NULL && from >=0 && from < ll_len(this) && from < to && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	for (i = from; i < to; i++)
    	{
    		auxElemento = ll_get( this, i);
    		ll_add(cloneArray,auxElemento);
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if (this != NULL)

   {
    	cloneArray = ll_subList(this,0,ll_len(this));

   }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
	int flagSwap;
	int i;
	int auxiliarCmp;
	Node* nodo1 = NULL;
	Node* nodo2 = NULL;
	void* auxElement = NULL;
	int len = 0;

	if(this != NULL && ll_len(this) > 0 && pFunc != NULL && (order == 0 || order == 1))
	{
		len = ll_len(this) - 1;
		do
		{
			flagSwap = 0;
			for(i=0;i < len; i++)
			{
				nodo1 = getNode(this, i);
				nodo2 = getNode(this, i + 1);
				auxiliarCmp = pFunc(nodo1->pElement, nodo2->pElement);
				if((auxiliarCmp > 0 && order == 1) || (auxiliarCmp < 0 && order == 0))
				{
					flagSwap = 1;
					auxElement = nodo1->pElement;
					nodo1->pElement = nodo2->pElement;
					nodo2->pElement=auxElement;
				}
			}

			len--;
		} while(flagSwap);
		returnAux = 0;
	}

    return returnAux;
}

/** \brief Cambios en el pElmento.
 * \param pList LinkedList* Puntero a la lista
 *  param pFunc LinkedList* Puntero a la funcion
 * \return LinkedList* Retorna  (-1) Error: si el puntero a la lista o funcion es NULL y
                                (0) Si ok
*/
 int ll_map(LinkedList* this, int (*pFunc)(void*))
 {

	 int returnAux =-1;
	 int i;
	 void* pElement;
	 if (this != NULL && pFunc!= NULL)
	 {

		 for (i=0;i<ll_len(this);i++)
		 {
			 pElement = ll_get(this,i);
			  if (pFunc(pElement) < 0)
			  {
				  printf( "Error");
			  }
		 }
		 returnAux = 0;
	 }
	 return returnAux;

 }

 /** \brief Obtiene una nueva lista.
  * \param pList LinkedList* Puntero a la lista
  *  param pFunc LinkedList* Puntero a la funcion
  * \return LinkedList* Retorna  (listaFiltrada) Error: si el puntero a la lista o funcion es NULL y
                                 (puntero a la nueva lista) Si ok
 */
 LinkedList* ll_filter(LinkedList* this, int (*pFuncion)(void*))
 {
 	LinkedList* listaFiltrada = NULL;
 	int i;
 	void* element = NULL;

 	if ( this != NULL && pFuncion != NULL )
 	{
 		listaFiltrada = ll_newLinkedList();
 		for(i=0;i<ll_len(this);i++)
 		{
 			element = ll_get(this,i);
 			if( pFuncion(element)==0 )
 			{
 				ll_add(listaFiltrada,element);
 			}
 		}
 	}
 	return listaFiltrada;
 }

 /** \brief Obtiene una nueva lista.
   * \param pList LinkedList* Puntero a la lista
   *  param pFunc LinkedList* Puntero a la funcion
   * \return LinkedList* Retorna  (listaFiltrada) Error: si el puntero a la lista o funcion es NULL y
                                  (puntero a la nueva lista) Si ok
  */
  int ll_reduce(LinkedList* this, int (*pFuncion)(void*, int,int))
  {
	  int i;
	  void* element = NULL;
	  int valor = 0;

	  if ( this != NULL && pFuncion != NULL )
	  {
		  for(i=0;i<ll_len(this);i++)
		  {
			  element = ll_get(this,i);
			  valor = pFuncion(element,valor,i);
		  }
	  }
	  return valor;
  }

  void* ll_reduceDos(LinkedList* this, int (*pFuncion)(LinkedList* this))
  {
	  void* element = NULL;
	  int valor = 0;

	  if ( this != NULL && pFuncion != NULL )
	  {
		  valor = pFuncion(this);
		  element = ll_get(this,valor);
	  }
	  return element;
  }
