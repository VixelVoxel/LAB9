/**************************************************************************/
/*          Coda con priorita' implementata come heap binario             */
/**************************************************************************/

#include "priority_queue.h"
#include <cmath>

// Funzioni ausiliarie che non appartengono al TDD

// tra i due indici, restituisce quello che corrisponde al timestamp inferiore
int minTimeStamp(priorityQueue::PriorityQueue pq, int index1, int index2)
{
  if (index1 >= pq.size && index2 >= pq.size)
    // entrambi gli indici sono fuori dal limite dello heap
    return -1;
  if (index1 >= pq.size)
    // il primo e' fuori, restituisco il secondo
    return index2;
  if (index2 >= pq.size)
    // il secondo e' fuori, restituisco il primo
    return index1;

  // entrambi sono dentro lo heap, scelgo quello con timestamp inferiore
  if (pq.data[index1].timeStamp < pq.data[index2].timeStamp)
    return index1;
  else
    return index2;
}

void moveDown(int index, priorityQueue::PriorityQueue pq) // riordina l'elemento in posizione index facendolo scendere alla profondità giusta di pq.
{
  int cur = index;
  while (cur != pq.size && pq.data[cur].timeStamp > pq.data[2 * cur].timeStamp)
  {
    int padreh = (cur - 2) / 2;
    priorityQueue::PQVeicoloElem fatherData = pq.data[padreh];
    pq.data[padreh] = pq.data[cur];
    pq.data[pq.size] = fatherData;
    cur = padreh;
  }
  return;
}

void moveUp(int index, priorityQueue::PriorityQueue pq) // riordina l'elemento in posizione index facendolo salire all'altezza giusta di pq.
{
  int cur = index;
  while (cur != 0 && pq.data[cur].timeStamp < pq.data[(cur - 2) / 2].timeStamp)
  {
    int padreh = (cur - 2) / 2;
    priorityQueue::PQVeicoloElem fatherData = pq.data[padreh];
    pq.data[padreh] = pq.data[cur];
    pq.data[pq.size] = fatherData;
    cur = padreh;
  }
  return;
}

// Funzioni del TDD PriorityQueue

// crea una PriorityQueue di dimensione dim
priorityQueue::PriorityQueue priorityQueue::createEmptyPQ(int dim)
{
  PriorityQueue pq;
  priorityQueue::PQVeicoloElem *array = new PQVeicoloElem[dim];
  pq.data = array;
  pq.maxsize = dim;
  pq.size = 0;
  return pq;
}

// verifica se una PriorityQueue e' vuota
bool priorityQueue::isEmpty(const PriorityQueue &pq)
{
  if (pq.size == 0)
  {
    return true;
  }
  return false;
}

// inserisce un Elem in una PriorityQueue (nella posizione corretta) e ritorna TRUE
// nel caso in cui la PriorityQueue sia piena ritorna FALSE
// suggerimento: inserire in fondo e poi chiamare la funzione ausiliaria moveUp(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::insert(PriorityQueue &pq, const Elem &elem)
{
  if (pq.size < pq.maxsize) // controllo che la PriorityQueue non si piena prima di aggiungere
  {
    pq.data[pq.size] = elem;
    moveUp(pq.size, pq);
    pq.size = pq.size + 1;
    return true;
  }
  return false;
}

// ritorna FALSE se PriorityQueue e' vuota
// altrimenti TRUE e l'Elem minimo nella PriorityQueue in res
// (cioe' quello radice in posizione 0)
bool priorityQueue::findMin(const PriorityQueue &pq, Elem &res)
{
  if (!isEmpty(pq))
  {
    res = pq.data[0];
    return true;
  }
  return false;
}

// ritorna FALSE se PriorityQueue e' vuota
// altrimenti TRUE ed elimina l'Elem minimo nella PriorityQueue
// (cioe' quello radice in posizione 0)
// suggerimento: sostituiamo la radice dell'albero con l'ultimo elemento
//   e poi chiamare la funzione ausiliaria moveDown(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::deleteMin(PriorityQueue &pq)
{
  if (!isEmpty(pq))
  {
    pq.data[0] = pq.data[pq.size - 1];
    moveDown(0, pq);
    return true;
  }
  return false;
}