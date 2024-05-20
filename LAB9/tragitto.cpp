#include "tragitto.h"

// verifica se un Tragitto e vuoto
bool tragitto::isEmpty(Tragitto tr)
{
  return (tr == tragittoVuoto);
}

// inserisce una Tappa in un Tragitto
void tragitto::insert(Tragitto &tr, Tappa t)
{
  TragittoElem *old = tr;
  TragittoElem *AUX = new TragittoElem;
  AUX->next = old;
  AUX->tappa = t;
  tr = AUX;
  return;
}

// ritorna FALSE se il Tragitto e vuoto
// altrimenti rimuove la prima Tappa del Tragitto
//    e la assegna al secondo parametro e ritorna TRUE
bool tragitto::extract(Tragitto &tr, Tappa &t)
{
  if (isEmpty(tr))
  {
    return false;
  }
  t = tr->tappa;
  tr = tr->next;
  return true;
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto tr)
{
  if (isEmpty(tr))
  {
    cout << "Tragitto Vuoto";
  }
  tragitto::TragittoElem *cur = tr;
  while (cur->next != tragitto::tragittoVuoto)
  {
    cout << cur->tappa.citta << " ";
    cout << cur->tappa.distanza << " ";
    cur = cur->next;
  }
  cout << "\n";
  return;
}
