/*
 * @file Buy.h
 * Command class for executing buys.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * ----------------------------------------------------------------------------
 * Buy Command Class:
 * Executes a buy, this adds an item to store inventory and adds a 
 * customer transaction.
*/
#pragma once
#include "Hashable.h"
#include "Transaction.h"
#include "InventoryMgr.h"
#include "UserManager.h"
#include "FactoryHashable.h"
#include <string>

using namespace std;

class Buy : public Transaction
{
private:

   FactoryHashable factoryObj; // Helper for creating objects.

public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   ~Buy() {};

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
   void execute(UserManager& userObj, InventoryMgr& invObj,
      string data);

};
