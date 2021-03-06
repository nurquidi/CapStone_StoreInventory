/*
 * @file CreateCustomer.h
 * Command class for creating a Customer object.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CreateCustomer Class:
 * Takes a string that contains the combined data fields for the object.
 * Initializes the object and returns a pointer to it.
*/

#pragma once
#include "CreateObject.h"
#include "Customer.h"
#include <string>
#include <sstream>

using namespace std;

class CreateCustomer : public CreateObject
{
public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    No dynamic data is owned in this class.
   */
   ~CreateCustomer() {};

   //------------------------------create--------------------------------------
   /* Creates a ComicBook object.
   * @pre     String must be in the correct format.
   *          Format: customerID(int), name(string).
   *                 - No leading spaces in the string
   *                 - A single comma followed by a space in between
                       data strings.
   *          Example string: "999, Pele"
   * @post    The string is processed and separated into the appropriate types
   *          for initiazling the object.
   *          Note, dynamic memory ownership is passed to the calling function.
   */
   Customer* create(string objData) const;
};
