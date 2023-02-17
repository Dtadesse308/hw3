#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    //base case
  if (head == nullptr)
  {
    return;
  }

  split(head->next, smaller, larger,pivot);

  //if val is less or equal to pivot
  if ((head->value) <= pivot)
  {
    //if new, create new LL
    if (smaller == nullptr)
    { 
      Node *newp = new Node((head->value), nullptr);
      smaller = newp;
    }
    //if existing, add to LL
    else
    {
      Node *newp = new Node((head->value), smaller);
      smaller = newp;
    }
  }

  //if val is greater than pivot
  else if ((head->value) > pivot)
  {
     //if new, create new LL
    if (larger == nullptr)
    {
      Node *newp = new Node((head->value), nullptr);
      larger = newp;
    }
    else
    {
      //if existing, add to LL
      Node *newp = new Node((head->value), larger);
      larger = newp;
    }
  }
  delete head;
  head = nullptr;
}
