/*
 * @file CreateCustomer.cpp
 * Command class for creating a Customer object.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CreateCustomer Class:
 * Takes a string that contains the combined data fields for the object.
 * Initializes the object and returns a pointer to it.
*/

#include "CreateCustomer.h"

//------------------------------create--------------------------------------
/* Creates a ComicBook object.
* @pre     String must be in the correct format.
*          Customer ID must be between 0 and 999.
*          Format: customerID(int), name(string).
*                 - No leading spaces in the string
*                 - A single comma followed by a space in between
                    data strings.
*          Example string: "999, Pele"
* @post    The string is processed and separated into the appropriate types
*          for initiazling the object.
*          Note, dynamic memory ownership is passed to the calling function.
*/
Customer* CreateCustomer::create(string objData) const {
   stringstream s(objData); // create a string stream for parsing input.
   string temp; // used when parsing through the data
   int id;
   string name;

   getline(s, temp, ','); // get id
   id = stoi(temp);
   s.get(); // throw away space
   getline(s, name); // get name

   return new Customer(id, name);
}