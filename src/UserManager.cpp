/*
 * @file UserManager.cpp
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

#include "UserManager.h"

//------------------------------Constructor---------------------------------
/* Default constructor.
* @pre     None.
* @post    Constructor. Initializes the hashTable to nullptrs.
*/
UserManager::UserManager() {
   for (int i = 0; i < hashTableSize; i++) {
      hashTable[i] = nullptr;
   }
}

//------------------------------Destructor----------------------------------
/* Destructor.
* @pre     None.
* @post    Deletes dynamic memory
*/
UserManager::~UserManager() {
   for (int i = 0; i < hashTableSize; i++) {
      delete hashTable[i];
      hashTable[i] = nullptr;
   }
}


//------------------------------loadCustomers-------------------------------
/* Loads customerList with input from file.
* @pre     File formatted correctly.
*          Each line in the file represents a customer.
*          Example format for one line: "999, Pele"
*          -- 999 is the customer ID. Customer ID must be between 0 and 999.
*          -- Pele is the customer name.
* @post    Loads the customerList in sorted order with the customer file.
*/
void UserManager::loadCustomers(ifstream& infile) {
   // Read one line at a time, convert the line into a string.
   // Pass the string and ch 'A' to factoryObj to create a customer object.
   // The factoryObj will return a pointer for each item, load the customer 
   // object into customerList.

   while (infile.peek() != EOF) {
      string customer;
      getline(infile, customer); // Full line is needed to pass to factory.

      stringstream s(customer);
      string ID;  // to check that ID is within bounds 0 to 999
      getline(s, ID, ','); // get customer ID, needed for hashTable
      int numID = stoi(ID);

      if (numID >= 0 && numID < 1000) { // check for valid ID range.

         Hashable* temp = factoryObj.createIt('A', customer); // A = customer
         // Load into SearchTree
         customerList.insert(temp);

         // Initialize transaction list for customer
         hashTable[numID] = new TransactionList(customer);
      }
      else {
         cerr << "Error, customer ID is out of range.\n";
      }
   }
}

//------------------------------addTransaction------------------------------
/* Everytime a customer buys or sells the transaction is recorded.
* @pre     Customer must be an existing customer.
* @post    Loads the transaction into the hashTable array at the approriate
*          customer location. Transaction = "Buy" or "Sell".
*/
void UserManager::addTransaction(const int custID, string transaction, 
                                 Hashable* item) {
   // Use the hashcode (custID) to load the item at the correct index of the
   // hashTable.  If nullptr at this location then append a 
   // new TransactionList and load the new item.

   if (custID >= 0 && custID < 1000) { // check for valid range
      if (hashTable[custID] != nullptr) {
         // load to existing list.
         hashTable[custID]->add(transaction, item);
      }
      else {
         cerr << "Error, customer is not on file.\n";
         delete item; // release memory to avoid leaks.
         item = nullptr;
      }
   }
   else {
      cerr << "Error, customer is not on file.\n";
      delete item; // release memory to avoid leaks.
      item = nullptr;
   }
}

//------------------------------displayCustomer-----------------------------
/*
* @pre     Customer must be an existing customer.
* @post    Displays transaction history of the customer in chronological
*          order.
*/
void UserManager::displayCustomer(const int custID) {
   // Use the customer toString() method to output customer information.   
   // New line, use the print() method of the TransactionList to output 
   // contents.
   if (custID >= 0 && custID < 1000) { // check for valid range
      if (hashTable[custID] != nullptr) {
         hashTable[custID]->print();
      }
   }
}

//------------------------------displayAll-----------------------------
/*
* @pre     None.
* @post    Displays customer in one line, next line it displays all
*          transactions for that customer, each transaction is separated
*          by a new line.  This is repeated for all customers in
*          alphabetical order.
*/
void UserManager::displayAll() {
   vector<Hashable*> temp;  // temporary storage
   temp = customerList.sortedItems(); // returns sorted customers.
   for (Hashable* v : temp) {
      // Use dynamic casting to cast down to Customer, check for nullptr.
      const Customer* custmr = dynamic_cast<const Customer*>(v);
      if (custmr == nullptr) {
         cerr << "Object is not a Customer object" << endl;
      }
      else {
         int custID = custmr->getID();
         if (custID >= 0 && custID < 1000) { // check for valid range
            if (hashTable[custID] != nullptr) {
               hashTable[custID]->print();
            }
         }
      }
   }
}


