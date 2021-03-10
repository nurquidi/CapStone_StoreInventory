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
 * -- Linked node data structure
 * -- Stores a Hashable* pointer to the transaction object
 * -- Stores quantity of each object
 * -- Stores whether the object was purchased or sold (e.g. "Buy" "Sold")
*/

#pragma once
#include "Hashable.h"
#include <iostream>
#include <iomanip>


class TransactionList
{
private:
   //-----------------------------NESTED STRUCT NODE-----------------------
   /**
    * Data structure that forms the linked nodes.
   */
   struct Node
   {
      string type;    // Stores transaction type, "Sell" or "Buy" is stored.
      Hashable* item; // Pointer to Hashable item.
      Node* next;     // Pointer to next node.

      //------------------------------Constructor---------------------------
      /* Default constructor.
      * @pre     None.
      * @post    Constructor. Initializes quantity = 0, type empty, item = 
      *          nullptr and next = nullptr.
      */
      Node() : type(), item(nullptr), next(nullptr) {};

      //------------------------------Constructor---------------------------
      /* Default constructor.
      * @pre     None.
      * @post    Constructor. Initializes to the passed parameters and
      *          next = nullptr
      */
      Node(const string transaction, Hashable* obj);
   };

   //------------------------------destroy------------------------------------
   /* Traverses list and deletes dynamic memory.
   * @pre     None.
   * @post    Deletes dynamic memory
   */
   void destroy(Node* ptr);

   int listSize;      // Number of entries in the list.
   Node* headPtr;     // Pointer to the first Node in the list.
   Node* backPtr;     // Pointer to the last Node in the list.
   string userInfo;   // Stores string that identifies the owner of this list.

public:
   //------------------------------Constructor---------------------------------
   /* Default constructor.
   * @pre     None.
   * @post    Constructor. Initializes Node <int>* headPtr = nullptr,
   *          backPtr = nullptr, listSize(0) and userInfo to empty.
   */
   TransactionList() : listSize(0), headPtr(nullptr), backPtr(nullptr),
                       userInfo() {};

   //------------------------------Constructor---------------------------------
   /* Default constructor.
   * @pre     None.
   * @post    Constructor. Initializes Node <int>* headPtr = nullptr,
   *          backPtr = nullptr, listSize(0) and sets user information.
   */
   TransactionList(const string user) : listSize(0), headPtr(nullptr), 
                   backPtr(nullptr), userInfo(user) {};

   //------------------------------Destructor----------------------------------
   /* Destructor.
   * @pre     None.
   * @post    Deletes dynamic memory
   */
   ~TransactionList();

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
   * @post    Adds to the back of the list. Transaction is "Buy" or "Sell".
   */
   bool add(string transaction, Hashable* ptr);
 

   //------------------------------print---------------------------------------
   /* Traverses the list and outputs to console.
   * @pre     None.
   * @post    Example output: "Object Stored : Quantity 1 : Transaction Buy"
   */
   void print() const;

};
