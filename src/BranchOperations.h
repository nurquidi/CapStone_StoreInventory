/*
 * @file BranchOperations.h
 * Manager class that handles inventory and customer transactions for a store.
 * @author Nestor Urquidi
 * @date 02/22/2021
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
   static const int ARRAYSIZE = 26;
   Transaction* command[ARRAYSIZE];  // Hash table for executing commands

   //------------------------------hash----------------------------------------
   /* Takes a char and returns the index number for the command array.
   * @pre     Only capital chars and must be S, B, D, C, or H.
   * @post    Converts the char into a hash number (index of array).
   *          Returns -1 if wrong input is provided.
   */
   int hash(const char ch) const;

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

   //------------------------------Destructor----------------------------------
   /* Destructor.
   * @pre     None.
   * @post    Deletes dynamic memory
   */
   ~BranchOperations();

   //------------------------------loadCustomers-------------------------------
   /* Loads customerList with input from file.
   * @pre     File formatted correctly.
   * @post    Loads the customerList sorted linked list with the give
   *          customer file.
   */
   void loadCustomers(ifstream& infile);

   //------------------------------loadInventory-------------------------------
   /* Loads inventory with input from file.
   * @pre     File formatted correctly.
   * @post    Loads the customerList sorted linked list with the give
   *          customer file.
   */
   void loadInventory(ifstream& infile);

   //------------------------------loadInventory-------------------------------
   /* Executes transactions with input from file.
   * @pre     File formatted correctly.
   * @post    Loads the customerList sorted linked list with the give
   *          customer file.
   */
   void loadTransactions(ifstream& infile);
};
