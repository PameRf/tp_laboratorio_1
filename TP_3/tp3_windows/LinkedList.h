/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);// me devuelve el elemento
int ll_set(LinkedList* this, int index,void* pElement);//me lo agrega en el indice y lo piso
int ll_remove(LinkedList* this,int index);//me devuelve si sali
int ll_clear(LinkedList* this);// vacia la la likedlis
int ll_deleteLinkedList(LinkedList* this);// free la borra
int ll_indexOf(LinkedList* this, void* pElement);//devuelve el indice
int ll_isEmpty(LinkedList* this);//si esta vacia o no
int ll_push(LinkedList* this, int index, void* pElement);// agregar a  uno nuevo y desplaza a los demas
void* ll_pop(LinkedList* this,int index);//devuelve el pax revomido lista de clientes inactivos
int ll_contains(LinkedList* this, void* pElement);//esta dentro o no
int ll_containsAll(LinkedList* this,LinkedList* this2);// dos likedlis si la segunda esta dentro dela primera
LinkedList* ll_subList(LinkedList* this,int from,int to);//lista nueva en rango de posisiones
LinkedList* ll_clone(LinkedList* this);//clona la lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//ordenamiento
