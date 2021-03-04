/*
 * @file Sell.h
 * Command class for executing sells.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Sell Command Class:
 * Executes a sell, this transfers an item from inventory to customer 
 * transaction.
*/
#pragma once
#include "Hashable.h"
#include "InventoryMgr.h"
#include "UserManager.h"
#include "FactoryHashable.h"
#include <string>

using namespace std;

class Sell : public Transaction
{
private:

   FactoryHashable factoryObj; // Helper for creating objects.

public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   ~Sell();

   //------------------------------execute-------------------------------------
   /* Executes a sell command.
   * @pre     String must be in the correct format. Item order in the string
   *          customerID, item type, and the rest of the fields vary according
   *          to item type.
   *          Example string: "001, S, 1989, Near Mint, Ken Griffey Jr., 
                               Upper Deck"
   * @post    Executes a sell command which removes an item from store
   *          inventory and adds a customer transaction.
   */
   void execute(UserManager& userObj, InventoryMgr& invObj,
      string data);
      // Can use ifstream to parse through the data, remove customer ID and 
      // store as an int, next remove the item type and store as a char. Remove
      // the comma and space after the item type and create a string with 
      // the rest of the text.

      // Use the factoryobj.createIt method and pass the item type and string
      // as parameters. Save the pointer of the new Hashable object it creates.
      
      // Use the built-in clone method of the Hashable object to create a clone
      
      // Pass one pointer to invObj.sellItem() method.
      // Pass the second pointer to userOjb.addTransaction() method.

};