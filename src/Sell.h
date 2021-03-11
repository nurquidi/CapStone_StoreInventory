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
#include "Transaction.h"
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
   ~Sell() {};

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

};