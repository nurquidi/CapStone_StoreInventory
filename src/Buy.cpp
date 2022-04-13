/*
 * @file Buy.cpp
 * Command class for executing buys.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * ----------------------------------------------------------------------------
 * Buy Command Class:
 * Executes a buy, this adds an item to store inventory and adds a
 * customer transaction.
*/

#include "Buy.h"

//------------------------------execute-------------------------------------
/* Executes a buy command.
* @pre     String must be in the correct format. Item order in the string
*          customerID, item type, and the rest of the fields vary according
*          to item type.
*          Example string: "001, S, 1989, Near Mint, Ken Griffey Jr.,
                            Upper Deck"
* @post    Executes the a buy command which adds an item (count 1) to
*          store inventory and adds an item to the customer transaction.
*/
void Buy::execute(UserManager& userObj, InventoryMgr& invObj,
   string data) {
   // Can use ifstream to parse through the data, remove customer ID and 
   // store as an int, next remove the item type and store as a char. Remove
   // the comma and space after the item type and create a string with 
   // the rest of the text.

   // Use the factoryobj.createIt method and pass the item type and string
   // as parameters. Save the pointer of the new Hashable object it creates.

   // Use the built-in clone method of the Hashable object to create a clone

   // Pass one pointer to invObj.buyItem() method.
   // Pass the second pointer to userOjb.addTransaction() method.

   stringstream s(data); // create a string stream for parsing input.
   string temp; // used when parsing through the data
   int custID;
   char code;
   string objData;

   getline(s, temp, ','); // get customer ID
   custID = stoi(temp);
   s.get(); // throw away space
   getline(s, temp, ','); // get object code
   code = temp[0];
   s.get(); // throw away space
   getline(s, objData); // get rest of data.

   // create transaction object
   Hashable* transactionPtr = factoryObj.createIt(code, objData);
   if (transactionPtr != nullptr) {
      // Object creation was successful

      // check if customer exists
      if (userObj.isCustomer(custID)) {
         Hashable* transactionPtr2 = transactionPtr->clone(); //create clone
         // perform inventory transaction
         bool bought = invObj.buyItem(code, transactionPtr);
         if (bought) { // inventory transaction success!

            // perform sell transaction for user inventory
            userObj.addTransaction(custID, "Sell", transactionPtr2);
         }
         else {
            cerr << "\nError, not enough inventory to cover transaction.\n";
            delete transactionPtr2; // release memory
            transactionPtr2 = nullptr;
         }
      }
      else {
         cerr << "\nError, customer is not on file.\n";
         delete transactionPtr; // release memory
         transactionPtr = nullptr;
      }
   }
}
