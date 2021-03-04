/*
 * @file CustomerDisplay.h
 * Command class for executing Display.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CustomerDisplay Command Class:
 * Executes a customerDisplay command.
 * Displays transaction history of the customer in chronological order.
*/
#pragma once
#include "Hashable.h"
#include "InventoryMgr.h"
#include "UserManager.h"
#include <string>

using namespace std;

class CustomerDisplay : public Transaction
{
public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   ~CustomerDisplay();

   //------------------------------execute-------------------------------------
   /* Executes a display command for the store inventory.
   * @pre     Customer must be an existing customer. The data string should
   *          contain a valid 3 digit customer ID.
   * @post    Displays transaction history of the customer in chronological 
   *          order.
   */
   void execute(UserManager& userObj, InventoryMgr& invObj,
      string data);
   // Convert the string to an int.
   // Use the userObj.displayCustomer() to display all the inventory contents.

};
