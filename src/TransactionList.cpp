/*
 * @file TransactionList.cpp
 * This is the header file for an unsorted linked list.
 * It holds pointers of Hashable class.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * TransactionList Class:
 * This data structure is used to hold the transaction history of a customer,
 * in chronological order.
 * -- Linked node data structure
 * -- Stores a Hashable* pointer to the transaction object
 * -- Stores quantity of each object
 * -- Stores whether the object was purchased or sold (e.g. "Buy" "Sold")
*/

#include "TransactionList.h"

//------------------------------Constructor---------------------------
/* Default constructor.
* @pre     None.
* @post    Constructor. Initializes to the passed parameters and 
*          next = nullptr
*/
TransactionList::Node::Node(const string transaction,
                            Hashable* obj) {
   type = transaction;
   item = obj;
   next = nullptr;
}

//------------------------------Destructor----------------------------------
/* Destructor.
* @pre     None.
* @post    Deletes dynamic memory
*/
TransactionList::~TransactionList() {
   destroy(headPtr);
   backPtr = nullptr;
}

//------------------------------destroy------------------------------------
/* Traverses list and deletes dynamic memory.
* @pre     None.
* @post    Deletes dynamic memory
*/
void TransactionList::destroy(Node* ptr) {
   // Base case is root = nullptr
   if (ptr != nullptr) { // if tree not empty.

      destroy(ptr->next); // go to next node

      //Delete data and release memory.
      delete ptr->item; // delete Hashable object
      delete ptr;
      ptr = nullptr;
   }
}

//------------------------------getCurrentSize------------------------------
/* Gets the current number of objects in this list.
* @pre     None.
* @post    Returns the number of objects currently in the list.
*/
int TransactionList::getCurrentSize() const {
   return listSize;
}

//------------------------------isEmpty-------------------------------------
/* Sees whether this list is empty.
* @pre     None.
* @post    True if empty, false if not.
*/
bool TransactionList::isEmpty() const {
   return (listSize == 0);
}

//------------------------------add-----------------------------------------
/* Adds the Hashable pointer to the list.
* @pre     None.
* @post    Adds to the back of the list. Transaction is "Buy" or "Sell".
*/
bool TransactionList::add(string transaction,
                          Hashable* ptr) {
   // If empty store at the front
   if (headPtr == nullptr) {
      headPtr = new Node(transaction, ptr);
      backPtr = headPtr; // only one item, so backPtr points to it.
      listSize++;
      return true;
   }
   else {
      Node* temp = new Node(transaction, ptr);
      backPtr->next = temp;
      backPtr = temp; // point to new back item.
      listSize++;
      return true;
   }
}

//------------------------------print---------------------------------------
/* Traverses the list and outputs to console.
* @pre     None.
* @post    Example output: "Object Stored : Quantity 5 : Transaction Buy"
*/
void TransactionList::print() const {
   // Print user information first
   if (!isEmpty()) {
      cout << "Customer Information : " << userInfo << "\n";

      // Print from front to back
      Node* ptr = headPtr;
      while (ptr != nullptr) {
         cout << setw(45) << left << ptr->item->toString() << " : Quantity 1"
            << " : " << "Transaction " << ptr->type << "\n";
         ptr = ptr->next;
      }
   }
   
}
