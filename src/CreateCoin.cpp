/*
 * @file CreateSportsCard.cpp
 * Command class for creating a Coin object.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CreateCoin Class:
 * Takes a string that contains the combined data fields for the object.
 * Initializes the object and returns a pointer to it.
*/

#include "CreateCoin.h"

//------------------------------create--------------------------------------
/* Creates a Coin object.
* @pre     String must be in the correct format.
*          Format: Year(int), grade(int), type(string)
*                 - No leading spaces in the string
*                 - A single comma followed by a space in between
                    data strings.
*          Example string: "2001, 65, Lincoln Cent"
* @post    The string is processed and separated into the appropriate types
*          for initiazling the object.
*          Note, dynamic memory ownership is passed to the calling function.
*/
Coin* CreateCoin::create(string objData) const {
   stringstream s(objData); // create a string stream for parsing input.
   string temp; // used when parsing through the data
   int year;
   int grade;
   string type;

   getline(s, temp, ','); // get year
   year = stoi(temp);
   s.get(); // throw away space
   getline(s, temp, ','); // get grade
   grade = stoi(temp);
   s.get(); // throw away space
   getline(s, type); // get type

   return new Coin(year, type, grade);
}