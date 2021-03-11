/*
 * @file History.cpp
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

#include "History.h"

//------------------------------execute-------------------------------------
/* Executes a display command for the store inventory.
* @pre     None.
* @post    The data string is not required for this method and is ignored.
*          Displays customer in one line, next line it displays all
*          transactions for that customer, each transaction is separated
*          by a new line.  This is repeated for all customers in
*          alphabetical order.
*/
void History::execute(UserManager& userObj, InventoryMgr& invObj,
   string data) {
   // The data string should be empty and is ignored.
   // Display all customers and their transactions. Customers are in
   // alphabetical order.
   userObj.displayAll();
}
