/*
 * @file History.h
 * Command class for executing History.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CustomerDisplay Command Class:
 * Executes a History command.
 * Displays customer in one line, next line it displays all transactions for
 * that customer, each transaction is separated by a new line.  This is 
 * repeated for all customers in alphabetical order.
*/

#pragma once
#include "Hashable.h"
#include "InventoryMgr.h"
#include "UserManager.h"
#include <string>

using namespace std;

class History : public Transaction
{
public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   ~History();

   //------------------------------execute-------------------------------------
   /* Executes a display command for the store inventory.
   * @pre     None.
   * @post    The data string is not required for this method and is ignored.
   *          Displays customer in one line, next line it displays all 
   *          transactions for that customer, each transaction is separated
   *          by a new line.  This is repeated for all customers in 
   *          alphabetical order.
   */
   void execute(UserManager& userObj, InventoryMgr& invObj,
      string data);
      // The data string should be empty and is ignored.
      // Use the userObj.displayAll method.

};

