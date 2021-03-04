/*
 * @file InventoryMgr.h
 * Manager class that handles the inventory for a one store branch.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * InventoryMgr Class:
 * Two data structures are used in this class.
 * - Hashtable that stores inventory according to item type.
 * - A sorted list that keeps a track of inventory. Sorting is done using
 *   Hashable::operator<
*/

#pragma once
#include "Hashable.h"
#include "LinkedList.h"
#include "FactoryHashable.h"
#include <string>
#include <fstream>

using namespace std;

class InventoryMgr
{
private:
   FactoryHashable factoryObj;  // Factory class for creating Hashable objects.
   LinkedList* hashTable[2];    // holds inventory for store.

   //------------------------------hash----------------------------------------
   /* Takes a char and returns the index number for the createOjb array.
   * @pre     Only capital chars and must be C, M or S
   * @post    Converts the char into a hash number (index of array).
   */
   int hash(const char ch) const;
   // create a hash function that will result in C = 0, M = 1, S = 2

public:
   //------------------------------Constructor---------------------------------
   /* Default constructor.
   * @pre     None.
   * @post    Constructor. Initializes the hashTable to nullptrs.
   */
   InventoryMgr();


   //------------------------------Destructor----------------------------------
   /* Destructor.
   * @pre     None.
   * @post    Deletes dynamic memory
   */
   ~InventoryMgr();

   //------------------------------loadInventory-------------------------------
   /* Loads inventory with input from file.
   * @pre     File formatted correctly.
   * @post    Loads the customerList sorted linked list with the give
   *          customer file.
   */
   void loadInventory(ifstream& infile);
   // Read one line at a time, extract the first character of each line and
   // save as a char.  Convert the rest of the text into a string.
   // Pass the char and string to factoryObj to create the appropriate 
   // Hashable item. The factoryObj will return a pointer for each item, load
   // the pointer into the hashTable at the correct location.

   //------------------------------buyItem-------------------------------------
   /*
   * @pre     Must be existing item in inventory.
   * @post    Searches for the item and increments the count.
   *          Memory management: Passed pointer is deleted and set to nullptr.
   */
   void buyItem(const int code, Hashable* item);
      // Use the code (item type) and the hash() function to find the correct 
      // index for the hashTable.
      // Use add() method for LinkedList object to add the item.

   //------------------------------sellItem------------------------------------
   /*
   * @pre     Must be existing item in inventory.
   * @post    Searches for the item and decreases the count. Count cannot be
   *          lower than 0.
   *          Memory management: Passed pointer is deleted and set to nullptr.
   */
   void sellItem(const int code, Hashable* item);
      // Use the code (item type) and the hash() function to find the correct 
      // index for the hashTable.
      // Use add() method for LinkedList object to add the item.

   //------------------------------displayAll-----------------------------
   /*
   * @pre     None.
   * @post    Displays the entire contents of the inventory, including the 
   *          number of each item in inventory.
   *          Display order is Coins, Comics and Sports. All separted by 
   *          new lines.
   */
   void displayAll();
      // Iterated through the hashTable and use the print() method of the 
      // LinkedList to display contents.

};
