#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  // base case
  if (head == nullptr)
  {
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  llpivot(head->next, smaller, larger, pivot);

  // if val is less or equal to pivot
  if ((head->val) <= pivot)
  {
    // if new, create new LL
    if (smaller == NULL){
      smaller = head;
    }   
    else if (smaller != NULL){
      head->next = smaller;
      smaller = head;
    }
  }

  // if val is greater than pivot
  else if ((head->val) > pivot)
  {
    
    if (larger == NULL){
      larger = head;
    }
    else if (larger != NULL){
      head->next = larger;
      larger = head;
    }
  }

  head = NULL;
}
