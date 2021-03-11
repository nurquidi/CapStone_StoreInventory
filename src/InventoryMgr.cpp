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

#include "InventoryMgr.h"

//------------------------------hash----------------------------------------
/* Takes a char and returns the index number for the createOjb array.
* @pre     Only capital chars and must be C, M or S
* @post    Converts the char into a hash number (index of array).
*          Returns -1 if wrong input is provided.
*/
int InventoryMgr::hash(const char ch) const {
   // create a hash function that will result in C = 0, M = 1, S = 2
   if (ch == 'C') return 0;
   if (ch == 'M') return 1;
   if (ch == 'S') return 2;

   // wrong input proviced
   cerr << "Wrong input data provided for method hash(char).\n";
   return -1;
}

//------------------------------Constructor---------------------------------
/* Default constructor.
* @pre     None.
* @post    Constructor. Initializes the hashTable to nullptrs.
*/
InventoryMgr::InventoryMgr() {
   for (int i = 0; i < ARRAYSIZE; i++) {
      hashTable[i] = nullptr;
   }
}

//------------------------------Destructor----------------------------------
/* Destructor.
* @pre     None.
* @post    Deletes dynamic memory
*/
InventoryMgr::~InventoryMgr() {
   // cycle through createObj array and delete objects
   for (int i = 0; i < ARRAYSIZE; i++) {
      if (hashTable[i] != nullptr) {
         delete hashTable[i]; // delete the SearchTree objects
         hashTable[i] = nullptr;
      }
   }
}

//------------------------------loadInventory-------------------------------
/* Loads inventory with input from file.
* @pre     File formatted correctly.
*          Each line in file represents one type of item and quantity.
*          The first char in each line is the item type, only valid chars are
*          'M' for coin, 'C' for comic book and 'S' for sports card. All other
*          codes will be ignored.
*          Example Input:
*              M, 3, 2001, 65, Lincoln Cent
*              C, 1, 1938, Mint, Superman, DC 
*              S, 9, 1989, Near Mint, Ken Griffey Jr., Upper Deck
* @post    Loads the customerList sorted linked list with the give
*          customer file.
*/
void InventoryMgr::loadInventory(ifstream& infile) {
   // Read one line at a time, extract the first character of each line and
   // save as a char.  Convert the rest of the text into a string.
   // Pass the char and string to factoryObj to create the appropriate 
   // Hashable item. The factoryObj will return a pointer for each item, load
   // the pointer into the hashTable at the correct location.

   // Get the initial code for the item and verify it's correct
   while (infile.peek() != EOF) {
      string code;
      string quantity;
      string temp;

      getline(infile, code, ','); // get the first character
      infile.get(); // throw away space
      getline(infile, quantity, ','); // get quantity
      infile.get(); // throw away space

      getline(infile, temp, '\n'); // get the rest of the line

      // Check if the correct code is included and if it is then pass it to
      // the load helper that creates the objects and stores in inventory.
      if (hash(code[0]) != -1) {
         // hash method returns -1 if the code is invalid
         loadHelper(code[0], stoi(quantity), temp);
      }
   }

}

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
void InventoryMgr::loadHelper(char c, int count, string data) {
   int index = hash(c); // get index for hash table
   if (hashTable[index] == nullptr) {
      // First time loading into this index, create a SearchTree object.
      hashTable[index] = new SearchTree;

      // create the inventory object
      Hashable* ptr = factoryObj.createIt(c, data); 

      // load the object into the inventory
      hashTable[index]->insert(ptr, count);
   }
   else {
      // Already contains a SearchTree object, so just need to load it.
      // create the inventory object
      Hashable* ptr = factoryObj.createIt(c, data);

      // load the object into the inventory
      hashTable[index]->insert(ptr, count);
   }
}

//------------------------------buyItem-------------------------------------
/*
* @pre     Must be existing item in inventory.
* @post    Searches for the item and increments the count.
*          Returns true if sucessful.
*          Memory management: Passed pointer is deleted and set to nullptr.
*/
bool InventoryMgr::buyItem(const char code, Hashable* item) {
   // Check if a nullptr is passed.
   if (item != nullptr) {
      int index = hash(code); // get index for hash table
      if (index != -1) { // check for valid code
         // if hashTable has a nullptr it means that the inventory is empty
         if (hashTable[index] != nullptr) {
            return hashTable[index]->increaseCount(item);
            // Memory Management - SearchTree destroys the passed object and 
            // sets the pointer to item == nullptr;
         }
         else {
            // Item is not in inventory
            delete item;  // release memory
            item = nullptr;
            return false;
         }
      }
      else {
         // Invalid code, delete pointer and exit.
         delete item;  // release memory
         item = nullptr;
         return false;
      }
   }
   return false;
}

//------------------------------sellItem------------------------------------
/*
* @pre     Must be existing item in inventory.
* @post    Searches for the item and decreases the count. Count cannot be
*          lower than 0.
*          Returns true if sucessful.
*          Memory management: Passed pointer is deleted and set to nullptr.
*/
bool InventoryMgr::sellItem(const char code, Hashable* item) {
   // Check if a nullptr is passed.
   if (item != nullptr) {
      int index = hash(code); // get index for hash table
      if (index != -1) { // check for valid code
         // if hashTable has a nullptr it means that the inventory is empty
         if (hashTable[index] != nullptr) {
            return hashTable[index]->decreaseCount(item);
            // Memory Management - SearchTree destroys the passed object and 3
            // sets the pointer to item == nullptr;
         }
         else {
            // Item is not in inventory
            delete item;  // release memory
            item = nullptr;
            return false;
         }
      }
      else {
         // Invalid code, delete pointer and exit.
         delete item;  // release memory
         item = nullptr;
         return false;
      }
   }
   return false;
}

//------------------------------displayAll-----------------------------
/*
* @pre     None.
* @post    Displays the entire contents of the inventory, including the
*          number of each item in inventory.
*          Display order is Coins, Comics and Sports. All separted by
*          new lines.
*/
void InventoryMgr::displayAll() {
   
   // print out Coins.
   if (hashTable[hash('M')] != nullptr) {
      cout << "\nCoin Inventory: \n";
      cout << *hashTable[hash('M')]; // prints out in sorted order.
   }

   // print out Comic books.
   if (hashTable[hash('C')] != nullptr) {
      cout << "\nComic Book Inventory: \n";
      cout << *hashTable[hash('C')]; // prints out in sorted order.
   }

   // print out Sports Cards.
   if (hashTable[hash('S')] != nullptr) {
      cout << "\nSports Cards Inventory: \n";
      cout << *hashTable[hash('S')]; // prints out in sorted order.
   }
}


