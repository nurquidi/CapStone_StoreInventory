/*
 * @file UserManager.h
 * Manager class that handles customer transactions and stores a transaction
 * list.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * UserManager Class:
 * Three data structures are used in this class.
 * - Hashtable that stores customers transaction list for fast access.
 * - An unsorted linked list for storing customer transactions in chronological
 *   order.
 * - A sorted list that keepds a list of customers in alphabetical order.
*/

#pragma once
#include "Hashable.h"
#include "SearchTree.h"
#include "FactoryHashable.h"
#include "TransactionList.h"
#include <string>
#include <fstream>

using namespace std;

class UserManager
{
private:
   FactoryHashable factoryObj;  // Factory class for creating Hashable objects.
   SearchTree customerList;     // Sorted linked list for customers, sorts 
                                // in alphabetical order.
   static const int hashTableSize = 1000;
   TransactionList* hashTable[hashTableSize]; // Maximum of 999 customers.
   // Customer objects have a hash code that is equal to the customer ID.
   // this hash code is used as the index to the hashTable array.

public:
   //------------------------------Constructor---------------------------------
   /* Default constructor.
   * @pre     None.
   * @post    Constructor. Initializes the hashTable to nullptrs.
   */
   UserManager();
   

   //------------------------------Destructor----------------------------------
   /* Destructor.
   * @pre     None.
   * @post    Deletes dynamic memory
   */
   ~UserManager();

   //------------------------------loadCustomers-------------------------------
   /* Loads customerList with input from file.
   * @pre     File formatted correctly.
   *          Each line in the file represents a customer.
   *          Example format for one line: "999, Pele"
   *          -- 999 is the customer ID. Customer ID must be between 0 and 999.
   *          -- Pele is the customer name.
   * @post    Loads the customerList in sorted order with the customer file.
   */
   void loadCustomers(ifstream& infile);

   //------------------------------addTransaction------------------------------
   /* Everytime a customer buys or sells the transaction is recorded.
   * @pre     Customer must be an existing customer.
   * @post    Loads the transaction into the hashTable array at the approriate
   *          customer location.  Transaction = "Buy" or "Sell".
   */
   void addTransaction(const int custID, string transaction, Hashable* item);

   //------------------------------displayCustomer-----------------------------
   /*
   * @pre     Customer must be an existing customer.
   * @post    Displays transaction history of the customer in chronological 
   *          order.
   */
   void displayCustomer(const int custID);
   // Use the customer toString() method to output customer information.   
   // New line, use the print() method of the TransactionList to output 
   // contents.

   //------------------------------displayAll-----------------------------
   /*
   * @pre     None.
   * @post    Displays customer in one line, next line it displays all 
   *          transactions for that customer, each transaction is separated
   *          by a new line.  This is repeated for all customers in 
   *          alphabetical order.
   */
   void displayAll();
};
