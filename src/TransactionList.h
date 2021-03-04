/*
 * @file TransactionList.h
 * This is the header file for an unsorted linked list.
 * It holds pointers of Hashable class.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * TransactionList Class:
 * This data structure is used to hold the transaction history of a customer, 
 * in chronological order.
*/

#pragma once
#include "Hashable.h"


class TransactionList
{
private:
   //-----------------------------NESTED STRUCT NODE-----------------------
   /**
    * Data structure that forms the linked nodes.
   */
   struct Node
   {
      int count;      // Keeps track of number of one item there are.
      Hashable* item; // Pointer to Hashable item.
      Node* next;     // Pointer to next node.
   };

   int listSize;      // Number of entries in the list.
   Node* headPtr;     // Pointer to the first Node in the list.

public:
   //------------------------------Constructor---------------------------------
   /* Default constructor.
   * @pre     None.
   * @post    Constructor. Initializes Node <int>* headPtr = nullptr
   *          and listSize(0).
   */
   TransactionList();

   //------------------------------Destructor----------------------------------
   /* Destructor.
   * @pre     None.
   * @post    Deletes dynamic memory
   */
   ~TransactionList();
      // Traverse all nodes and delete memory

   //------------------------------getCurrentSize------------------------------
   /* Gets the current number of objects in this list.
   * @pre     None.
   * @post    Returns the number of objects currently in the list.
   */
   int getCurrentSize() const;

   //------------------------------isEmpty-------------------------------------
   /* Sees whether this list is empty.
   * @pre     None.
   * @post    True if empty, false if not.
   */
   bool isEmpty() const;

   //------------------------------add-----------------------------------------
   /* Adds the Hashable pointer to the list.
   * @pre     None.
   * @post    Adds to the back of the list.
   * @param   int counter
   * @param   Hashable* ptr
   */
   bool add(int counter, Hashable* ptr);
 

   //------------------------------print---------------------------------------
   /* Traverses the list and outputs to console.
   * @pre     None.
   * @post    At each node the count is output to console followed by a space
   *          followed by the toString() method from the Hashable object.
   */
   void print() const;

};
