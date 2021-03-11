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
 * - A SearchTree that keeps a track of inventory. Sorting is done using
 *   Hashable::operator<
*/

#pragma once
#include "SearchTree.h"
#include "FactoryHashable.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class InventoryMgr
{
private:
   static const int ARRAYSIZE = 3;
   FactoryHashable factoryObj;  // Factory class for creating Hashable objects.
   SearchTree* hashTable[ARRAYSIZE];  // A collection of collections to hold inventory.

   //------------------------------hash----------------------------------------
   /* Takes a char and returns the index number for the createOjb array.
   * @pre     Only capital chars and must be C, M or S
   * @post    Converts the char into a hash number (index of array).
   *          Returns -1 if wrong input is provided.
   */
   int hash(const char ch) const;

   //------------------------------loadHelper-------------------------------
   /* Loads inventory with code input, quantity and data string.
   * @pre     Valid char code for the hashtable. Only capital chars and
   *          must be C, M or S.
   *          string data must be the correct format for the object type.
   *          Format:
   *                 - No leading spaces in the string
   *                 - A single comma followed by a space in between
   *                 data strings.
   *          Coin:  Year(int), grade(int), type(string)
   *                 Example string: "2001, 65, Lincoln Cent"
   *          SportsCard: Year(int), grade(string), player(string), and
   *                 manufacturer(strint)
   *                 Example string: "1989, Near Mint, Ken Griffey Jr.,
   *                                  Upper Deck"
   *          ComicBook: Year(int), grade(string), title(string), and
   *                 publisher(string)
   *                 Example string: "2010, Excellent, X-Men, Marvel"
   * @post    Loads the inventory item the hashTable.
   */
   void loadHelper(char c, int count, string data);

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

   //------------------------------buyItem-------------------------------------
   /*
   * @pre     Must be existing item in inventory.
   * @post    Searches for the item and increments the count.
   *          Returns true if sucessful.
   *          Memory management: Passed pointer is deleted and set to nullptr.
   */
   bool buyItem(const char code, Hashable* item);

   //------------------------------sellItem------------------------------------
   /*
   * @pre     Must be existing item in inventory.
   * @post    Searches for the item and decreases the count. Count cannot be
   *          lower than 0.
   *          Returns true if sucessful.
   *          Memory management: Passed pointer is deleted and set to nullptr.
   */
   bool sellItem(const char code, Hashable* item);

   //------------------------------displayAll-----------------------------
   /*
   * @pre     None.
   * @post    Displays the entire contents of the inventory, including the 
   *          number of each item in inventory.
   *          Display order is Coins, Comics and Sports. All separted by 
   *          new lines.
   */
   void displayAll();

};
