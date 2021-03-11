/*
 * @file Display.cpp
 * Command class for executing Display.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Display Command Class:
 * Executes a diplay command.
 * Displays the entire contents of the inventory, including the
 * number of each item in inventory. Display order is Coins, Comics and Sports.
 * All separted by new lines.
*/

#include "Display.h"


//------------------------------execute-------------------------------------
/* Executes a display command for the store inventory.
* @pre     None.
* @post    The data string is not required for this method and is ignored.
*          Displays the entire contents of the inventory, including the
*          number of each item in inventory. Display order is Coins, Comics
*          and Sports. All separted by new lines.
*/
void Display::execute(UserManager& userObj, InventoryMgr& invObj,
   string data) {

   invObj.displayAll();  // Display all items in inventory.

}
