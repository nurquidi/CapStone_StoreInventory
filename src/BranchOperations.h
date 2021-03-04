/*
 * @file BranchOperations.h
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

#pragma once
#include "Hashable.h"
#include "InventoryMgr.h"
#include "UserManager.h"
#include "Transaction.h"
#include "Display.h"
#include "Sell.h"
#include "Buy.h"
#include "CustomerDisplay.h"
#include "History.h"
#include <string>
#include <fstream>

using namespace std;

class BranchOperations
{
private:
   
   UserManager userMgr; // Object to manage all customer transactions.
   InventoryMgr inventoryMgr; // Object to manage all inventory transactions.
   Transaction* command[4];  // Hash table for executing commands

   //------------------------------hash----------------------------------------
   /* Takes a char and returns the index number for the command array.
   * @pre     Only capital chars and must be S, B, D, C, or H.
   * @post    Converts the char into a hash number (index of array).
   */
   int hash(const char ch) const;
      // create a hash function that will result in B = 0, D = 1, C = 2, H = 3
      // S = 3.

public:

   //------------------------------Constructor---------------------------------
   /* Default constructor.
   * @pre     None.
   * @post    Initializes the createObj array with Collectible and Customer
   *          objects.
   * @param   const int ID
   * @param   const string n
   */
   BranchOperations();
   // Initialize createObj array.
   // command[0] = new Buy;
   // command[1] = new Display;
   // command[2] = new CustomerDisplay;
   // command[3] = new Sell;

   //------------------------------Destructor----------------------------------
   /* Destructor.
   * @pre     None.
   * @post    Deletes dynamic memory
   */
   ~BranchOperations();
   // Delete the dynamic memory of command array

   //------------------------------loadCustomers-------------------------------
   /* Loads customerList with input from file.
   * @pre     File formatted correctly.
   * @post    Loads the customerList sorted linked list with the give
   *          customer file.
   */
   void loadCustomers(ifstream& infile);
      // Pass the file to userMgr.loadCustomers

   //------------------------------loadInventory-------------------------------
   /* Loads inventory with input from file.
   * @pre     File formatted correctly.
   * @post    Loads the customerList sorted linked list with the give
   *          customer file.
   */
   void loadInventory(ifstream& infile);
   // Pass the file to inventoryMgr.loadInventory method.

   //------------------------------loadInventory-------------------------------
   /* Executes transactions with input from file.
   * @pre     File formatted correctly.
   * @post    Loads the customerList sorted linked list with the give
   *          customer file.
   */
   void loadTransactions(ifstream& infile);
      // Read one line at a time, extract the first character of each line and
      // save as a char, this is the transaction command.
      // - S = sell, B = Buy, D = Display, C = CustomerDisplay, H = History.
      // Convert the rest of the text into a string.
      
      // Use the hash() method to get the correct index of the command array.
      // For each command array index use the appropriate command.
      // Example:  command[0]->Buy.execute() method and pass the string and
      //          inventoryMgr and userMgr objects
};
