/*
 * @file Transaction.h
 * Interface class for executing commands. All derived classes will need to
 * implement the pure virtual method.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Transaction Interface Class:
 * A command interface class for executing commands.
*/
#pragma once
#include "Hashable.h"
#include "InventoryMgr.h"
#include "UserManager.h"
#include <string>

using namespace std;

class Transaction
{
public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   virtual ~Transaction() = 0;

   //------------------------------execute--------------------------------------
   /* Executes a command.
   * @pre     String must be in the correct format.
   * @post    Executes the command stored in the string on the given object.
   */
   virtual void execute(UserManager& userObj, InventoryMgr& invObj, 
                        string data) = 0;

};
