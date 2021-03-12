/*
 * @file BranchOperations.cpp
 * Manager class that handles inventory and customer transactions for a store.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * BranchOperations Class:
 * This is the top level manager class. It instatiates a UserManager class
 * which handles all customer transactions and an InventoryMgr class which
 * handles all inventory operations.
*/

#include "BranchOperations.h"

//------------------------------hash----------------------------------------
/* Takes a char and returns the index number for the command array.
* @pre     Only capital chars and must be S, B, D, C, or H.
* @post    Converts the char into a hash number (index of array).
*          Returns -1 if wrong input is provided.
*/
int BranchOperations::hash(const char ch) const {
   // All codes are in capital letters, so use A = 65 to subtract from code 
   // letters to designate the appropriate index
   // Valid codes in use are B, C, D, H, S
   int index = int(ch - 'A');
   
   // check command array to see if this code is in use
   if (command[index] != nullptr) return index;

   // wrong input proviced
   cerr << "\nWrong input data provided for method hash(char).\n";
   return -1;

}

//------------------------------Constructor---------------------------------
/* Default constructor.
* @pre     None.
* @post    Initializes the createObj array with Collectible and Customer
*          objects.
* @param   const int ID
* @param   const string n
*/
BranchOperations::BranchOperations() {
   // Initialize createObj array.
   for (int i = 0; i < ARRAYSIZE; i++) {
      command[i] = nullptr;
   }

   // the following are commands in use
   command[int('B'-'A')] = new Buy;
   command[int('D'-'A')] = new Display;
   command[int('C'-'A')] = new CustomerDisplay;
   command[int('H'-'A')] = new History;
   command[int('S'-'A')] = new Sell;
}

//------------------------------Destructor----------------------------------
/* Destructor.
* @pre     None.
* @post    Deletes dynamic memory
*/
BranchOperations::~BranchOperations() {
   // Delete the dynamic memory of command array
   for (int i = 0; i < ARRAYSIZE; i++) {
      delete command[i]; // delete the objects
      command[i] = nullptr;
   }
}

//------------------------------loadCustomers-------------------------------
/* Loads customerList with input from file.
* @pre     File formatted correctly.
* @post    Loads the customerList sorted linked list with the give
*          customer file.
*/
void BranchOperations::loadCustomers(ifstream& infile) {
   // Pass the file to userMgr
   userMgr.loadCustomers(infile);
}

//------------------------------loadInventory-------------------------------
/* Loads inventory with input from file.
* @pre     File formatted correctly.
* @post    Loads the customerList sorted linked list with the give
*          customer file.
*/
void BranchOperations::loadInventory(ifstream& infile) {
   // Pass the file to inventoryMgr
   inventoryMgr.loadInventory(infile);
}


//------------------------------loadInventory-------------------------------
/* Executes transactions with input from file.
* @pre     File formatted correctly.
* @post    Loads the customerList sorted linked list with the give
*          customer file.
*/
void BranchOperations::loadTransactions(ifstream& infile) {
   // Read one line at a time, extract the first character of each line and
   // save as a char, this is the transaction command.
   // - S = sell, B = Buy, D = Display, C = CustomerDisplay, H = History.
   // Convert the rest of the text into a string.

   // Use the hash() method to get the correct index of the command array.
   // For each command array index use the appropriate command.
   // Example:  command[0]->Buy.execute() method and pass the string and
   //          inventoryMgr and userMgr objects

   while (infile.peek() != EOF) {
      int index; // for hash table.
      char code; // transaction code
      string objData;

      code = infile.get();
      index = hash(code);
      if (index != -1) { // correct code
         if (!(code == 'D' || code == 'H')) {
            infile.get(); // get rid of comma
            infile.get(); // get rid of space
            getline(infile, objData, '\n'); // get rest of data.
            // execute commands.
            command[index]->execute(userMgr, inventoryMgr, objData);
         }
         else {
            getline(infile, objData, '\n'); // get rest of data.
            // execute commands.
            command[index]->execute(userMgr, inventoryMgr, objData);
         }
      }
      else {
         cerr << "\nError, incorrect transaction code provided.\n";
         getline(infile, objData, '\n'); // get rest of data.
      }
   }


   
}



