/*
 * @file CustomerDisplay.cpp
 * Command class for executing Display.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CustomerDisplay Command Class:
 * Executes a customerDisplay command.
 * Displays transaction history of the customer in chronological order.
*/

#include "CustomerDisplay.h"

//------------------------------execute-------------------------------------
/* Executes a display command for user transactions.
* @pre     Customer must be an existing customer. The data string should
*          contain a valid 3 digit customer ID. Customer ID must be between
*          0 and 999.
* @post    Displays transaction history of the customer in chronological
*          order.
*/
void CustomerDisplay::execute(UserManager& userObj, InventoryMgr& invObj,
   string data) {
   // display transactions for the given customer.
   userObj.displayCustomer(stoi(data)); 
}