/*
 * @file CreateSportsCard.cpp
 * Command class for creating a SportsCard object.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CreateSportsCard Class:
 * Takes a string that contains the combined data fields for the object.
 * Initializes the object and returns a pointer to it.
*/

#include "CreateSportsCard.h"

//------------------------------create--------------------------------------
/* Creates a SportsCard object.
* @pre     String must be in the correct format.
*          Format: Year(int), grade(string), player(string), and
*                  manufacturer(strint)
*                 - No leading spaces in the string
*                 - A single comma followed by a space in between
                    data strings.
*          Example string: "1989, Near Mint, Ken Griffey Jr., Upper Deck"
* @post    The string is processed and separated into the appropriate types
*          for initiazling the object.
*          Note, dynamic memory ownership is passed to the calling function.
*/
SportsCard* CreateSportsCard::create(string objData) const {
   stringstream s(objData); // create a string stream for parsing input.
   string temp; // used when parsing through the data
   int year;
   string grade;
   string player;
   string manufacturer;

   getline(s, temp, ','); // get year
   year = stoi(temp);
   s.get(); // throw away space
   getline(s, grade, ','); // get grade
   s.get(); // throw away space
   getline(s, player, ','); // get player
   s.get(); // throw away space
   getline(s, manufacturer); // get manufacturer
   
   return new SportsCard(year, player, manufacturer, grade);
}
