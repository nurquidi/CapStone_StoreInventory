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
   // create a hash function that will result in B = 0, D = 1, C = 2, H = 3
   // S = 4.
   if (ch == 'B') return 0;
   if (ch == 'D') return 1;
   if (ch == 'C') return 2;
   if (ch == 'H') return 3;
   if (ch == 'S') return 4;

   // wrong input proviced
   cerr << "Wrong input data provided for method hash(char).\n";
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
    command[0] = new Buy;
    command[1] = new Display;
    command[2] = new CustomerDisplay;
    command[3] = new History;
    command[4] = new Sell;
}

//------------------------------Destructor----------------------------------
/* Destructor.
* @pre     None.
* @post    Deletes dynamic memory
*/
BranchOperations::~BranchOperations() {
   // Delete the dynamic memory of command array
   for (int i = 0; i < ARRAYSIZE; i++) {
      delete command[i]; // delete the SearchTree objects
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
         }
         // execute commands.
         command[index]->execute(userMgr, inventoryMgr, objData);
      }
      else {
         cerr << "Error, incorrect transaction code provide.\n";
      }
   }


   
}



