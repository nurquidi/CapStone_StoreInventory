/* 
 * @file LinkedList.h
 * This is the header file for a sorted linked list.
 * It holds pointers of Hashable class and an int count field.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * LinkedList Class:
 * This data structure is used as an inventory list for the store. It holds
 * items (Hashable*) and an int count. It is also used to sort the customers.
*/

#pragma once
#include "Hashable.h"


class LinkedList
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
   LinkedList();

   //------------------------------Destructor----------------------------------
   /* Destructor.
   * @pre     None.
   * @post    Deletes dynamic memory
   */
   ~LinkedList();
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
   * @pre     Hashable object must be a comparable type so it can be sorted.
   * @post    If new item, it adds it to the linked list in sorted order, from 
   *          smallest to largest. If the item exists already then it increase
   *          the count only.
   *          Memory management: The passed object is destroyed if it already
   *                             exists in the list and is set to nullptr.
   * @param   int counter
   * @param   Hashable* ptr
   */
   bool add(int counter, Hashable* ptr);
      // Logic use the Hashable::operator< to insert at the correct location.

   //---------------------------decrement--------------------------------------
   /* Decrease the count of the object by 1.
   * @pre     Hashable object must be a comparable type so it can be sorted.
   * @post    If new item, it adds it to the linked list in sorted order, from
   *          smallest to largest. If the item exists already then it increase
   *          the count only.
   *          Memory management: The passed object is destroyed and set to 
   *                             nullptr.
   * @param   const Hashable* ptr
   */
   bool decrement(const Hashable* ptr);

   //------------------------------getCount------------------------------------
   /* Returns the count of the first item in the list
   * @pre     None.
   * @post    Returns the count of the first item in the list, this is the 
   *          smallest item in sorted order.
   */
   int getCount() const;
      // return count;

   //------------------------------removeMin-----------------------------------
   /* Removes the first item in the list.
   * @pre     None.
   * @post    Returns the pointer to the removed item from the front of the 
   *          list, this is the smallest item in sorted order.
   */
   Hashable* removeMin() const;
      // return Hashable pointer at the front of the list. Delete the node.

   //------------------------------print---------------------------------------
   /* Traverses the list and outputs to console.
   * @pre     None.
   * @post    At each node the count is output to console followed by a space
   *          followed by the toString() method from the Hashable object.
   */
   void print() const;
 
};
