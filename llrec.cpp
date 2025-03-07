#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  if(head==nullptr) //BASE CASE: empty list
  {
    smaller=nullptr;
    larger=nullptr;
    return;
  }

  //COMPARE head->val to pivot
  smaller=nullptr;
  larger=nullptr;
  Node* headList = head;   
  head = head->next;
  headList->next=nullptr;

  if(headList->val<=pivot)
  {
    smaller = headList;
    llpivot(head, smaller->next, larger, pivot);
  }
  else{
    larger = headList;
    llpivot(head, smaller, larger->next, pivot);
  }
  
}

